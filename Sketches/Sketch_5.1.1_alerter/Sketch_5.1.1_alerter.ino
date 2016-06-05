/*
  Sketch_5.1.1_alerter
  
  modified 2016/6/5
  by http://www.freenove.com
*/
int buttonPin = 8;   // the number of the push button pin
int buzzerPin = 11;    // the number of the buzzer pin
float sinVal;         // Define a variable to save the sine value
int toneVal;          // Define a variable to save the sound frequency

void setup() {
  pinMode(buttonPin, INPUT);  // Set Push Button pin to input mode
  pinMode(buzzerPin, OUTPUT); // Set Buzzer pin to output mode
}

void loop() {
  if (digitalRead(buttonPin) == LOW)// when the buttonPin is low, the button is pressed.
    alert();//start to alarm
  else                    // when the buttonPin is high, the button is not pressed.
    noTone (buzzerPin);    // turn off Buzzer
}
void alert() {
  for (int x = 0; x < 360; x++) {    // X from 0 degree->360 degree
    sinVal = sin(x * (PI / 180));    // Calculate the sine of x
    toneVal = 2000 + sinVal * 500;   // Calculate sound frequency according to the sine of x
    tone(buzzerPin, toneVal);        // Output sound frequency to buzzerPin
    delay(1);
  }
}

