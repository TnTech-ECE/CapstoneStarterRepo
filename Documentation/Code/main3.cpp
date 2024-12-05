#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cmath>
#include <vector>
#include <ctime>
#include <pigpio.h>
#include <thread>
#include <chrono>
#include <sstream>
#include <memory>
#include <string>
#include <chrono>
#include <libcamera/libcamera.h>
#include <libcamera/camera_manager.h>
#include <libcamera/camera.h>
#include <libcamera/framebuffer_allocator.h>
#include <libcamera/request.h>

#include <unistd.h>

using namespace libcamera;

using namespace std;

#define MAX_BUFFER_SIZE 1024
#define ARRAY_SIZE 9
#define PORT 10010
#define IMAGE_PORT 9090

// Constants and configuration
const double MIN_QUALITY_DISTANCE = 500;  // Minimum distance (in meters) for a quality picture
const double MAX_TIME_BETWEEN_PICTURES = 1;  // Maximum time between taking pictures in seconds
const double ERROR_MARGIN = 0.05;  // 5% margin for straight-line motion
const double CAMERA_LATITUDE = 0;  // Camera's latitude
const double CAMERA_LONGITUDE = 0;  // Camera's longitude
const double CAMERA_ALTITUDE = 0;  // Camera's altitude
const int MOTOR_1_PIN = 18;  // BCM GPIO 18, which supports hardware PWM on Raspberry Pi
const int MOTOR_2_PIN = 19;  // BCM GPIO 19, which supports hardware PWM on Raspberry Pi
const float pulseWidthMs = 2.5; //Determined by the camera motors

int dutyCycleM1 = 0;
int dutyCycleM2 = 0;

bool neg = false;

// Data structure for holding RID data
struct RIDData {
    double latitude;
    double longitude;
    double altitude;
    float speed;
    // unsigned int direction;
    // unsigned int timestamp;
    double cs_latitude;
    double cs_longitude;
    double cs_altitude;
    bool highPriorityArea;
};

// Global variables
RIDData ridData;  // Where the newly obtained RID data is temporarily stored
vector<RIDData> RID_data;  // Holds up to 3 RID data points
time_t pic_timestamp;  // Holds the timestamp of the last picture
bool take_picture = false;  // Should we take a picture?
bool picture_subject = false;  // True if UAS should be the focus, False for control station
bool slm = false;  // Straight Line Motion flag
bool camera_status = false;  // Camera system status
bool camera_set = false;  // Camera is set to take a picture
double theta_h = 0.0, theta_v = 0.0;  // Horizontal and vertical angles



// Listen and receive from the database
void receive_data() {
    int server_fd;
    int client_fd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        cerr << "Socket creation failed" << endl;
        return;
    }

    // Allow the socket to be reused (important when binding repeatedly)
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        cerr << "Setsockopt failed" << endl;
        close(server_fd);
        return;
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Bind to all interfaces
    server_addr.sin_port = htons(PORT);        // Port to listen on

    // Bind server socket to address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        cerr << "Bind failed" << endl;
        close(server_fd);
        return;
    }

    // Listen for incoming connections
    if (listen(server_fd, 1) < 0) {
        cerr << "Listen failed" << endl;
        close(server_fd);
        return;
    }

    cout << "Server listening on port " << PORT << "..." << endl;

    // Accept client connection
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) {
        cerr << "Accept failed" << endl;
        close(server_fd);
        return;
    }

    cout << "Connection established with client!" << endl;

    // Receive the DataPacket struct
    ssize_t bytes_received = read(client_fd, &ridData, sizeof(ridData));
    if (bytes_received < 0) {
        cerr << "Read failed" << endl;
    } else if (bytes_received != sizeof(ridData)) {
        cerr << "Incomplete data received. Expected " << sizeof(ridData) << " bytes, but got " << bytes_received << " bytes." << endl;
    }

    cout << "Data has been read" << endl;

    // Close the client and server sockets after the data is received
    close(client_fd);
    close(server_fd);
}

// Store RID data in the global array
void store_data(RIDData rid_data) {
    if (RID_data.size() >= 3) {
        RID_data.erase(RID_data.begin());  // Remove the oldest data if we have 3 data points
    }
    RID_data.push_back(rid_data);
}

