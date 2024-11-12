#include "capstoneproject.h"

void setup()
{
   VL53LX_Error status;
   // Led.
   pinMode(LedPin, OUTPUT);
   pinMode(interruptPin, INPUT_PULLUP);
   attachInterrupt(interruptPin, measure, FALLING);

   // Initialize serial for output.
   SerialPort.begin(115200);
   SerialPort.println("Starting...");
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
   // Initialize I2C bus.
   DEV_I2C.begin();

   // Configure VL53LX satellite component.
   sensor_vl53lx_sat.begin();

   // Switch off VL53LX satellite component.
   sensor_vl53lx_sat.VL53LX_Off();

   // Initialize VL53LX satellite component.
   status = sensor_vl53lx_sat.InitSensor(0x12);
   if(status)
   {
      SerialPort.println("Init sensor_vl53lx_sat failed...");
   }
   servo1.attach(servoPin1);
   servo2.attach(servoPin2);
   sensor_vl53lx_sat.VL53LX_StartMeasurement();
}

void loop()
{
   if(start == True){
    servo();
   }
   check_for_signal();
   VL53LX_MultiRangingData_t MultiRangingData;
   VL53LX_MultiRangingData_t *pMultiRangingData = &MultiRangingData;
   uint8_t NewDataReady = 0;
   int no_of_object_found = 0, j;
   char report[64];
   if (interruptCount)
   {
      int status;

      interruptCount=0;
      // Led blinking.
      digitalWrite(LedPin, HIGH);

      status = sensor_vl53lx_sat.VL53LX_GetMeasurementDataReady(&NewDataReady);
      if((!status)&&(NewDataReady!=0))
      {
         status = sensor_vl53lx_sat.VL53LX_GetMultiRangingData(pMultiRangingData);
         no_of_object_found=pMultiRangingData->NumberOfObjectsFound;
         for(j=0;j<no_of_object_found;j++)
         {
            if(j!=0)SerialPort.print("\r\n                   ");
            time = millis();
            distancemm = pMultiRangingData->RangeData[j].RangeMilliMeter;
            SerialPort.print("status=");
            SerialPort.print(pMultiRangingData->RangeData[j].RangeStatus);
            SerialPort.print(", D=");
            SerialPort.print(distancemm);
            SerialPort.print("mm, Time = ");
            SerialPort.print(time);
         }
         SerialPort.println("");
         if (status==0)
         {
            status = sensor_vl53lx_sat.VL53LX_ClearInterruptAndStartMeasurement();
         }
      }
      digitalWrite(LedPin, LOW);
   }
}

//Checks if serial avalible and then reads chars into char array
void check_for_signal() {
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
      i = atoi(message);
    }
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

void measure()
{
   interruptCount=1;
}

void servo(){
  if(lineDegreex[i] <= servoPos1){
    while(servoPos1 >= lineDegreex[i]) {
      servoPos1--;
      servo1.write(servoPos1);
      Serial.println(servoPos1);
      delay(5);
    }
  }
  else{
    while(servoPos1 <= lineDegreex[i]) {
      servoPos1++;
      servo1.write(servoPos1);
      Serial.println(servoPos1);
      delay(5);
    }
  }

  if(lineDegreey[j] <= servoPos2){
    while(servoPos2 >= lineDegreey[j]) {
      servoPos2--;
      servo1.write(servoPos2);
      Serial.println(servoPos2);
      delay(5);
    }
  }
  else{
    while(servoPos2 <= lineDegreey[j]) {
      servoPos2++;
      servo1.write(servoPos2);
      Serial.println(servoPos2);
      delay(5);
    }
  }
}
