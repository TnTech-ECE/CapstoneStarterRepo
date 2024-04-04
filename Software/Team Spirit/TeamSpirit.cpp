#include "team_spirit.h"
#include <Wire.h>
#include <Arduino.h>
using namespace std;

//constants
const int purple = 6;
const int yellow = 7;


void blinkTS(bool& blinkToggle)
{
  //sets up pin for LEDs
  pinMode(purple, OUTPUT);
  pinMode(yellow, OUTPUT);
  

  if(blinkToggle)
  {
    digitalWrite(yellow, LOW);
    digitalWrite(purple, HIGH);
    Serial.print("Purple\n");
    blinkToggle = false;
  }
  else
  {
    digitalWrite(yellow, HIGH);
    digitalWrite(purple, LOW);
    Serial.print("Yellow\n");
    blinkToggle = true;
  } 
}

void offTS()
{
  //sets up pin for LEDs
  pinMode(purple, OUTPUT);
  pinMode(yellow, OUTPUT);

  digitalWrite(yellow, LOW);
  digitalWrite(purple, LOW);
}