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
    ADC_result = (ADC_result_raw / 1023.0) * 5.0;
    distance = pow((10.743 / ADC_result), (1.0 / 0.695));
    return distance;
}

