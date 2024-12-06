#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdint>
#include <cmath>
#include <ctime>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h> //used for none window machine
#include <netinet/in.h>
#include <unistd.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <filesystem>
#include <vector>
#include <thread>
#include <chrono>

#pragma comment(lib, "Ws2_32.lib")  // Link with Winsock library

using namespace std;
namespace fs = filesystem;

#define LISTEN_PORT1 8080
#define LISTEN_PORT2 9090
#define BUFFER_SIZE 300
#define IMAGE_SIZE 4096
#define SEND_PORT 10010

struct DataPacket {
    float value1;
    double value2;
    float value3;
    double value4;

};

string currentRID = "Global string";

string getTimeStamp() {
    auto now = chrono::system_clock::now();
    auto in_time_t=chrono::system_clock::to_time_t(now);

    stringstream ss;
    ss << put_time(localtime(&in_time_t), "%y-%m-%d %H:%M:%S");
    return ss.str();
}

void createDirectory(const string& dir) {
    struct stat info;
    if(stat(dir.c_str(), &info) != 0) {
        cout << "Directory does not exist, creating a new one...\n";
        if(mkdir(dir.c_str(), 0777) != 0) {
            cerr << "Failed to create directory: " << dir << "\n";
        }
    }
}

// Function to extract and process ANSI/CTA-2063-A Serial Number
string processAnsiSerialNumber(const vector<uint8_t>& data) {
    stringstream result;
    // Manufacturer Code (first 4 characters)
    for (int i = 0; i < 4; ++i) {
        result << static_cast<char>(data[i]);
    }
    // Length Code to indicate how many character the Serial number will have
    char lengthCode = static_cast<char>(data[5]);
    int serialLength = lengthCode - 'A' + 1;
    // Serial Number (remaining characters)
    for (int i = 6; i < serialLength + 5; ++i) {
        result << static_cast<char>(data[i]);
    }
    return result.str();
}

// Function to process CAA Assigned Registration ID
string processCaaRegistrationID(const vector<uint8_t>& data) {
    stringstream result;
    result << static_cast<char>(data[0]) << ".";  // ICAO Nationality Mark
    for (int i = 1; i < data.size(); ++i) {
        result << static_cast<char>(data[i]);
    }
    return result.str();
}

// Function to process UTM Assigned UUID
string processUtmUUID(const vector<uint8_t>& data) {
    stringstream result;
    result << static_cast<char>(data[0]);
    result << ".";
    for (int i = 2; i < data.size(); i++) {
        result << static_cast<char>(data[i]);
    }
    
    return result.str();
}

// Function to process Specific Session ID of Drone
string processSpecificSessionID(const vector<uint8_t>& data) {
    stringstream result;
    result << hex << setw(2) << setfill('0') << (int)data[0] << "-";  // Specific Session ID Type
    for (int i = 1; i < data.size(); ++i) {
        result << hex << setw(2) << setfill('0') << (int)data[i];
    }
    return result.str();
}

// Function to process Location/Vector message type 0x1, to extra drone speed
float processDroneSpeed(const vector<uint8_t>& data) {
    // Status/Flags from offset 1
    bool multiplierFlag = (data[1] & 0x01) != 0;
    
    // Speed from offset 3
    uint8_t speedEncoded = data[3];
    float speed = 0;
    if (multiplierFlag == 0) {
        speed = speedEncoded * 0.25;
    } else {
        speed = (speedEncoded * 0.75) + (255 * 0.25);
    }

    return speed;
}

// Function to process Location/Vector message type 0x1, to extra process DroneLatitude
double processDroneLatitude(const vector<uint8_t>& data) {
    // Latitude from offset 5 to 8
    int32_t latEncoded = (data[4] << 24) | (data[5] << 16) | (data[6] << 8) | data[7];
    double divisor = pow(10, 7);
    double latitude = latEncoded / divisor;
    
    return latitude;
}

