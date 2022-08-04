#include <Arduino.h>
#include <IrSensor.h>
#include <Filters.h>
#include <math.h>
#include <Stepper.h>
#include <Ultrasonic.h>

//Define states of movement for State Machine
  enum State{
    Start,
    Extrude,
    Retract,
    Stop,
  };
  State state = Extrude;
  float d;

  const int stepsPerRevolution = 200; 
  //Create instance of Stepper Library
  //Pins used: 8,9,10,11
  Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

  IrSensor irSensor;
  Filters filter;
  Ultrasonic ultra;

  float avg;
  float runAvg;
  int count = 5;
  int j = 0;
  int k = 0;
  int ana;
  float V;


void cycleOnce(){
  // d = irSensor.CalcDistance();
  // Serial.println(d);
  switch(state){
    case Start:


      // d = irSensor.CalcDistance();
      // Serial.println(d);
      // // Serial.print("  ");
      //  delay(5);
      // avg = filter.avg(d, count);
      // runAvg = filter.movingAvg(d, count);
      // Serial.println(roundToHun(runAvg));
    break;

    case Extrude:
      myStepper.step(stepsPerRevolution);
      j++;
      Serial.println ("extrude");
      // if (irSensor.CalcDistance() <=23) {
      if (j>5){
        // state=Stop;
        Serial.println ("stopped");
        state=Retract; //When distance excedes X, move to next state
        j=0;
      }
    break;

    case Retract:
      myStepper.step(-stepsPerRevolution);
      k++;
      Serial.println ("retract");
      // if (irSensor.CalcDistance() >28){
      if (k>5){  
        state=Stop;
        k=0;
      }
    break;

    case Stop:
      Serial.println ("stop");
      myStepper.step(0);
      delay(10000);
    break;
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Set rpm for Stepper Motor
  myStepper.setSpeed(35);
  ultra.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println("hello");
  // d = irSensor.CalcDistance();
  // Serial.println(d);
  // cycleOnce();
  // ultra.calcDistance();
  Serial.println ("i start");
  for (int i=1; i<=5; i++){
    for(int k=1; k<=i; k++){
      myStepper.step(-1);
        delay(700);
    }
    
    Serial.print ("i stepped ");
    Serial.println (i);
    delay(5000);
  }
  
}

