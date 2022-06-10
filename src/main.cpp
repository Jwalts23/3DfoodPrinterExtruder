#include <Arduino.h>
#include <IrSensor.h>

//Define states of movement for State Machine
  enum State{
    Start,
    Extrude,
    Retract,
    Stop,
  };
  State state;

void cycleOnce(){
  switch(state){
    case Start:
    {

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
  Serial.println("hello");
  cycleOnce();
}

