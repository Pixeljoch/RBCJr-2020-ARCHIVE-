#include <Arduino.h>
#include <Wire.h>
#include <Core.h>
#include <Motor.h>
#include <Encoder_ctm.h>
#include <Gyro.h>

// EncoderData datam2;
// EncoderData datam3;

 Motor m1 (2, 3, 4);
 Motor m2 (6, 7, 5);
 Motor m3 (8, 9, 10);

 TSSP T0 (A0);


//MotorControl control;

// void encoder2change() {
//   if (digitalRead(12)==LOW)
//   {
//     datam3.ticksmoved++;
//   }
//   else
//   {
//     datam3.ticksmoved--;
//   }
//   datam3.currentpulsetime=micros()-datam3.previoustime;-
//   datam3.previoustime=micros();
// }

// void encoder1change() {
//   if (digitalRead(11)==LOW)
//   {
//     datam2.ticksmoved++;
//   }
//   else
//   {
//     datam2.ticksmoved--;
//   }
//   datam2.currentpulsetime=micros()-datam2.previoustime;
//   datam2.previoustime=micros();
// }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(20, INPUT);
  pinMode(11, INPUT);
  pinMode(21, INPUT);
  pinMode(12, INPUT);
  // attachInterrupt(digitalPinToInterrupt(20), encoder1change, RISING);
  // attachInterrupt(digitalPinToInterrupt(21), encoder2change, RISING);

  m1.setup();
  m2.setup();
  m3.setup();
  //control = MotorControl(m1, m2, m3);
  gyroSetup();

  mpu.setXAccelOffset(1975);
motionTrackingDevice.setYAccelOffset(-1842);
motionTrackingDevice.setZAccelOffset(4667);
motionTrackingDevice.setXGyroOffset(99);
motionTrackingDevice.setYGyroOffset(18);
motionTrackingDevice.setZGyroOffset(-6);
  
}

int speed = 200;

void move(double degrees, int baseSpeed) {
    float pi = 57.29577951;
    float speedM1 = -(baseSpeed) * sin((degrees + 180) / pi);
    float speedM2 = -(baseSpeed) * sin((degrees - 60) / pi);
    float speedM3 = -(baseSpeed) * sin((degrees + 60) / pi);
    m1.move(speedM1);
    m2.move(speedM2);
    m3.move(speedM3);
    debug(String(speedM1));
    debug(String(speedM2));
    debug(String(speedM3));
}

void loop() {
  //   Serial.print("Motor 2: ");
  //   Serial.println(datam2.calcRPM());
  //   Serial.print("Motor 3: ");
  //   Serial.println(datam3.calcRPM());
  //  control.move(0, 255);
  updateAngle();
  // for(int i = 0; i < speed; i+=10) {
  //   m2.move(i);
  //   m3.move(i*-1);
  //   delay(100);
  // }
  // delay(500);
  // m1.move(-200);
  // m2.move(100);
  // m3.move(100);
  // delay(500);
  delay(200);

}


