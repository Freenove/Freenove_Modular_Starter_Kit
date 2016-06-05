/*
  Sketch_3.1.1_adjustable_LED
  
  modified 2016/6/5
  by http://www.freenove.com
*/
int adcValue;     // Define a variable to save the ADC value
int ledPin = 9;   // the number of the LED pin

void setup() {
  pinMode(ledPin, OUTPUT);             // initialize the LED pin as output
}

void loop() {
  adcValue = analogRead(A0);          // Convert analog of A0 port to digital
  // Map the converted digital to the range 0-255 as the PWM duty cycle of ledPin port
  analogWrite(ledPin, map(adcValue, 0, 1023, 0, 255));
}

