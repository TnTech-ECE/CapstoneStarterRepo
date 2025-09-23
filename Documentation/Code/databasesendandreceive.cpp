#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstdlib>     // For rand() and srand()
#include <ctime>       // For time()

using namespace std;

#define PORT 8080
#define IMAGE_PORT 8081
#define MAX_BUFFER_SIZE 1024

struct DataPacket {
    signed int latitude;
    signed int longitude;
    unsigned int altitude;
    unsigned int speed;
    unsigned int direction;
    unsigned int timestamp;
    signed int cs_latitude;
    signed int cs_longitude;
    signed int cs_altitude;
    bool highpriorityArea;
};

// Function prototypes
bool sendDataPacket(const DataPacket &data, const string &ip_address, int port);
bool receiveImage(const string &filename, int port);
DataPacket generateRandomDataPacket();

int main() {
    srand(static_cast<unsigned>(time(0)));  // Seed random number generator

    while (true) {
        //Generate a random DataPacket each cycle
        DataPacket data = generateRandomDataPacket();
        //DataPacket data = {5, -5, 2, 0, 0, 0, 5, 5, 2, 0};

        if (!sendDataPacket(data, "10.104.134.37", PORT)) {
            cerr << "Failed to send data packet!" << endl;
            //break;
        }

        if (!receiveImage("received_cat.jpg", IMAGE_PORT)) {
            cerr << "Failed to receive image!" << endl;
            //break;
        }

        sleep(15);  // Wait for 1 second before next iteration
    }

    return 0; 
}

// Function to send data packet to the specified IP and port
bool sendDataPacket(const DataPacket &data, const string &ip_address, int port) {
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("Socket creation failed");
        return false;
    }

    sockaddr_in server_addr {};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address.c_str(), &server_addr.sin_addr);

    if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(client_fd);
        return false;
    }

    ssize_t bytes_sent = send(client_fd, &data, sizeof(data), 0);
    if (bytes_sent < 0) {
        perror("Send failed");
    } else {
        cout << "Sent struct with " << bytes_sent << " bytes successfully!" << endl;
    }

    close(client_fd);
    return bytes_sent >= 0;
}

// Function to receive an image file from a client connection on a specified port
bool receiveImage(const string &filename, int port) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        return false;
    }

    // Step 1: Enable SO_REUSEADDR to allow immediate reuse of the port
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("Setsockopt failed");
        close(server_fd);
        return false;
    }

    sockaddr_in server_addr {};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Step 3: Attempt to bind the port with retry mechanism
    int max_retries = 5;
    while (max_retries-- > 0) {
        if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            if (errno == EADDRINUSE) {
                cerr << "Port in use, retrying..." << endl;
                sleep(1); // Wait 1 second before retrying
                continue;
            } else {
                perror("Bind failed");
                close(server_fd);
                return false;
            }
        }
        break; // Exit loop if bind is successful
    }

    if (max_retries <= 0) {
        cerr << "Failed to bind after multiple retries!" << endl;
        close(server_fd);
        return false;
    }

    if (listen(server_fd, 1) < 0) {
        perror("Listen failed");
        close(server_fd);
        return false;
    }

    cout << "Server listening on port " << port << "..." << endl;

    sockaddr_in client_addr {};
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) {
        perror("Accept failed");
        close(server_fd);
        return false;
    }

    cout << "Connection established with image sender!" << endl;

    ofstream outfile(filename, ios::binary);
    if (!outfile.is_open()) {
        cerr << "Failed to open output file!" << endl;
        close(client_fd);
        close(server_fd);
        return false;
    }

    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = read(client_fd, buffer, MAX_BUFFER_SIZE)) > 0) {
        outfile.write(buffer, bytes_received);
    }

    if (bytes_received < 0) {
        perror("Read failed");
    } else {
        cout << "Image received and saved as '" << filename << "'!" << endl;
    }

    outfile.close();
    close(client_fd);
    close(server_fd);

    return bytes_received >= 0;
}

// Function to generate a random DataPacket
DataPacket generateRandomDataPacket() {
    DataPacket data;
    data.latitude = rand() % 18 - 9;          // Latitude range: -90 to +90 degrees
    data.longitude = rand() % 36 - 18;        // Longitude range: -180 to +180 degrees
    data.altitude = rand() % 100;                           // Altitude range: 0 to 100 meters
    data.speed = rand() % 1000;                             // Speed range: 0 to 1,000 m/s
    data.direction = rand() % 360;                          // Direction range: 0 to 359 degrees
    data.timestamp = static_cast<unsigned int>(time(0));    // Current timestamp
    data.cs_latitude = rand() % 180000000 - 90000000;       // Cross-station latitude
    data.cs_longitude = rand() % 360000000 - 180000000;     // Cross-station longitude
    data.cs_altitude = rand() % 100;                        // Control-station altitude
    data.highpriorityArea = rand() % 2;                     // Randomly assign true or false

    return data;
}
