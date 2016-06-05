/*
  Sketch_1.1.1_Blink

  modified 2016/6/5
  by http://www.freenove.com
*/
int ledPin=13; //Connect LED to Pin13
void setup() {
  // initialize digital ledPin as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}

