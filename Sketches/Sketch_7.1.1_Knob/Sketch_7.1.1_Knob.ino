/*
  Sketch_7.1.1_Knob
  
  modified 2016/6/5
  by http://www.freenove.com
*/
#include <Servo.h>

Servo myservo;              // create servo object to control a servo

int servoPin = 8;           // define the pin of servo signal line 
int potPin = A0;             // analog pin used to connect the potentiometer
int potVal;                 // variable to read the potValue from the analog pin

void setup() {
  myservo.attach(servoPin); // attaches the servo on servoPin to the servo object
}

void loop() {
  potVal = analogRead(potPin);          // reads the potValue of the potentiometer
  potVal = map(potVal, 0, 1023, 0, 180);// scale it to use it with the servo
  myservo.write(potVal);                // sets the servo position
  delay(15);                            // waits for the servo to get there
}

