#ifndef GYRO_H_
#define GYRO_H_

#include <Arduino.h>
#include <Wire.h>
#include <math.h>
#include <Core.h>
#include <SparkFunLSM9DS1.h>
#include <Gyro.h>


#define LSM9DS1_M   0x1E // Would be 0x1C if SDO_M is LOW
#define LSM9DS1_AG  0x6B // Would be 0x6A if SDO_AG is LOW
// SDO_XM and SDO_G are both pulled high, so our addresses are:


void compassInit();
float magCalibrate();
float magRead();
float getAverage();
#endif