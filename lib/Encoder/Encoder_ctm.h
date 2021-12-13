#ifndef ENCODER_CTM_H_
#define ENCODER_CTM_H_

#include <Encoder_ctm.h>
#include <Encoder.h>
#include <Core.h>


class EncoderData {
    public:
        long ticksmoved=0;
        unsigned long currentpulsetime=0.0;
        unsigned long previoustime=0;
        EncoderData();  
        double calcRPM();
        void updateEncoder();
        volatile long encoderValue;
};




#endif