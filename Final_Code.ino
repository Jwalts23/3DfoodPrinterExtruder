
//Setup for Stepper Motor
    //Call Arduino Stepper Motor library
    #include <Stepper.h> 
    //Define Number of steps per output rotation. From datasheet.
    const int stepsPerRevolution = 200; 
    //Create instance of Stepper Library
    //Pins used: 8,9,10,11
    Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
    
//Set Up for UltraSonic Sensor
   //Define pins for Ultrasonic Sensor
     int trigpin=6;
     int echopin=5;
     
//Define states of movement for State Machine
  enum State{
  Extrude,
  Retract,
  Stop,
  };
    State state;
  float duration, distance_cm;

//Setup for Humidity Sensor 
  //Initiate library and call data for library functions
    #include "DHT.h"
    #define DHTPIN 2
    #define DHTTYPE DHT11
    DHT dht(DHTPIN,DHTTYPE);
  //Initialize global variables
    int humi;
    int tempC;


void setup(){
    //Set rpm for Stepper Motor
    myStepper.setSpeed(35);
    
    //Set pin modes for ultrasonic sensor
      pinMode(trigpin, OUTPUT); //Set trigpin to output
      pinMode(echopin, INPUT); //Set echopin as input
    //Define Inital State of the State Machine
         state=Extrude;
    
    //initialize the Serial Monitor for humidity sensor data
    //distnace lines do not need to print to serial at all times
    //only active for distance fine-tuning
    Serial.begin(9600);
    dht.begin(); //initializes the humidity sensor
}

void loop(){
  //Print collected Humidity data to Serial Monitor
    Humidity();
    Serial.print("Humidity ");
    Serial.print(humi);
    Serial.println("%");

  //Print collected Temperature data to Serial Monitor
    Serial.print("Temperature ");
    Serial.print(tempC);
    Serial.println("°C");

  //Break up the data
    Serial.println();

//Generate State Machine Operations
  switch(state){
    case Extrude: //first state, when sensing distance is less than X, drive up
      myStepper.step(stepsPerRevolution);
      if(Distance()>17){
        state=Retract; //When distance excedes X, move to next state
      }
      break;
    case Retract: //Second State, once exceded X distnace, drive downward
     myStepper.step(-stepsPerRevolution);
     if(Distance()<=8){
      state=Stop; //When distnace equals Y, move to next state
     }
     break;
    case Stop:
      myStepper.step(0); //When distance equals Y, end program
      break;
  }   
}

float Distance(){
  //Code for gathering distance data
  //Sends 10 microsend pulse
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigpin,LOW);

  //Read echopin, return sound wave travel time
    duration=pulseIn(echopin,HIGH);

  //Calcualte distance in cm
    distance_cm=0.017*duration;

  //Relay data to Serial Monitor
    Serial.print("distnace");
    Serial.print(distance_cm);
    Serial.println("cm");

    return distance_cm;
}

void Humidity(){
  //Sensor reads Humidity
    humi=dht.readHumidity();

  //Have temperature read in C
   tempC=dht.readTemperature();

}
