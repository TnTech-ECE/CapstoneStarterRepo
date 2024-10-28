#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <SPI.h>

#define LOCAL_UDP_PORT 1337
#define REMOTE_UDP_PORT 1337
const char SSID[] = "TestNetwork";
const char PASSWORD[] = "Dontworryaboutit";
const char HOST_NAME[] = "NetworkStation1";
IPAddress remoteIp;

WiFiUDP Udp;
char incomingPacket[256];  // buffer for incoming packets
char  replyPacket[] = "Hello world!";  // a reply string to send back
bool initalized = false;
char longCharArray[256];



void setup()
{
  Serial.begin(9600);
  while(!Serial){}
  
  for(int i = 0; i < 10; i++){
  Serial.printf("Debug\n");
  delay(500);
}
delay(1000);
Serial.printf("Welcome to the networker!!\n");
  Serial.printf("Connecting to %s ", SSID);
    WiFi.hostname(HOST_NAME);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  Udp.begin(LOCAL_UDP_PORT);
  Serial.printf("Now listening at IP %s, UDP port %d, remote IP: %s\n", WiFi.localIP().toString().c_str(), LOCAL_UDP_PORT, Udp.remoteIP().toString().c_str());
}

bool recievedPacket(){
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    // receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    remoteIp = Udp.remoteIP();
    
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
   
    Serial.printf("UDP packet contents: %s\n", incomingPacket);
    // send back a reply, to the IP address and port we got the packet from
    sendPacket(incomingPacket);
    return true;
  }
  return false;
}
void sendPacket(char packetData[]){
    Udp.beginPacket(Udp.remoteIP(), REMOTE_UDP_PORT);
    Udp.write(packetData);
    Udp.endPacket();
    //Serial.printf("Sent to %s, port %d\n", Udp.remoteIP().toString().c_str(), Udp.remotePort());
}


void loop(){
recievedPacket();
}
