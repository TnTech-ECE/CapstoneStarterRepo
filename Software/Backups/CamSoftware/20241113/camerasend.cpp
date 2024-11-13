#include <iostream>
#include <fstream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8081
#define MAX_BUFFER_SIZE 1024

int main() {
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    // Open the image file in binary mode
    std::ifstream infile("cat.jpg", std::ios::binary);
    if (!infile.is_open()) {
        std::cerr << "Failed to open image file!" << std::endl;
        return -1;
    }

    // Create client socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);                  // Port to connect to
    server_addr.sin_addr.s_addr = inet_addr("10.104.130.17");  // Receiver's IP

    // Connect to the receiver
    if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(client_fd);
        return -1;
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

    return 0;
}