// Analyze data to determine if we should take a picture
void analyze_data() {
    
    // Determine if we focus on UAS or control station based on alert area
    bool high_priority_area = RID_data.back().highPriorityArea;
    
    if (high_priority_area) {
        picture_subject = true;  // Prioritize UAS
    } else {
        picture_subject = false;  // Prioritize control station
    }

    // Set flag to take a picture
    take_picture = true;
}

// Detect if the object is moving in a straight line
void determine_slm() {
    if (RID_data.size() < 3) {
        return;
    }

    RIDData p1 = RID_data[0], p2 = RID_data[1], p3 = RID_data[2];

    // Directional vectors
    double vector_p1_p2[3];
    double vector_p2_p3[3];

    if (picture_subject) {
        // Calculate directional vectors between points
        vector_p1_p2[0] = p1.latitude - p2.latitude;
        vector_p1_p2[1] = p1.longitude - p2.longitude;
        vector_p1_p2[2] = p1.altitude - p2.altitude;

        vector_p2_p3[0] = p2.latitude - p3.latitude;
        vector_p2_p3[1] = p2.longitude - p3.longitude;
        vector_p2_p3[2] = p2.altitude - p3.altitude;
    } else {
        // Calculate directional vectors between points
        vector_p1_p2[0] = p1.cs_latitude - p2.cs_latitude;
        vector_p1_p2[1] = p1.cs_longitude - p2.cs_longitude;
        vector_p1_p2[2] = p1.cs_altitude - p2.cs_altitude;

        vector_p2_p3[0] = p2.cs_latitude - p3.cs_latitude;
        vector_p2_p3[1] = p2.cs_longitude - p3.cs_longitude;
        vector_p2_p3[2] = p2.cs_altitude - p3.cs_altitude;
    }

    // Calculate magnitudes of the vectors
    double mag_p1_p2 = sqrt(vector_p1_p2[0] * vector_p1_p2[0] + 
                            vector_p1_p2[1] * vector_p1_p2[1] + 
                            vector_p1_p2[2] * vector_p1_p2[2]);
    double mag_p2_p3 = sqrt(vector_p2_p3[0] * vector_p2_p3[0] + 
                            vector_p2_p3[1] * vector_p2_p3[1] + 
                            vector_p2_p3[2] * vector_p2_p3[2]);

    // Check if the motion is straight (within a 5% error margin)
    for (int i = 0; i < 3; ++i) {
        double ratio = vector_p2_p3[i] / mag_p2_p3;
        double expected_ratio = vector_p1_p2[i] / mag_p1_p2;

        if (!(0.95 <= ratio / expected_ratio && ratio / expected_ratio <= 1.05)) {
            slm = false;
            return;
        }
    }

    slm = true;  // Straight-line motion detected
}

// Predict future location if moving in a straight line
void predict_location() {
    if (!slm) {
        return;
    }

    cout << "Straight line motion detected!" << endl;

    RIDData p2 = RID_data[1], p3 = RID_data[2];

    
    if (picture_subject) {
        // Speed variables
        double v2 = p2.speed > 0 ? p2.speed : 1.0; // Avoid division by zero
        double v3 = p3.speed > 0 ? p3.speed : 1.0; // Avoid division by zero

        // Predict future location
        double predicted_latitude = p3.latitude + (v3 / v2) * (p3.latitude - p2.latitude);
        double predicted_longitude = p3.longitude + (v3 / v2) * (p3.longitude - p2.longitude);
        double predicted_altitude = p3.altitude + (v3 / v2) * (p3.altitude - p2.altitude);

        // Update RID_data with predicted location
        RID_data[2] = {
            predicted_latitude,
            predicted_longitude,
            predicted_altitude,
            p3.speed,
            // p3.direction,
            // p3.timestamp,
            p3.cs_latitude,
            p3.cs_longitude,
            p3.cs_altitude,
            p3.highPriorityArea
        };
    } else {
        // Speed variables
        double v2 = 1.0; 
        double v3 = 1.0; 

        // Predict future location
        double predicted_latitude = p3.cs_latitude + (v3 / v2) * (p3.cs_latitude - p2.cs_latitude);
        double predicted_longitude = p3.cs_longitude + (v3 / v2) * (p3.cs_longitude - p2.cs_longitude);
        double predicted_altitude = p3.cs_altitude + (v3 / v2) * (p3.cs_altitude - p2.cs_altitude);

        // Update RID_data with predicted location
        RID_data[2] = {
            p3.latitude,
            p3.longitude,
            p3.altitude,
            p3.speed,
            // p3.direction,
            // p3.timestamp,
            predicted_latitude,
            predicted_longitude,
            predicted_altitude,
            p3.highPriorityArea
        };
    }
}