// Function to process Location/Vector message type 0x1, to extra drone longitude
double processDroneLongitude(const vector<uint8_t>& data) {
    // Longitude from offset 9 to 12
    int32_t lonEncoded = (data[8] << 24) | (data[9] << 16) | (data[10] << 8) | data[11];
    double longitude = lonEncoded / 1e7;

    return longitude;  
}

// Function to process Location/Vector message type 0x1, to extra Drone altitude
float processDroneAltitude(const vector<uint8_t>& data) {
    // Altitude from offset 15 to 16
    int16_t altEncoded = (data[14] << 8) | data[15];
    float altitude = (altEncoded * 0.5f) - 1000;
    if (altitude == -1000) {
        cout << "Altitude: Unknown\n" << endl;
    } else {
        cout << "Altitude: " << altitude << " meters\n" << endl;
    }

    return altitude;
}

// Function to process Location/Vector message type 0x1, to extra time stamp
string processDroneTime(const vector<uint8_t>& data) {
    // Timestamp from offset 21 to 22 (tenths of seconds since the hour)
    uint16_t timestampEncoded = (data[20] << 8) | data[21];
    time_t now = time(nullptr);  // Get current time
    
    // Set tm struct to current time, with minutes and seconds zeroed
    struct tm* currentTime = localtime(&now);
    currentTime->tm_min = 0;
    currentTime->tm_sec = 0;

    // Convert back to time_t and add the timestamp in seconds
    time_t hourStart = mktime(currentTime);
    time_t fullTimestamp = hourStart + (timestampEncoded / 10);  // Convert tenths of seconds to seconds

    // Format the timestamp
    char formattedTime[20];
    strftime(formattedTime, sizeof(formattedTime), "%Y-%m-%d %H:%M:%S", localtime(&fullTimestamp));

    return formattedTime;
}

// Process Operator Location message type 0x4
double processOperatorLatitude(const vector<uint8_t>& data) {
    // Latitude from offset 2 to 5
    int32_t latEncoded = (data[1] << 24) | (data[2] << 16) | (data[3] << 8) | data[4];
    double operatorLatitude = latEncoded / 1e7;

    return operatorLatitude;
}

double processOperatorLongitude(const vector<uint8_t>& data) {
    // Longitude from offset 6 to 9
    int32_t lonEncoded = (data[5] << 24) | (data[6] << 16) | (data[7] << 8) | data[8];
    double operatorLongitude = lonEncoded / 1e7;

    return operatorLongitude;
}

double processOperatorAltitude(const vector<uint8_t>& data) {
    // Altitude from offset 18 to 19
    int16_t altEncoded = (data[17] << 8) | data[18];
    float operatorAltitude = (altEncoded * 0.5f) - 1000.0f;

    return operatorAltitude;
}

string processOperatorTime(const vector<uint8_t>& data) {
    // Timestamp from offset 20 to 23 (Unix Timestamp)
    uint32_t timestampEncoded = (data[19] << 24) | (data[20] << 16) | (data[21] << 8) | data[22];
    time_t timestamp = timestampEncoded + 1546300800; // Adding offset to convert to standard Unix timestamp
    struct tm* tm_info = localtime(&timestamp);
    
    char buffer[20]; // For formatted time
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);

    return buffer;
}

// Function to insert Drone data into the MariaDB database for drone location table
void drone_location(string drone_id, float dr_speed, double dr_latitude, double dr_longitude, float dr_altitude, string dr_tm_info) {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::PreparedStatement *pstmt;

    try {
        // Establish connection to the MariaDB server
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "tntech"); //localhost:3306
        con->setSchema("RID");

        // Prepare the SQL INSERT statement
        pstmt = con->prepareStatement("INSERT INTO drone_location (id, speed, drone_latitude, drone_longitude, drone_altitude, timestamp) VALUES (?, ?, ?, ?, ?, ?)");

        // Set parameters for the prepared statement
        pstmt->setString(1, drone_id);
        pstmt->setDouble(2, dr_speed);
        pstmt->setDouble(3, dr_latitude);
        pstmt->setDouble(4, dr_longitude);
        pstmt->setDouble(5, dr_altitude);
        pstmt->setString(6, dr_tm_info);

        // Execute the statement
        pstmt->executeUpdate();

        cout << "Data inserted successfully!" << endl;

    } catch (sql::SQLException &e) {
        cerr << "SQL error: " << e.what() << endl; // Print SQL errors
    } catch (exception &e) {
        cerr << "Error: " << e.what() << endl; // Print general errors
    }

    // Clean up
    delete pstmt;
    delete con;
}

