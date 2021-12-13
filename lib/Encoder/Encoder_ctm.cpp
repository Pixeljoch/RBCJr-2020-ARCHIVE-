#include <Arduino.h>
#include <Encoder_ctm.h>
#include <Core.h>

//The sample code for driving one way motor encoder

/**
 * Calculates the RPM based on the interrupts.
 *
 */

double EncoderData::calcRPM() {   
  if (currentpulsetime==0)
  {
    return 0;
  }
  return 60000/(((currentpulsetime)/1000.0)*562.215);
}


/**
 * Interrupt method example
 * 
 * 
 * void encoder3change() {
 * if (digitalRead(<ENCODER-B-PIN>)==LOW)
 * {
 *   <EncoderDataObject>.ticksmoved++;
 * }
 * else
 * {
 *   <EncoderDataObject>.ticksmoved--;
 * }
 * <EncoderDataObject>.currentpulsetime=micros()-<EncoderDataObject>.previoustime;
 * <EncoderDataObject>.previoustime=micros();
 * }
 * 
 */