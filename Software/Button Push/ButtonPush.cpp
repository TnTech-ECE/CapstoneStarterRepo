#include <Wire.h>
#include <Arduino.h>
#include <Servo.h>
using namespace std;

void deployBP()
{
  Servo buttonPush;
  buttonPush.attach(3);

  //rotate counter-clock
  buttonPush.write(45);
  Serial.print("Pulling pin...\n");
  delay(5000);


  //rotate counter-clock
  buttonPush.write(0);
  Serial.print("Pushing pin back...\n");
  delay(5000);
}