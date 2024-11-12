/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>
#include <Wire.h>
#include <vl53lx_class.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <ESP32Servo.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <SPI.h>
/**********Status**********/
#define CAPSTONEPROJECT_H
#define  VL53LX_RANGESTATUS_RANGE_VALID       0
/*!<The Range is valid. */
#define  VL53LX_RANGESTATUS_SIGMA_FAIL        1
/*!<Sigma Fail. */
#define  VL53LX_RANGESTATUS_SIGNAL_FAIL       2
/*!<Signal fail. */
#define  VL53LX_RANGESTATUS_RANGE_VALID_MIN_RANGE_CLIPPED 3
/*!<Target is below minimum detection threshold. */
#define  VL53LX_RANGESTATUS_OUTOFBOUNDS_FAIL      4
/*!<Phase out of valid limits -  different to a wrap exit. */
#define  VL53LX_RANGESTATUS_HARDWARE_FAIL     5
/*!<Hardware fail. */
#define  VL53LX_RANGESTATUS_RANGE_VALID_NO_WRAP_CHECK_FAIL  6
/*!<The Range is valid but the wraparound check has not been done. */
#define VL53LX_RANGESTATUS_WRAP_TARGET_FAIL     7
/*!<Wrapped target - no matching phase in other VCSEL period timing. */
#define VL53LX_RANGESTATUS_PROCESSING_FAIL      8
/*!<Internal algo underflow or overflow in lite ranging. */
#define VL53LX_RANGESTATUS_XTALK_SIGNAL_FAIL      9
/*!<Specific to lite ranging. */
#define VL53LX_RANGESTATUS_SYNCRONISATION_INT     10
/*!<1st interrupt when starting ranging in back to back mode. Ignore data. */
#define VL53LX_RANGESTATUS_RANGE_VALID_MERGED_PULSE   11
/*!<All Range ok but object is result of multiple pulses merging together.
 * Used by RQL for merged pulse detection */
#define VL53LX_RANGESTATUS_TARGET_PRESENT_LACK_OF_SIGNAL  12
/*!<Used  by RQL  as different to phase fail. */
#define VL53LX_RANGESTATUS_MIN_RANGE_FAIL     13
/*!<Unexpected error in SPAD Array.*/
#define VL53LX_RANGESTATUS_RANGE_INVALID      14
/*!<lld returned valid range but negative value ! */
#define  VL53LX_RANGESTATUS_NONE        255
#define DEV_I2C Wire
#define SerialPort Serial
#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif
#define LedPin LED_BUILTIN
#define interruptPin A2
#define LOCAL_UDP_PORT 1337     //Any port as long as the firewall is fine with it
#define REMOTE_UDP_PORT 1337    //Probably should be the same as local
#define PAYLOAD_LEN 1
#define ID '0'

const IPAddress REMOTE_IP(10, 104, 130, 255);

// WiFi Credentials
const char SSID[] = "EagleNet";
const char PASSWORD[] = "cY4DoKPo";
// Arbitrary name
const char HOST_NAME[] = "NetworkStation1";
IPAddress remoteIp;

WiFiUDP Udp;
char incomingPacket[256];  // buffer for incoming packets

void sendPacket(char packetData[]);
void check_for_signal()

VL53LX sensor_vl53lx_sat(&DEV_I2C, A1);
volatile int interruptCount=0;

bool start = True;

Servo servo1;
Servo servo2;
int servoPos1 = 25;
int servoPos2 = 90;

static bool b_receive = false;
const uint8_t u8_length = 128;
char ac_input[u8_length] = {0};
uint8_t u8_receivedPackets;

long time
static const int servoPin1 = A4;
static const int servoPin2 = A3;
int i,j = 0;
int lineDegreex[15] = {155,146,137,128,119,110,101,92,83,74,65,56,47,38,29};
int lineDegreey[4] = {25,35,45,55};
int distancemm = 0;
