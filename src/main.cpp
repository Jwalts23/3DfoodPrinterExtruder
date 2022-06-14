#include <Arduino.h>
#include <IrSensor.h>
#include <Filters.h>
#include <math.h>

//Define states of movement for State Machine
  enum State{
    Start,
    Extrude,
    Retract,
    Stop,
  };
  State state = Start;
  float d;


  IrSensor irSensor;
  Filters filter;
  float avg;
  float runAvg;
  int count = 6;
  int j = 0;
  int ana;
  float V;


void cycleOnce(){
  switch(state){
    case Start:
    { 
      if (j>=200){
        
      }

      else{
      ana = analogRead(A0);
      V = 5.0/1023.0 * (float) ana; 
      Serial.print(ana);
      Serial.print("  ");
      Serial.println(V);
      j++;
      delay(50);
      // d = irSensor.CalcDistance();
      // Serial.println(d);
      // avg = filter.avg(d, count);
      // runAvg = filter.movingAvg(d, count);
      // Serial.println(roundToHun(runAvg));
      }

       

      
    }

    case Extrude:
    {

    }

    case Retract:
    {

    }

    case Stop:
    {

    }
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println("hello");
  cycleOnce();
}

