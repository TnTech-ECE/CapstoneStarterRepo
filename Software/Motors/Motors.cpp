#include "motors.h"
#include <Wire.h>
#include <Arduino.h>
using namespace std;

//constants
const int IN1=5;
const int IN2=4;
const int ENA=6;
const int IN3=8;
const int IN4=7;
const int ENB=9;

//Motor setup
void motorSetup()
{
  //motor one pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  //motor two pins
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(ENB, OUTPUT);
}

//Drive forward
void drive()
{
  //quick pace but not crazy fast
  int speed = 255;
  //Serial.print("Onward!\n");

  //motor one -- counter
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW); 
  analogWrite(ENA,speed);

  //motor two -- counter
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW); 
  analogWrite(ENB,speed);
}

void stop()
{
  //Serial.print("Stopping!\n");

  //motor one -- stop
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);

  //motor two -- stop
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void turnRight()
{
  //small speed 
  int speedL = 100;
  int speedR = 255;
  //Serial.print("Turn Right!\n");

  //motor one
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); 
  analogWrite(ENA,speedR);

  //motor two
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW); 
  analogWrite(ENB,speedL);
}

void turnLeft()
{ 
  //small speed 
  int speedL = 255;
  int speedR = 100;
  //Serial.print("Turn Left!\n");

  //motor one
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW); 
  analogWrite(ENA,speedR);
  
  //motor two 
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW); 
  analogWrite(ENB,speedL);
}

void turnCorner()
{
  int speedL = 255;
  int speedR = 255;

  //motor one
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speedR);

  //motor two
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speedL);

}