#include <Arduino.h>
#include <Wire.h>
#include <math.h>
#include <Core.h>
#include <SparkFunLSM9DS1.h>
#include <Gyro.h>

LSM9DS1 sensor;
float averageMag = 0;

float magCalibrate() {
  // Define Integers
  int n, i;

  // Define floats
  float num[100], sum=0.0, average;

  // Define Zero Values
  n = 300;

  // Notify user of process
  Serial.println("Welcome. Calibrating Compass.");
  Serial.println("Do not rotate the robot. Leave it still on a flat surface.");

  for(i = 0; i < n; i++) {
    float val = magRead();
    Serial.print("Found Values: ");
    Serial.println(val);
    sum += val;
  }

  // Calculation work
  average = sum / n;

  // Notify user
  Serial.print("Found Average: ");
  Serial.println(average);

  // Beeper
  analogWrite(5, 50);
  delay(300);
  analogWrite(5, 200);
  delay(100);
  analogWrite(5, 0);
  return average;
}

void compassInit() {
  Wire.begin();
  if (sensor.begin() == false) // with no arguments, this uses default addresses (AG:0x6B, M:0x1E) and i2c port (Wire).
  {
    Serial.println("Failed to communicate with LSM9DS1.");
    Serial.println("Double-check wiring.");
    Serial.println("Default settings in this sketch will " \
                   "work for an out of the box LSM9DS1 " \
                   "Breakout, but may need to be modified " \
                   "if the board jumpers are.");
    while (1);
  }
  sensor.calibrate(false);
  sensor.settings.mag.scale = 16;
  sensor.settings.device.commInterface = IMU_MODE_I2C; // Set mode to I2C
  sensor.settings.device.mAddress = LSM9DS1_M; // Set mag address to 0x1E
  sensor.settings.device.agAddress = LSM9DS1_AG; // Set ag address to 0x6B
  averageMag = magCalibrate();
  
}

float magRead(){
  sensor.readMag();
  float heading;
  float my = -sensor.my;
  float mx = -sensor.mx;
  if (my == 0)
    heading = (mx < 0) ? PI : 0;
  else
    heading = atan2(mx, my);

  heading -= -8.58 * PI / 180;

  if (heading > PI) heading -= (2 * PI);
  else if (heading < -PI) heading += (2 * PI);

  // Convert everything from radians to degrees:
  heading *= 180.0 / PI;
  
  return heading;// - getAverage();
}

float getAverage()
 {
   return averageMag;
 }