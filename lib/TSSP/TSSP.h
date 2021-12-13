#ifndef TSSP_H_
#define TSSP_H_

#include <TSSP.h>
#include <Arduino.h>
#include <Core.h>

#define DATAPIN 4

class TSSP {
    private:
        short pin = 0;
        short tsspnumber = 0;
    public:
        TSSP(short pin, short tsspNumber);
        short lastValue;
        short getCurValue();
        void initTSSP();
        short getPin();

};

void initTSSP();
short getBallDir(short x);

#endif