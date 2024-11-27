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
    i = atoi(receivedChars);
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
        Serial.print(receivedChars);
    }
  }

}

void measure() {
   interruptCount=1;
}

void servo() {
  servoP1 = lineDegreex[i];
  Serial.print(servoP1);
  servo1.attach(servoPin1, minUs, maxUs);
  servo2.attach(servoPin2, minUs, maxUs);
  servo1.write(servoP1);
  servo2.write(lineDegreey[i]);
  servo1.detach();
  servo2.detach();
  newData = false;
}
