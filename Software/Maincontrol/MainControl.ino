#include "motors.h"
#include "start_sensor.h"
#include "navigation.h"
#include "Wire.h"
#include <Arduino.h>

int startSignal = LOW;
bool cornerDetect = false;
bool straightLine = false;
bool leftTurn = false;
bool rightTurn = false;
bool hellaLost = false;
int run = 0;

void setup() {
  // put your setup code here, to run once:
  
  //Start up Serial for testing 
  Serial.begin(9600);
  Serial.println();

  Serial.print("ON\n");
  //Setup Nav and Motors
  navSetup();
  motorSetup();

}

void loop() {
  // put your main code here, to run repeatedly:


  while(run == 0)
  { 
    //runs until go signal is received
    Serial.print("RUN\n");
    while(startSignal == LOW)
    {
      startSignal = detectStart(startSignal);
    }
    
    //Drive out of the grey box
    drive();
    delay(500);

    while(!cornerDetect)
    {
      nav(straightLine, rightTurn, leftTurn, cornerDetect, hellaLost);
      if(straightLine)
      {
        drive();
        delay(250);
        stop();
      }
      else if(rightTurn)
      {
        turnRight();
        delay(250);
        stop();
      }
      else if(leftTurn)
      {
        turnLeft();
        delay(250);
        stop();
      }
      else if(hellaLost)
      {
        turnLeft();
        delay(250);
        stop();
      }
    }

    turnCorner();
    delay(1000);
    cornerDetect = false;

   while(!cornerDetect)
    {
      nav(straightLine, rightTurn, leftTurn, cornerDetect, hellaLost);
      if(straightLine)
      {
        drive();
        delay(250);
        stop();
      }
      else if(rightTurn)
      {
        turnRight();
        delay(250);
        stop();
      }
      else if(leftTurn)
      {
        turnLeft();
        delay(250);
        stop();
      }
      else if(hellaLost)
      {
        turnLeft();
        delay(250);
        stop();
      }
    }

    turnCorner();
    delay(1000);  

    stop();
    

    run = 1;
  }
}