bool checkDroneLocation(double dr_latitude, double dr_longtitude) {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    bool warning = false;

    // Establish connection to the MariaDB server
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "tntech"); //localhost:3306
    con->setSchema("RID");

    // Create a statement object
    sql::Statement *stmt;
    stmt = con->createStatement();

    // Execute a query to select data
    sql::ResultSet *res;
    res = stmt->executeQuery("SELECT max_latitude, min_latitude, max_longitude, min_longitude FROM priority_zone");

    // Process the result set
    while (res->next()) {
        double maxLatitude = res->getDouble("max_latitude");
        double minLatitude = res->getDouble("min_latitude");
        double maxLongitude = res->getDouble("max_longitude");
        double minLongitude = res->getDouble("min_longitude");

        // Check if the drone is within the priority zone
        if((dr_latitude<maxLatitude) && (dr_latitude>minLatitude) && (dr_longtitude<maxLongitude) && (dr_longtitude>minLongitude)) {
            warning = true;
            break;
        }
    }

    // Clean up
    delete res;
    delete stmt;
    delete con;

    return warning;
}

// Function to insert Drone operator data into the MariaDB database for operator location table
void operator_location(string drone_id, double op_latitude, double op_longitude, float op_altitude, string op_tm_info) {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::PreparedStatement *pstmt;

    try {
        // Establish connection to the MariaDB server
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://localhost:3306", "root", "tntech");
        con->setSchema("RID");

        // Prepare the SQL INSERT statement
        pstmt = con->prepareStatement("INSERT INTO operator_location (id, operator_latitude, operator_longitude, operator_altitude, timestamp) VALUES (?, ?, ?, ?, ?)");

        // Set parameters for the prepared statement
        pstmt->setString(1, drone_id);
        pstmt->setDouble(2, op_latitude);
        pstmt->setDouble(3, op_longitude);
        pstmt->setDouble(4, op_altitude);
        pstmt->setString(5, op_tm_info);

        // Execute the statement
        pstmt->executeUpdate();

        cout << "Data inserted successfully!" << endl;

    } catch (sql::SQLException &e) {
        cerr << "SQL error: " << e.what() << endl; // Print SQL errors
    } catch (exception &e) {
        cerr << "Error: " << e.what() << endl; // Print general errors
    }

    // Clean up
    delete pstmt;
    delete con;
}

// Function to send DataPacket
bool sendDataPacket(int socket, const DataPacket &packet) {
    ssize_t bytes_sent = send(socket, &packet, sizeof(DataPacket), 0);
    return bytes_sent == sizeof(DataPacket);
}

// Client function to send DataPacket to a given port
void sendToPort(int port, const DataPacket &packet) {
    int sock;
    struct sockaddr_in server_address;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cerr << "Socket creation error for port " << port << "\n";
        return;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, "10.104.196.92", &server_address.sin_addr) <= 0) {
        cerr << "Invalid address or address not supported\n";
        close(sock);
        return;
    }

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        cerr << "Connection failed for port " << port << "\n";
        close(sock);
        return;
    }

    cout << "Connected to port " << port << ", sending DataPacket...\n";
    if (sendDataPacket(sock, packet)) {
        cout << "DataPacket sent successfully to port " << port << "!\n";
    } else {
        cerr << "Failed to send DataPacket to port " << port << "\n";
    }

    close(sock);
}

