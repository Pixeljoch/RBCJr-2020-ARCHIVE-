#include <Arduino.h>
#include <Core.h>

void setupCore() {
    Serial.begin(115200);
}

void debug(String msg) {
    Serial.println("Debug >>> " + msg);
}

float mapFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}