#include "Filters.h"

Filters::Filters(){

}

float Filters::avg(float newVal, int measurementsToAvg){
    
    if (k <= measurementsToAvg) {
        avgDistance += newVal;
        k++;
        avg1 = -1;
    }

    if (k == measurementsToAvg){
        avg1 = avgDistance / (float)measurementsToAvg;
        k = 0;
        avgDistance = 0.0; 
        // Serial.println(avg1);
    }
    return avg1;
}

float Filters::movingAvg(float newVal, int runAvgCount){
    // highest count that will work is 6
    float runAvgBuffer[runAvgCount];

    if (k==0){     
        runAvg = 0;
        // Serial.println("HERE");

    }

    if(k < runAvgCount) {
        runAvgBuffer[k]= newVal;
    }

    if (!firstTime) {
        runAvgSum = 0;
        for (int l=0; l<runAvgCount; l++){
            runAvgSum += runAvgBuffer[l];
        }

        Serial.print("k ");
        Serial.println(k);
        runAvg = runAvgSum/ (float) runAvgCount;
        Serial.print("run avg ");
        Serial.println(runAvg);
        

    }
    k++;
    if(k == runAvgCount) {
        firstTime = false;
        k=0;
    }

    return runAvg;
}

float Filters::exponential(float newval){

    return 1.1;
}

