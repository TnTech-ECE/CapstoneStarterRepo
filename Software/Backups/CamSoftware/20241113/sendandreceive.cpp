#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

#define MAX_BUFFER_SIZE 1024
#define ARRAY_SIZE 9
#define PORT 8080

// Constants and configuration
const double MIN_QUALITY_DISTANCE = 500;  // Minimum distance (in meters) for a quality picture
const double MAX_TIME_BETWEEN_PICTURES = 1;  // Maximum time between taking pictures in seconds
const double ERROR_MARGIN = 0.05;  // 5% margin for straight-line motion
const double CAMERA_LATITUDE = 36175188;  // Camera's latitude
const double CAMERA_LONGITUDE = -457234795;  // Camera's longitude
const double CAMERA_ALTITUDE = 50;  // Camera's altitude

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


// Function to receive data from database
void receive_data(int server_fd, int& client_fd) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Accept the connection from the client
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) {
        std::cerr << "Accept failed" << std::endl;
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
}

// Function to store RID data in the global array
void store_data(RIDData rid_data) {
    if (RID_data.size() >= 3) {
        RID_data.erase(RID_data.begin());  // Remove the oldest data if we have 3 data points
    }
    RID_data.push_back(rid_data);
    can_receive = false;  // Reset receive flag
}

// Function to send image back to database
void send_data(int client_fd) {
    std::ifstream infile("cat.jpg", std::ios::binary);
    if (!infile.is_open()) {
        std::cerr << "Failed to open image file!" << std::endl;
        return;
    }

    char buffer[MAX_BUFFER_SIZE];

    // Read and send the image file in chunks
    while (infile.read(buffer, MAX_BUFFER_SIZE)) {
        ssize_t bytes_sent = send(client_fd, buffer, infile.gcount(), 0);
        if (bytes_sent < 0) {
            std::cerr << "Send failed!" << std::endl;
            break;
        }
    }

    // Send any remaining bytes in the last chunk
    if (infile.gcount() > 0) {
        ssize_t bytes_sent = send(client_fd, buffer, infile.gcount(), 0);
        if (bytes_sent < 0) {
            std::cerr << "Send failed!" << std::endl;
        }
    }

    std::cout << "Image sent successfully!" << std::endl;

    // Close the file after sending
    infile.close();
}

// Main function
int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;

    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Bind to all interfaces
    server_addr.sin_port = htons(PORT);        // Port to listen on

    // Bind server socket to address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        close(server_fd);
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 1) < 0) {
        std::cerr << "Listen failed" << std::endl;
        close(server_fd);
        return -1;
    }

    std::cout << "Server listening on port " << PORT << "..." << std::endl;

    // Main loop (Your original loop structure)
    for (int i = 0; i < 5; ++i) {
        receive_data(server_fd, client_fd);  // Receive the struct data from Raspberry Pi A
        store_data(ridData);  // Store the received data

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

        send_data(client_fd);  // Send the image back to Database
    }

    // Close the client socket and server socket after all operations are done
    close(client_fd);
    close(server_fd);

    return 0;
}