// Server function to listen on a port and receive data
void ridReceive(int port) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    DataPacket packet;

    uint8_t buffer[BUFFER_SIZE];
    int messageCount;
    string user_id;
    int extraHeader = 0;
    float updatedDroneSpeed = 0;
    double updatedDroneLatitude = 0;
    double updatedDroneLongitude = 0;
    float updatedDroneAltitude = 0;
    bool inPriorityZone = false;

    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        cerr << "Socket creation error on port " << port << "\n";
        return;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        cerr << "Bind failed on port " << port << endl;
        close(server_fd);
        return;
    }

    if (listen(server_fd, 3) < 0) {
        cerr << "Listen failed on port " << port << endl;
        close(server_fd);
        return;
    }

    cout << "Listening on port " << port << "..." << endl;

    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
        cout << "Connection received on port " << port << ", waiting to receive data..." << endl;
        
        // Receive data
        ssize_t bytes_received = recv(new_socket, reinterpret_cast<char*>(buffer), BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            cerr << "Error receiving data" << endl;
        } else if (bytes_received > 0) {

            cout << "Bytes Received:" << bytes_received << endl;
            start = chrono::high_resolution_clock::now();
        } 

        if(buffer[4] == 0x0D) {
            // Get the number of message chunks from byte 9 for NAN Synchronization Beacon Frame(Wifi)
            messageCount = static_cast<int>(buffer[8]);
            cout << "Number of message: " << messageCount << endl;
            // extraHeader is used for the next 5 b
            //extraHeader = 9;
        }
        // else if (buffer[1] == 0x3C) - used for to check if the package is Bluetooth Beacon Frame
        // {
        //     // Get the number of message chunks from byte 26 for Bluetooth 5 Beacon Frame
        //     messageCount = (buffer[29 - 1] & 0x1F) << 3 | (buffer[30 - 1] >> 5);
        // }
        else {
            cout << "Incorrect Beacon Frame format" << endl;
        }
        
        for (int i = 0; i < messageCount; ++i) {
            // Each message chunk is 25 bytes + (9) bytes of extra head only for NAN synchronization Beacon Frame, need to implment for Bluetooth
            int chunkOffset = 9 + (i * 25) - 1;
            cout << "Current message point: " << chunkOffset << endl;
            uint8_t messageHeader = buffer[chunkOffset+1];
            uint8_t messageType = (messageHeader >> 4) & 0x0F;
            cout << static_cast<int>(messageType) << endl;
            uint8_t idTypeHeader = buffer[chunkOffset+2];
            uint8_t idType = (idTypeHeader & 0xF0) >> 4;
            cout << static_cast<int>(idType) << endl;
            
            // Extract the relevant 24 bytes for message processing
            vector<uint8_t> messageData(buffer + chunkOffset + 2, buffer + chunkOffset + 25);
            
            // Switch on messageType first
            switch (static_cast<int>(messageType)) {
                case 0:
                    // Switch based on idType
                    switch (static_cast<int>(idType)) {
                        case 1:
                            cout << "Serial Number: " << processAnsiSerialNumber(messageData) << endl;
                            user_id = processAnsiSerialNumber(messageData);
                            currentRID = user_id;
                            break;
                        case 2:
                            cout << "CAA Assigned Registration ID: " << processCaaRegistrationID(messageData) << endl;
                            user_id = processCaaRegistrationID(messageData);
                            currentRID = user_id;
                            break;
                        case 3:
                            cout << "UTM Assigned UUID: " << processUtmUUID(messageData) << endl;
                            user_id = processUtmUUID(messageData);
                            currentRID = user_id;
                            break;
                        case 4:
                            cout << "Specific Session ID: " << processSpecificSessionID(messageData) << endl;
                            user_id = processSpecificSessionID(messageData);
                            currentRID = user_id;
                            break;
                        default:
                            cout << "Unknown ID Type" << endl;
                            break;
                    }
                    break;
                case 1:
                    updatedDroneSpeed = processDroneSpeed(messageData);
                    updatedDroneLatitude = processDroneLatitude(messageData);
                    updatedDroneLongitude = processDroneLongitude(messageData);
                    updatedDroneAltitude = processDroneAltitude(messageData);
                    drone_location(user_id, updatedDroneSpeed, updatedDroneLatitude, updatedDroneLongitude, updatedDroneAltitude, processDroneTime(messageData));
                    inPriorityZone = checkDroneLocation(updatedDroneLatitude, updatedDroneLongitude);
                    break;
                case 4:
                    operator_location(user_id, processOperatorLatitude(messageData), processOperatorLongitude(messageData), processOperatorAltitude(messageData), processOperatorTime(messageData));
                    break;
                default:
                    cout << "Unknown Message Type" << endl;
                    break;
            }

            if(inPriorityZone == true){
                packet.value1 = updatedDroneSpeed;
                packet.value2 = updatedDroneLatitude;
                packet.value3 = updatedDroneLongitude;
                packet.value4 = updatedDroneAltitude; 

                // Send data
                sendToPort(SEND_PORT, packet);
                end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
                cout << "time taken: " << duration.count() << " ms" << endl;
            }
        }

        close(new_socket);
    }

    close(server_fd);
}

