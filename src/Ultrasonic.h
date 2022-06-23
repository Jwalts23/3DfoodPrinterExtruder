#include <Arduino.h>

class Ultrasonic{
    public:
        Ultrasonic(void);
        float calcDistance(void);
        void init(void);

        float avgDistance;
    private:
        int trigPin = 9;
        int echoPin = 10;
        long duration;
        float distance;

        


};