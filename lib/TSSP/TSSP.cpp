#include <Arduino.h>
#include <TSSP.h>
#include <Core.h>

TSSP::TSSP(short pin, short tsspNumber) {
    TSSP::pin = pin;
    TSSP::tsspnumber = tsspNumber;
}


void TSSP::initTSSP() {
    pinMode(pin, INPUT);
}

short TSSP::getCurValue() {
    short value = analogRead(pin);
    short valueMapped = map(value, 0, 1024, 1024, 0);
    lastValue = valueMapped;
    return valueMapped;
}

short TSSP::getPin() {
    return tsspnumber;
}

// TSSP T1 (A0);
// TSSP T2 (A1);
// TSSP T3 (A2);
// TSSP T4 (A3);
// TSSP T5 (A4);
// TSSP T6 (A5);
// TSSP T7 (A6);
// TSSP T8 (A7);
// TSSP T9 (A8);
// TSSP T10 (A9);
// TSSP T11 (A10);
// TSSP T12 (A11);

TSSP ir[] = {TSSP(A0, 0), TSSP(A1, 1), TSSP(A2, 2), TSSP(A3, 3), TSSP(A4, 4), TSSP(A5, 5), TSSP(A6, 6), TSSP(A7, 7), TSSP(A8, 8), TSSP(A9, 9), TSSP(A10, 10), TSSP(A11, 11)};
short prevVal = 0;

void initTSSP() {
    for(TSSP tssp : ir) {
        tssp.initTSSP();
    }
}




short getBallDir(short x) {
    short highestVal = 1;
    
    TSSP highestTSSP = TSSP(69, 100);
    for(TSSP tssp : ir) {
        if(tssp.getCurValue() > highestVal) {
            highestVal = tssp.getCurValue();
            highestTSSP = tssp;
        }
    }
    // TODO: Refine this system and make sure all the returned values are efficient and funcitonal.
//     switch (highestTSSP.getPin())
//     {   
//         case 0: {
//             return 0;
//         }
//         case 1: {
//             return 90;
//         }
//         case 2: {
//             return 120;
//         }
//         case 3: {
//             return 150;
//         }
//         case 4: {
//             return 180;
//         }
//         case 5: {
//             return 210;
//         }
//         case 6: {
//             return 120;
//         }
//         case 7: {
//             return 150;
//         }
//         case 8: {
//             return 270;
//         }
//         case 9: {
//             return 210;
//         }
//         case 10: {
//             return 240;
//         }
//         case 11: {
//             return 270;
//         }
//     default:
//         return (highestTSSP.getPin() * 30);
//     }
    return highestTSSP.getPin();
}
x