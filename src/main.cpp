#include <Arduino.h>
#include <IrSensor.h>

//Define states of movement for State Machine
  enum State{
    Start,
    Extrude,
    Retract,
    Stop,
  };
  State state = Start;
  float d;
  int i = 0;

  IrSensor irSensor;

void cycleOnce(){
  switch(state){
    case Start:
    {
      d = irSensor.CalcDistance();
      if (i>100){
        Serial.println(d);
        i=0;
      }
      i++;
      
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
  Serial.begin(9200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println("hello");
  cycleOnce();
}