void receiveImage(int clientSocket) {
    char image[IMAGE_SIZE];

    ssize_t bytesReceived;
    cout << "Receiving image data...\n";

    //create a new directory for the image file to be sotred in
    string timestamp = getTimeStamp();
    string directoryPath = "/home/tntech/Documents/capstone/" + currentRID;
    createDirectory(directoryPath);

    string fileName = directoryPath +"/" + timestamp + ".jpg";
    ofstream outFile(fileName, ios::binary);

    if (!outFile.is_open()) {
        cerr << "Failed to open file for writing: " << fileName << "\n";
        return;
    }

    while ((bytesReceived = recv(clientSocket, image, BUFFER_SIZE, 0)) > 0) {
        outFile.write(image, bytesReceived);
    }

    try {
        // Connect to the MariaDB database
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection* con = driver->connect("tcp://127.0.0.1:3306", "root", "tntech"); //localhost:3306
        con->setSchema("RID"); // Replace with your database name

        // Prepare SQL query to insert the image as BLOB
        unique_ptr<sql::PreparedStatement> pstmt(
            con->prepareStatement("INSERT INTO images (id, image_name, image_path) VALUES (?, ?, ?)")
        );


        // Bind the image data as a BLOB
        pstmt->setString(1, currentRID);
        pstmt->setString(2, timestamp);
        pstmt->setString(3, fileName);

        // Execute the query
        pstmt->executeUpdate();
        cout << "Image successfully saved to database.\n";

        // Clean up
        delete con;
    } catch (sql::SQLException& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    if (bytesReceived < 0) {
        cerr << "Error receiving data.\n";
    } else {
        cout << "Image received and saved to " << fileName << "\n";
    }

    outFile.close();

    return;
}

void imageReceive(int PORT) {
    int clientSocket;

    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == 0) {
        perror("Socket failed");
        return;
    }

    // Bind the socket to the port
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(serverSocket);
        return;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 3) < 0) {
        perror("Listen failed");
        close(serverSocket);
        return;
    }

    cout << "Listening on port " << PORT << "..." << endl;

    // Accept a connection
    int addrlen = sizeof(address);

    while ((clientSocket = accept(serverSocket, (struct sockaddr*)&address, (socklen_t*)&addrlen)) >= 0) {
    if (clientSocket < 0) {
        perror("Accept failed");
        close(serverSocket);
        return;
    }

    cout << "Connection established. Receiving image...\n";

    // Receive the image and save it
    receiveImage(clientSocket);

    }

    // Close sockets
    close(clientSocket);
    close(serverSocket);
}

int main() {
    // Start listening on LISTEN_PORT1 and LISTEN_PORT2 in separate threads
    thread listenThread1(ridReceive, LISTEN_PORT1);

    thread listenThread2(imageReceive, LISTEN_PORT2);

    // Give the server time to start listening before the client sends data
    this_thread::sleep_for(chrono::seconds(1));

    // Join the listening threads before exiting
    listenThread1.join();
    listenThread2.join();

    return 0;
}