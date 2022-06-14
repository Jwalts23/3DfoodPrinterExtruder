#include "IrSensor.h"
#include "math.h"
#include <Arduino.h>

IrSensor::IrSensor(){

}

void IrSensor::Init(){

}

float IrSensor::CalcDistance(){
    float distance;
    float ADC_result_raw = 0.0;
    float ADC_result = 0.0;
    ADC_result_raw = analogRead(A0);
    ADC_result = (ADC_result_raw / 1024.0) * 5.0;
    distance = pow((11.829 / ADC_result), (1.0 / 0.775));
    // if (errorIR > 0 || errorIR < 0)
    // {
    //     effortIR = kpIR * errorIR + kdIR * (curEffortIR - prevEffortIR);
    // }
    // else
    // {
    //     effortIR = 0.0;
    // }
    // prevEffortIR = curEffortIR;
    // return effortIR;
    return distance;
}

