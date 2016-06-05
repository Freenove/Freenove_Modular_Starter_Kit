/*
  Sketch_10.1.1_sense_Lamp
  
  modified 2016/6/5
  by http://www.freenove.com
*/
int ledPin = 12;// define pin for LED
int sensorPin = 8; // define input pin for the sensor
void setup() {
  pinMode(sensorPin, INPUT); // define input and output
  pinMode(ledPin, OUTPUT);
}
void loop() {
  if (digitalRead(sensorPin))// if sensorPin is in high level, turn LED on.
    digitalWrite(ledPin, HIGH);
  else//     turn off LED
    digitalWrite(ledPin, LOW);
}

