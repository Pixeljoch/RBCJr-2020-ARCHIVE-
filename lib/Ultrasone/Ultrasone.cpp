#include <Arduino.h>
#include <Ultrasone.h>

Ultrasone::Ultrasone(int trigPin, int echoPin) {
    this.trigPin = trigPin;
    this.echoPin = echoPin;
}

void Ultrasone::setup() {
     
}

short Ultrasone::getDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    long duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    return duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
}