// Calculate camera angles based on UAS or control station location
void determine_angles() {
    if (!take_picture) {
        return;
    }

    if (picture_subject){
        // Calculate horizontal angle (theta_h)
        double x = RID_data.back().longitude - CAMERA_LONGITUDE;
        double y = RID_data.back().latitude - CAMERA_LATITUDE;
        theta_h = atan2(y, x) * (180 / M_PI);

        if (theta_h < 0){
            theta_h = theta_h + 360;
        }

        // Calculate vertical angle (theta_v)
        double z = RID_data.back().altitude - CAMERA_ALTITUDE;
        double l = sqrt(x * x + y * y);
        theta_v = atan2(z, l) * (180 / M_PI);

        if (theta_h > 270){
            theta_h = theta_h - 180;
            theta_v = 180 - theta_v;
        }
    } else {
        // Calculate horizontal angle (theta_h)
        double x = RID_data.back().cs_longitude - CAMERA_LONGITUDE;
        double y = RID_data.back().cs_latitude - CAMERA_LATITUDE;
        theta_h = atan2(y, x) * (180 / M_PI);

        if (theta_h < 0){
            theta_h = theta_h + 360;
        }
    
        // Calculate vertical angle (theta_v)
        double z = RID_data.back().cs_altitude - CAMERA_ALTITUDE;
        double l = sqrt(x * x + y * y);
        theta_v = atan2(z, l) * (180 / M_PI);

        if (theta_h > 270){
            theta_h = theta_h - 180;
            theta_v = 180 - theta_v;
        }
    }

}

// Generates the square wave
void generateSquareWave(double dutyCycle, int PWM_PIN) {
    int frequency = 1000 / 2.5;
    int dutyCycleScaled = static_cast<int>(dutyCycle * 10000); // Scale from 0 to 1,000,000

    int result = gpioHardwarePWM(PWM_PIN, frequency, dutyCycleScaled);

    if (result != 0) {
        cerr << "Failed to set PWM!" << endl;
        gpioTerminate();
        return;
    }
}

// Move the camera to the calculated angles
void move_camera() {

    //theta_v += 180; //assuming camera is set on its side REMOVE LATER DEPENDING ON SET UP

    // Initialize pigpio
    if (gpioInitialise() < 0) {
        cerr << "pigpio initialization failed!" << endl;
        return;
    }

    // Set the pins to output mode
    gpioSetMode(MOTOR_1_PIN, PI_OUTPUT);
    gpioSetMode(MOTOR_2_PIN, PI_OUTPUT);

    //Determining duty cycle value

    if (theta_h < 270 && theta_h > 0){
        dutyCycleM1 = (theta_h + 50.546)/3.3332;
    }
    if (theta_v < 180 && theta_v > 0){
        dutyCycleM2 = (theta_v + 34.615)/2.3077;
    }



    // Moving the camera hardware to the calculated angles
    cout << "Generated square wave on GPIO pin " << MOTOR_1_PIN 
         << " with pulse width " << pulseWidthMs << " ms and duty cycle " 
         << dutyCycleM1 << "%" << endl;
    generateSquareWave(dutyCycleM1, MOTOR_1_PIN);

    cout << "Generated square wave on GPIO pin " << MOTOR_2_PIN
         << " with pulse width " << pulseWidthMs << " ms and duty cycle " 
         << dutyCycleM2 << "%" << endl;
    generateSquareWave(dutyCycleM2, MOTOR_2_PIN);
    
    camera_set = true;  // Indicate camera is set to take a picture
}

