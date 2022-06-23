#include <Ultrasonic.h>

Ultrasonic::Ultrasonic(){

}

void Ultrasonic::init(){
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input 
}

float Ultrasonic::calcDistance(){

    // speed of sound = 343 m/s
    // or 0.343 m/us
    // d = (time to recieve ping back * speed of sound) / 2

    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.0343 / 2.0;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);


    return distance;
}