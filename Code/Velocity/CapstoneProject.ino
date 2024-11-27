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
   // Initialize serial for output.
   Serial.begin(9200);
   //SerialPort.println("Starting...");
   while(!Serial){}
   // Initialize I2C bus.
   DEV_I2C.begin();
   // Configure VL53LX satellite component.
   sensor_vl53lx_sat.begin();
   // Switch off VL53LX satellite component.
   sensor_vl53lx_sat.VL53LX_Off();
   // Initialize VL53LX satellite component.
   status = sensor_vl53lx_sat.InitSensor(0x12);
   if(status) {
      Serial.println("Init sensor_vl53lx_sat failed...");
   }
   sensor_vl53lx_sat.VL53LX_StartMeasurement();
}

void loop() {
   VL53LX_MultiRangingData_t MultiRangingData;
   VL53LX_MultiRangingData_t *pMultiRangingData = &MultiRangingData;
   uint8_t NewDataReady = 0;
   int no_of_object_found = 0, j;
   char report[64];
   serial_input();
   if (newData == true){
    //Serial.print(i);
    if(i < 17){
      servo();
    }
    newData = false;
   }
   if (interruptCount) {
      int status;
      interruptCount=0;
      // Led blinking.
      digitalWrite(LedPin, HIGH);
      status = sensor_vl53lx_sat.VL53LX_GetMeasurementDataReady(&NewDataReady);
      if((!status)&&(NewDataReady!=0)) {
         status = sensor_vl53lx_sat.VL53LX_GetMultiRangingData(pMultiRangingData);
         no_of_object_found=pMultiRangingData->NumberOfObjectsFound;
         for(j=0;j<no_of_object_found;j++) {
            distancemm = pMultiRangingData->RangeData[j].RangeMilliMeter;
            time_ms = millis();
            if(distancemm < 900) {
              Serial.print(time_ms);
              Serial.print(distancemm);
            }
         }
         //SerialPort.println("debug");
         if (status==0)
         {
           status = sensor_vl53lx_sat.VL53LX_ClearInterruptAndStartMeasurement();
         }
      }
      digitalWrite(LedPin, LOW);
   }
}

void serial_input() {
  char rc;
  String rs;
  //Allows for junk over serial since there is no endmarker 
  while (Serial.available()) {
    rc = Serial.read();
    rs += rc;
  }
  //Hard coding conversion to line number
  if(rs.length()>0){
    if(rs = "1"){
      i = 1;
    }
    else if (rs = "2"){
      i = 2;
    }
    else if (rs = "3"){
      i = 3;
    }
    else if (rs = "4"){
      i = 4;
    }
    else if (rs = "5"){
      i = 5;
    }
    else if (rs = "6"){
      i = 6;
    }
    else if (rs = "7"){
      i = 7;
    }
    else if (rs = "8"){
      i = 8;
    }
    else if (rs = "9"){
      i = 9;
    }
    else if (rs = "A"){
      i = 10;
    }
    else if (rs = "B"){
      i = 11;
    }
    else if (rs = "C"){
      i = 12;
    }
    else if (rs = "D"){
      i = 13;
    }
    else if (rs = "E"){
      i = 14;
    }
    else if (rs = "F"){
      i = 15;
    }
    rs = "\0";
    newData = true;
  }
}

void measure() {
   interruptCount=1;
}

void servo() {
  Serial.print(lineDegreex[i]);
  servo1.attach(servoPin1, minUs, maxUs);
  servo2.attach(servoPin2, minUs, maxUs);
  servo1.write(lineDegreex[i]);
  servo2.write(lineDegreey[i]);
  servo1.detach();
  servo2.detach();
  newData = false;
}
