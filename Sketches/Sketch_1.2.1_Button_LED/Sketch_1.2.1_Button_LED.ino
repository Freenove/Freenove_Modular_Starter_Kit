/*
  Sketch_1.2.1_Button_LED

  modified 2016/6/5
  by http://www.freenove.com
*/
int buttonPin = 8; // The number of the push button pin
int ledPin = 13;     // The number of the LED pin

void setup() {
  pinMode(buttonPin, INPUT);  // Set Push Button pin to input mode
  pinMode(ledPin, OUTPUT);    // Set LED pin to output mode
}

void loop() {
  if(digitalRead(buttonPin) == LOW)//If ButtonPin is low ，the button is pressed.
    digitalWrite(ledPin, HIGH);        // Turn LED on
  else                            //If ButtonPin is high，the button is not pressed.
    digitalWrite(ledPin, LOW);        // Turn LED off
}

