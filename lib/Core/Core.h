#ifndef CORE_H_
#define CORE_H_

#include <Arduino.h>
#include <Core.h>


void setupCore();
void debug(String msg);
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max);



#endif