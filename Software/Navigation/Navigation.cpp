#include "sensorbar.h"
#include "motors.h"
#include "navigation.h"
#include <Wire.h>
#include <Arduino.h>
using namespace std;

// Uncomment one of the four lines to match your SX1509's address
//  pin selects. SX1509 breakout defaults to [0:0] (0x3E).
const uint8_t SX1509_ADDRESS = 0x3E;  // SX1509 I2C address (00)
//const byte SX1509_ADDRESS = 0x3F;  // SX1509 I2C address (01)
//const byte SX1509_ADDRESS = 0x70;  // SX1509 I2C address (10)
//const byte SX1509_ADDRESS = 0x71;  // SX1509 I2C address (11)

SensorBar mySensorBar(SX1509_ADDRESS);

//Define the states that the decision making machines uses:
#define IDLE_STATE 0
#define READ_LINE 1
#define GO_FORWARD 2
#define GO_LEFT 3
#define GO_RIGHT 4
#define BIG_CORNER 5

uint8_t state;

//Setup Function
void navSetup()
{
  Serial.print("Nav Setup\n");
//Default: the IR will only be turned on during reads.
  mySensorBar.setBarStrobe();
  //Other option: Command to run all the time
  //mySensorBar.clearBarStrobe();

  //Default: dark on light
  mySensorBar.clearInvertBits();
  //Other option: light line on dark
  //mySensorBar.setInvertBits();
  
  //Don't forget to call .begin() to get the bar ready.  This configures HW.
  uint8_t returnStatus = mySensorBar.begin();

  Serial.print("Message: ");
  //Messages on status
  if(returnStatus)
  {
	  Serial.println("\nsx1509 IC communication OK");
  }
  else
  {
	  Serial.println("\nsx1509 IC communication FAILED!");
  }
  Serial.println();
}

void nav(bool& straight, bool& right, bool& left, bool& corner, bool& lost)
{
  uint8_t nextState = state;

  switch (state) {
    //if idle -- stop
    case IDLE_STATE:
      nextState = READ_LINE;
      break;

    //read line
    case READ_LINE:
      //Serial.println(mySensorBar.getPosition());
      //line detected and isn't complete line

      //if all eyes see a line -- STOP
      if(mySensorBar.getDensity() == 0)
      {
        Serial.println("STOP AT GAP!");
        nextState = IDLE_STATE;
        corner = false;
        right = false;
        left = false;
        straight = false;
      }

      //if less than all eyes see a line
      else if( mySensorBar.getDensity() <= 7)
      {
        //straight line (b3 and b4 are dim)
        if(mySensorBar.getPosition() >= -12 && mySensorBar.getPosition() <= 12)
        { 
          nextState = GO_FORWARD; 
          straight = true;
          corner = false;
          left = false;
          right = false;
        }

        //to the right of the line AKA turn left (b6 is dim)
        else if(mySensorBar.getPosition() > 10 && mySensorBar.getPosition() < 95)
        {
          nextState = GO_LEFT;
          straight = false;
          corner = false;
          left = true;
          right = false;
        }

        //to the left of the line AKA turn right (b1 or b0 or both are dim)
        else if( mySensorBar.getPosition() < -12)
        {
          straight = false;
          corner = false;
          right = true;
          left = false;
          nextState = GO_RIGHT;
        }

        else if(mySensorBar.getPosition() >= 95)
        {
          corner = true;
          straight = false;
          right = false;
          left = false;
          nextState = BIG_CORNER;
        }

      }
      //off line
      else
      {
        Serial.print("OFF THE LINE COMPLETELY!!!\n");
        corner = false;
        straight = false;
        right = false;
        left = false;
        lost = true;
        nextState = IDLE_STATE;
      }
      break;

    //drive forward 
    case GO_FORWARD:
      //drive();
      Serial.print("Go!\n");
      nextState = READ_LINE;
      break;

    //turn left  
    case GO_LEFT:
      //turnLeft();
      Serial.print("Left!\n");
      nextState = READ_LINE;
      break;

    //turn right
    case GO_RIGHT:
      //turnRight();
      Serial.print("Right!\n");
      nextState = READ_LINE;
      break;

    case BIG_CORNER:
      //turnLeft();
      Serial.print("BIG LEFT!\n");
      nextState = READ_LINE;
      break;

    //stop  
    default:
      //stop();
      Serial.print("Stop!\n");
      break;
    }

  //Serial for test purposes
  //Serial.println(mySensorBar.getPosition());
  Serial.println(mySensorBar.getPosition());
  state = nextState;

  //wait
  delay(100);
}



