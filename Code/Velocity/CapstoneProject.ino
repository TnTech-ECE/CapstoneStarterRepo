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
    while(servoPos1 <= lineDegreex[j]) {
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
