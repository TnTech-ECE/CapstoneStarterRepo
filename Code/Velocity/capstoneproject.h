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

VL53LX sensor_vl53lx_sat(&DEV_I2C, A1);
volatile int interruptCount=0;

Servo servo1;
Servo servo2;
long time
static const int servoPin1 = 13;
static const int servoPin2 = 14;
int i,j = 0;
int lineDegreex[15];
int lineDegreey[15];
int distancemm = 0;
int servoPos1 = 30;
int servoPos2 = 90;