#include <Arduino.h>
#include <math.h>
#include <Motor.h>
#include <Core.h>
#include <Encoder_ctm.h>

/**
 * Constructor
 * in1 = 1st input pin
 * in2 = 2nd input pin
 * pwm = speed pin
 * speeddiff = what should be added or subtracted to make the motor function properly 
 * (defaults to 0 if not specified)
 */

Motor::Motor(int in1, int in2, int pwm, float speeddiff) {
    Motor::in1 = in1;
    Motor::in2 = in2;
    Motor::pwm = pwm;
    Motor::speeddiff = speeddiff;
}
Motor::Motor(int in1, int in2, int pwm) {
    Motor::in1 = in1;
    Motor::in2 = in2;
    Motor::pwm = pwm;
    Motor::speeddiff = 0;
}

/**
 * Must be called in the setup() method.
 * Sets the correct pinMode for the pins used.
 */

void Motor::setup() {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(pwm, OUTPUT);
    pinMode(enc1, OUTPUT);
    pinMode(enc2, OUTPUT);
}

// Just for testing purposes
void Motor::test() {
    debug(String(in1));
    debug(String(in2));
    debug(String(pwm));
}

/**
 * Move method. Makes the motor spin at given speed (-255 - 255) 
 * applies a speed differential if set, otherwise 
 * 
*/

void Motor::move(float speed) {
    if(speed < -255 || speed > 255) {
        // normally I'd do an exception but arduino doesnt support that.
        return;
    }
    if(speed < 0) { 
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(pwm, abs(speed));
    } else {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        analogWrite(pwm, abs(speed + speeddiff));
    }   
}


/**
 * Default Motor movements.
 * 
 */

MotorControl::MotorControl(Motor m1, Motor m2, Motor m3) {
    MotorControl::m1 = m1;
    MotorControl::m2 = m2;
    MotorControl::m3 = m3;
}


/**
 * Simple functions for motor-movement 
 * Forward, Backward, Left-Turn, Right-Turn
 */


void MotorControl::forward(float time, float speed) {
    m2.move(speed);
    m3.move(speed*-1);
    delay(time);
    m2.move(0);
    m3.move(0);
}

void MotorControl::backward(float time, float speed) {
    m2.move(speed*-1);
    m3.move(speed);
    delay(time);
    m2.move(0);
    m3.move(0);
}

void MotorControl::move(double degrees, int baseSpeed) {
    float pi = 57.29577951;
    float speedM1 = -(baseSpeed) * sin((degrees + 180) / pi);
    float speedM2 = -(baseSpeed) * sin((degrees + 60) / pi);
    float speedM3 = -(baseSpeed) * sin((degrees - 60) / pi);
    m1.move(speedM1);
    m2.move(speedM2);
    m3.move(speedM3);
    m1.test();
    m2.test();
    m3.test();
}