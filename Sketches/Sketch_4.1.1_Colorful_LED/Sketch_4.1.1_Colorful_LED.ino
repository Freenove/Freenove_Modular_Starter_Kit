/*
  Sketch_4.1.1_Colorful_LED
  
  modified 2016/6/5
  by http://www.freenove.com
*/
// set pin numbers:
int ledPinR = 9;   // the number of the LED R pin
int ledPinG = 10;   // the number of the LED G pin
int ledPinB = 11;    // the number of the LED B pin

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);
}

void loop() {
//Generates 3 random numbers between 0-255 as 3 duty cycles of the PWM outputed by ledPin.
  rgbLedDisplay(random(256), random(256), random(256));
  delay(500);
}

void rgbLedDisplay(int red, int green, int blue) {
  // set 3 duty cycles of the PWM outputed by ledPin.
  analogWrite(ledPinR, constrain(red, 0, 255));
  analogWrite(ledPinG, constrain(green, 0, 255));
  analogWrite(ledPinB, constrain(blue, 0, 255));
}

