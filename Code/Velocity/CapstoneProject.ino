#include "capstoneproject.h"

void setup() {
  VL53LX_Error status;
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
   // Led.
   pinMode(LedPin, OUTPUT);
   pinMode(interruptPin, INPUT_PULLUP);
   attachInterrupt(interruptPin, measure, FALLING);
   servo1.setPeriodHertz(50);
   servo1.setPeriodHertz(50);
   servo1.attach(servoPin1, minUs, maxUs);
   servo2.attach(servoPin2, minUs, maxUs);

   // Initialize serial for output.
   SerialPort.begin(115200);
   //SerialPort.println("Starting...");
   while(!Serial){}
   //WiFi.hostname(HOST_NAME);
   //WiFi.begin(SSID, PASSWORD);
   
  // while (WiFi.status() != WL_CONNECTED){
      //delay(500);
      //Serial.print(".");
   //}
   //Serial.println(" connected");
   //Serial.printf("Now listening at IP %s, UDP port %d, remote IP: %s\n", WiFi.localIP().toString().c_str(), LOCAL_UDP_PORT, Udp.remoteIP().toString().c_str());
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
   //Udp.begin(LOCAL_UDP_PORT);
   sensor_vl53lx_sat.VL53LX_StartMeasurement();
}

void loop() {
   //check_for_signal();
   VL53LX_MultiRangingData_t MultiRangingData;
   VL53LX_MultiRangingData_t *pMultiRangingData = &MultiRangingData;
   uint8_t NewDataReady = 0;
   int no_of_object_found = 0, j;
   char report[64];
   serial_input();
   output_input();
   if (newData == true){
    i = atoi(receivedChars);//Could be atoi
    //if(i < 17){
      //if(j < 1) j++;
    servo();
    //}
   }
   if (interruptCount){
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
            if(j!=0)//SerialPort.print("\r\n                   ");
            distancemm = pMultiRangingData->RangeData[j].RangeMilliMeter;
            time_ms = millis();
            /*
            SerialPort.print("status=");
            SerialPort.print(pMultiRangingData->RangeData[j].RangeStatus);
            SerialPort.print(", D=");
            SerialPort.print(distancemm);
            SerialPort.print("mm, Time = ");
            SerialPort.print(time_ms);
            SerialPort.print("\n");
            */
         }
         //SerialPort.println("debug");
         if (status==0)
         {
            status = sensor_vl53lx_sat.VL53LX_ClearInterruptAndStartMeasurement();
         }
         /*
            byte byteArray[6];
            byteArray[0] = distancemm;
            byteArray[1] = (time_ms >> 24 ) & 0xFF;
            byteArray[2] = (time_ms >> 16 ) & 0xFF;
            byteArray[3] = (time_ms >> 8 ) & 0xFF;
            byteArray[4] =  (time_ms) & 0xFF;
            //forwardData((char *) byteArray);
            */
      }
      digitalWrite(LedPin, LOW);
   }
}

void serial_input(){
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;
  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();
    if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
            ndx = numChars - 1;
        } 
    }
    else {
        receivedChars[ndx] = '\0'; // terminate the string
        ndx = 0;
        newData = true;
    }
  }
}

void output_input(){
  if (newData == true) {
    Serial.print("This just in ... ");
    Serial.println(receivedChars);
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
      //i = atoi(message);
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
    Serial.printf("Sent to %s, port %d\n", Udp.remoteIP().toString().c_str(), Udp.remotePort());
    Udp.beginPacket(REMOTE_IP, REMOTE_UDP_PORT);
    Udp.write((const uint8_t*)packetData, PAYLOAD_LEN + 1);  // Cast to uint8_t*
    Udp.endPacket();
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
  }*/
  sendPacket(payload);
}

void measure()
{
   interruptCount=1;
}

void servo(){
  servoPos1 = i;
  SerialPort.print("Servo1 Moving to = ");
  //SerialPort.print(lineDegreex[i]);
  SerialPort.print(servoPos1);
  SerialPort.print("\n");
  //servoPos1 = lineDegreex[i];
  servo1.write(servoPos1);
  SerialPort.print("Servo1 Position Up = ");
  SerialPort.print(servoPos1);
  SerialPort.print("\n");
  newData = false;
}
