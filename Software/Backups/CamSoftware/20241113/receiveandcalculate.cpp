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

using namespace std;

#define MAX_BUFFER_SIZE 1024
#define ARRAY_SIZE 9
#define PORT 8080
#define IMAGE_PORT 8081

// Constants and configuration
const double MIN_QUALITY_DISTANCE = 500;  // Minimum distance (in meters) for a quality picture
const double MAX_TIME_BETWEEN_PICTURES = 1;  // Maximum time between taking pictures in seconds
const double ERROR_MARGIN = 0.05;  // 5% margin for straight-line motion
const double CAMERA_LATITUDE = 0;  // Camera's latitude
const double CAMERA_LONGITUDE = 0;  // Camera's longitude
const double CAMERA_ALTITUDE = 5;  // Camera's altitude
const int MOTOR_1_PIN = 18;  // BCM GPIO 18, which supports hardware PWM on Raspberry Pi
const int MOTOR_2_PIN = 19;  // BCM GPIO 19, which supports hardware PWM on Raspberry Pi
const float pulseWidthMs = 2.5; //Determined by the camera motors

// Data structure for holding RID data
struct RIDData {
    signed int latitude;
    signed int longitude;
    unsigned int altitude;
    unsigned int speed;
    unsigned int direction;
    unsigned int timestamp;
    signed int cs_latitude;
    signed int cs_longitude;
    bool highPriorityArea;
};

// Global variables
RIDData ridData;  // Where the newly obtained RID data is temporarily stored
vector<RIDData> RID_data;  // Holds up to 3 RID data points
time_t pic_timestamp;  // Holds the timestamp of the last picture
bool take_picture = false;  // Should we take a picture?
bool picture_subject = false;  // True if UAS should be the focus, False for control station
bool slm = false;  // Straight Line Motion flag
bool can_send = false;  // Can send data to database
bool can_receive = false;  // Can receive data from database
bool camera_status = false;  // Camera system status
bool new_angles = false;  // New angles set flag
bool new_data = false;  // New data flag
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
        std::cerr << "Socket creation failed" << std::endl;
        return;
    }

    // Allow the socket to be reused (important when binding repeatedly)
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        std::cerr << "Setsockopt failed" << std::endl;
        close(server_fd);
        return;
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Bind to all interfaces
    server_addr.sin_port = htons(PORT);        // Port to listen on

    // Bind server socket to address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        close(server_fd);
        return;
    }

    // Listen for incoming connections
    if (listen(server_fd, 1) < 0) {
        std::cerr << "Listen failed" << std::endl;
        close(server_fd);
        return;
    }

    std::cout << "Server listening on port " << PORT << "..." << std::endl;

    // Accept client connection
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) {
        std::cerr << "Accept failed" << std::endl;
        close(server_fd);
        return;
    }

    std::cout << "Connection established with client!" << std::endl;

    // Receive the DataPacket struct
    ssize_t bytes_received = read(client_fd, &ridData, sizeof(ridData));
    if (bytes_received < 0) {
        std::cerr << "Read failed" << std::endl;
    } else if (bytes_received != sizeof(ridData)) {
        std::cerr << "Incomplete data received. Expected " << sizeof(ridData) << " bytes, but got " << bytes_received << " bytes." << std::endl;
    }

    std::cout << "Data has been read" << std::endl;

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

// Calculate camera angles based on UAS or control station location
void determine_angles() {
    //if (!take_picture || !slm || !new_angles) {
    //    return;
    //}

    // Calculate horizontal angle (theta_h)
    double x = RID_data.back().longitude - CAMERA_LONGITUDE;
    double y = RID_data.back().latitude - CAMERA_LATITUDE;
    theta_h = atan2(y, x) * (180 / M_PI);
   
    // Calculate vertical angle (theta_v)
    double z = RID_data.back().altitude - CAMERA_ALTITUDE;
    double l = sqrt(x * x + y * y);
    theta_v = atan2(z, l) * (180 / M_PI);

}

//Generates the square wave
void generateSquareWave(double dutyCycle, int PWM_PIN) {
    int frequency = 1000 / 2.5;
    int dutyCycleScaled = static_cast<int>(dutyCycle * 10000); // Scale from 0 to 1,000,000

    int result = gpioHardwarePWM(PWM_PIN, frequency, dutyCycleScaled);

    if (result != 0) {
        std::cerr << "Failed to set PWM!" << std::endl;
        gpioTerminate();
        return;
    }
}

// Move the camera to the calculated angles
void move_camera() {
    int dutyCycleM1 = 0;
    int dutyCycleM2 = 0;

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

    if (theta_h < 270 || theta_h >= 0){
        dutyCycleM1 = (theta_h + 50.546)/3.3332;
    }
    if (theta_v < 180 || theta_v >= 0){
        dutyCycleM2 = (theta_v + 34.615)/2.3077;
        
    }


    if (dutyCycleM1 < 10 || dutyCycleM1 > 100) {
        cerr << "Duty cycle 1 not between 0 and 100." << endl;
    }
    else if (dutyCycleM2 < 10 || dutyCycleM1 > 100) {
        cerr << "Duty cycle 2 not between 0 and 100." << endl;
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

//Connect to the database and send an image
void send_image() {
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    // Open the image file in binary mode
    std::ifstream infile("cat.jpg", std::ios::binary);
    if (!infile.is_open()) {
        std::cerr << "Failed to open image file!" << std::endl;
        return;
    }

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

    std::cout << "Connected to receiver!" << std::endl;

    // Read and send the image file in chunks
    while (infile.read(buffer, MAX_BUFFER_SIZE)) {
        send(client_fd, buffer, infile.gcount(), 0);
    }

    // Send any remaining bytes in the last chunk
    if (infile.gcount() > 0) {
        send(client_fd, buffer, infile.gcount(), 0);
    }

    std::cout << "Image sent successfully!" << std::endl;

    // Close the file and socket
    infile.close();
    close(client_fd);

}


int main() {
    
    while (1) {
            receive_data();
            store_data(ridData);

             std::cout << "\nAll Stored RID Data: " << std::endl;
                for (const auto& data : RID_data) {
                    std::cout << "Latitude: " << data.latitude << ", "
                      << "Longitude: " << data.longitude << ", "
                      << "Altitude: " << data.altitude << ", "
                      << "Speed: " << data.speed << ", "
                      << "Direction: " << data.direction << ", "
                      << "Timestamp: " << data.timestamp << ", "
                      << "CS Latitude: " << data.cs_latitude << ", "
                      << "CS Longitude: " << data.cs_longitude << ", "
                      << "High Priority Area: " << (data.highPriorityArea ? "Yes" : "No") << std::endl;
                }

            determine_angles ();
             std::cout << "\nPointing Angles: " << theta_h << " degrees" << ", " << theta_v << " degrees" << std::endl;

            move_camera();

            send_image();
        }    
}