// Start RPICam
void check_and_launch_rpicam() {
        // Initialize the camera manager
    shared_ptr<CameraManager> cameraManager = make_shared<CameraManager>();
    if (cameraManager->start()) {
        cerr << "Failed to start camera manager." << endl;
        return;
    }

    // Open the first available camera
    shared_ptr<Camera> camera = cameraManager->cameras()[0];
    if (!camera) {
        cerr << "No camera available." << endl;
        return;
    }

    if (camera->acquire()) {
        cerr << "Failed to acquire camera." << endl;
        return;
    }

    // Configure the camera
    unique_ptr<CameraConfiguration> config = camera->generateConfiguration({ StreamRole::StillCapture });
    if (!config || config->validate() != CameraConfiguration::Valid) {
        cerr << "Invalid camera configuration." << endl;
        return;
    }

    if (camera->configure(config.get())) {
        cerr << "Failed to configure the camera." << endl;
        return;
    }

    // Allocate frame buffers
    FrameBufferAllocator allocator(camera);
    for (StreamConfiguration &streamConfig : *config) {
        Stream *stream = streamConfig.stream();
        if (allocator.allocate(stream) < 0) {
            cerr << "Failed to allocate frame buffers." << endl;
            return;
        }
    }

    // Create a capture request
    unique_ptr<Request> request = camera->createRequest();
    if (!request) {
        cerr << "Failed to create capture request." << endl;
        return;
    }
}

// Takes the picture
void capture_image(int picture_counter) {
    // Form the picture filename with the new path and format
    string filename = "/home/tntech/Documents/C2/Pictures/Picture_" + to_string(picture_counter);

    // Command to capture an image using libcamera-still with original resolution and quality
    string command = "libcamera-still -o " + filename + " --width 4056 --height 3040 --quality 100 --nopreview --timeout 1";

    // Run the command to capture the image
    cout << "Taking picture and saving as: " << filename << endl;
    system(command.c_str()); // Execute the command
}

// Send the image 
void send_image(int picture_num) {
    string directory = "/home/tntech/Documents/C2/Pictures/"; // Directory for storing screenshots
    stringstream filename;
    filename << "Picture_" << picture_num ; // Match the naming
    string full_path = directory + filename.str();

    char buffer[MAX_BUFFER_SIZE];

    // Open the image file in binary mode
    ifstream infile(full_path, ios::binary);
    if (!infile.is_open()) {
        cerr << "Failed to open image file: " << full_path << endl;
        return;
    }

    int client_fd;
    struct sockaddr_in server_addr;

    // Create client socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("Socket creation failed");
        return;
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAGE_PORT);                  // Port to connect to
    server_addr.sin_addr.s_addr = inet_addr("10.104.130.17");  // Receiver's IP

    // Connect to the receiver
    if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(client_fd);
        return;
    }

    cout << "Connected to receiver!" << endl;

    // Read and send the image file in chunks
    while (infile.read(buffer, MAX_BUFFER_SIZE)) {
        send(client_fd, buffer, infile.gcount(), 0);
    }

    // Send any remaining bytes in the last chunk
    if (infile.gcount() > 0) {
        send(client_fd, buffer, infile.gcount(), 0);
    }

    cout << "Image sent successfully!" << endl;

    // Close the file and socket
    infile.close();
    close(client_fd);
}


//g++ -std=c++17 -I/usr/include/libcamera main2.cpp -o main2 -lcamera -lcamera-base -pthread -lpigpio


int main() {
    int picNum = 0;
    check_and_launch_rpicam();

    while (1) {

            receive_data();

            store_data(ridData);

             cout << "\nAll Stored RID Data: " << endl;
                for (const auto& data : RID_data) {
                    cout << "Latitude: " << data.latitude << ", "
                      << "Longitude: " << data.longitude << ", "
                      << "Altitude: " << data.altitude << ", "
                      << "Speed: " << data.speed << ", "
                      << "CS Latitude: " << data.cs_latitude << ", "
                      << "CS Longitude: " << data.cs_longitude << ", "
                      << "High Priority Area: " << (data.highPriorityArea ? "Yes" : "No") << endl;
                }

            analyze_data();

            determine_slm();

            predict_location();

            determine_angles();
             cout << "\nPointing Angles: " << theta_h << " degrees" << ", " << theta_v << " degrees" << endl;

            move_camera();

            capture_image(picNum);

            send_image(picNum);

            picNum++;
            
    }    
}
