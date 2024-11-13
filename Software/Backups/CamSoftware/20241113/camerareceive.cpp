#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define ARRAY_SIZE 9
#define PORT 8080

int main() {
    int server_fd;
    int client_fd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int32_t buffer[ARRAY_SIZE] = {0};  // Array to store 9 signed integers

    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Bind to all interfaces
    server_addr.sin_port = htons(PORT);        // Port to listen on

    // Bind server socket to address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 1) < 0) {
        perror("Listen failed");
        close(server_fd);
        return -1;
    }

    std::cout << "Server listening on port " << PORT << "..." << std::endl;

    // Accept client connection
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) {
        perror("Accept failed");
        close(server_fd);
        return -1;
    }

    std::cout << "Connection established with client!" << std::endl;

    // Receive exactly 9 signed integers (36 bytes for 9 int32_t)
    ssize_t bytes_received = read(client_fd, buffer, sizeof(buffer));
    if (bytes_received < 0) {
        perror("Read failed");
    } else if (bytes_received == sizeof(buffer)) {
        std::cout << "Received 9 signed integers: ";
        for (int i = 0; i < ARRAY_SIZE; i++) {
            std::cout << buffer[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cerr << "Incomplete data received. Expected " << sizeof(buffer) << " bytes, but got " << bytes_received << " bytes." << std::endl;
    }

    // Close the sockets
    close(client_fd);
    close(server_fd);

    return 0;
}
