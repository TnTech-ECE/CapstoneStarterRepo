/*
  Author:       JT Jones
  Date:         30 October 2024
  Description:  Used by capstone networking subsystem to transmit data over LAN using UDP packets
  Usage:        The code currently sends a packet once it recieved data over Serial - the Rx pin. 
                Use forwardData(char*) to send a byte array.
  Setup:        Set the SSID to the name of the access point, and set the PASSWORD. Set HOST_NAME 
                to something descriptive. Set ID to a unique byte to other subsystems.
*/
#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <SPI.h>

#define LOCAL_UDP_PORT 1337     //Any port as long as the firewall is fine with it
#define REMOTE_UDP_PORT 1337    //Probably should be the same as local
#define PAYLOAD_LEN 1
#define ID '0'
const IPAddress REMOTE_IP(10, 104, 130, 255);

// WiFi Credentials
const char SSID[] = "EagleNet";
const char PASSWORD[] = "cY4DoKPo";
// Arbitrary name
const char HOST_NAME[] = "NetworkStation1";
IPAddress remoteIp;

WiFiUDP Udp;
char incomingPacket[256];  // buffer for incoming packets

void sendPacket(char packetData[]);

void setup(){
  // Setup Serial for USB debugging and rx/tx
  Serial.begin(9600);
  while(!Serial){}
  delay(1000);

  //Print Welcome
  Serial.printf("Welcome to the networker!!\n");

  // Will print '.' to the serial until it connects to the access point
  Serial.printf("Connecting to %s ", SSID);
  WiFi.hostname(HOST_NAME);
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println(" connected");

  Udp.begin(LOCAL_UDP_PORT);
  Serial.printf("Now listening at IP %s, UDP port %d, remote IP: %s\n", WiFi.localIP().toString().c_str(), LOCAL_UDP_PORT, Udp.remoteIP().toString().c_str());
}

// Check if packet is recieved. Returns true if packet is recieved else: false
bool recievedPacket(){
  int packetSize = Udp.parsePacket();

  //if packetSize is null then no packet has been recieved
  if (packetSize){
    // receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    remoteIp = Udp.remoteIP();
    
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }

    // Display contents to serial
    Serial.printf("UDP packet contents: %s\n", incomingPacket);
    // send back a reply by repeating the packet back
    //sendPacket(incomingPacket);
    return true;
  }
  return false;
}

// Do not use directly, use forwardData. Sends Packet with payload that is packetData
void sendPacket(char packetData[]){
    Udp.beginPacket(REMOTE_IP, REMOTE_UDP_PORT);
    Udp.write((const char*)packetData, PAYLOAD_LEN+1);
    Udp.endPacket();
    //Serial.printf("Sent to %s, port %d\n", Udp.remoteIP().toString().c_str(), Udp.remotePort());
}

// Sends packet and adds the ID
inline void forwardData(char data[]){
  char payload[PAYLOAD_LEN+1];
  payload[0] = ID;
  for(int i = 0; i < PAYLOAD_LEN; i++){
    payload[i+1] = data[i];
  }
  /*
  for(int i = 0; i < PAYLOAD_LEN+1; i++){
    Serial.print(payload[i]);
  }
  */
  sendPacket(payload);
}


void loop(){
  /*
    while(1){
      sendPacket("Hello World!");
      delay(500);
    }*/
  // If serial message is availible
  if (Serial.available()) {
    String message = ""; 

    // Build the message

    while (Serial.available()) {
      char c = Serial.read();
      message += c;
      delayMicroseconds(1000);
    }

    // Display the message on the Serial monitor
    Serial.print("Received: ");
    Serial.println(message);

    // Send the packet over udp
    forwardData((char*)message.c_str());
  }
}