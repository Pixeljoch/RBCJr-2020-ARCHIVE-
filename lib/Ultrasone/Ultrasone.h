#define _Ultrasone_H_
#ifdef _Ultrasone_H_

#include <Ultrasone.h>


class Ultrasone {
    private:
        int trigPin, echoPin;
    public:
        Ultrasone(int trigPin, int echoPin);
        short getDistance();
        void setup();

}

#endif}

#endif