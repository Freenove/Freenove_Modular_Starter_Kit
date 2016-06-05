/*
  Sketch_11.1.1_sound_Lamp
  
  modified 2016/6/5
  by http://www.freenove.com
*/
#define sensorPin A0// define input pin for sensor
int ledPin = 12;// define pin for LED
unsigned long updateTime;// Define a variable to save the time point for collection of sound
unsigned long durationTime = 3000;//define the duration after collection of sound

void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  if (analogRead(sensorPin) > 600) {// If the sound is loud enough, update the collection time point, and turn LED on.
    updateTime = millis();
    digitalWrite(ledPin, HIGH);
  }
  if ((millis() - updateTime) > durationTime) {//if the duration is over, turn LED off.
    digitalWrite(ledPin, LOW);
  }
}

