/*
  Sketch_2.2.1_Breathing_LED
  
  modified 2016/6/5
  by http://www.freenove.com
*/
// set pin numbers:
int ledPin = 9;             // the number of the LED pin

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Call breath() function circularly
  breath(ledPin, 6);
  delay(500);
}

void breath(int ledPin, int delayMs) {
  for (int i = 0; i <= 255; i++) {  // “i” (number of cycles) is from 0 to 255
analogWrite(ledPin, i);         // i from 0 to 255 is consistent with duty ratio from 0% to 100%
    delay(delayMs);                 // Adjust change rate of LED brightness 
  }
  for (int i = 255; i >= 0; i--) {  // “i” (number of cycles) is from 255 to 0
analogWrite(ledPin, i);     // i from 0 to 255 is consistent with duty ratio from 0% to 100%
    delay(delayMs);          // Adjust change rate of LED brightness
  }
}

