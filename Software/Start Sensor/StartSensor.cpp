#include "start_sensor.h"
#include "SparkFun_APDS9960.h"
#include <Wire.h>
#include <Arduino.h>
using namespace std;

//Constants
//pin numbers for button/sensor
const int startButton = 12;

//values to determine required green color
const uint16_t minGreen = 175;
const uint16_t maxRed = 75;
const uint16_t maxBlue = 75;

//create APDS Object
SparkFun_APDS9960 apds = SparkFun_APDS9960();

//function to detect start signal either from button or go light
int detectStart(int startSig)
{
  //sets up pin for push button
  pinMode(startButton, INPUT);
  
  //Sets up I2C and initial values
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }

  // Start running the APDS-9960 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }
  
  // Wait for initialization and calibration to finish
  delay(500);

  //initially reads button
  int button = digitalRead(startButton);

  //Initially reads light
  uint16_t readRed = 0;
  uint16_t readBlue = 0;
  uint16_t readGreen = 0;
  apds.readRedLight(readRed);
  apds.readGreenLight(readGreen);
  apds.readBlueLight(readBlue);

  //red range
  bool redRange = readRed <= maxRed;
  //blue range
  bool blueRange = readBlue <= maxBlue;
  //green range
  bool greenRange = readGreen >= minGreen;

  //does the range match?
  bool match = redRange && blueRange && greenRange;

  //Wait until button push or light detected
  while(button == LOW && !match)
  {
    //Do nothing
    Serial.print("Wait...\n");
    delay(100);

    //read again
    button = digitalRead(startButton);
    apds.readRedLight(readRed);
    apds.readGreenLight(readGreen);
    apds.readBlueLight(readBlue);

    redRange = readRed <= maxRed;
    blueRange = readBlue <= maxBlue;
    greenRange = readGreen >= minGreen;
    match = redRange && blueRange && greenRange;

  }

  //once button push or light detected send go signal!
  startSig = HIGH;
  Serial.print("Go!\n");

  return startSig;
}