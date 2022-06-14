#include "math.h"
#include <Arduino.h>

class Filters{
    public:
        Filters(void);
        float avg(float newVal, int measurementsToAvg);
        float movingAvg(float newVal, int runAvgCount);
        float exponential(float newVal);

        float avgDistance;
    private:
        int k = 0;
        float avg1;
        // running avg variables
        float runAvg;
        long runAvgSum;
        // int nextRunAvg;
        bool firstTime = true;

        


};