/*
  Sketch_1.3.1_MINI_tableLamp

  modified 2016/6/5
  by http://www.freenove.com
*/
int ledPin = 13;//Define the pin of LED
int buttonPin = 8;//Define the pin of button 
int ledState = LOW;//Record the state of LED; the initial state is OFF
int buttonState = HIGH;// Record the state of botton; the initial state is HIGH
int lastButtonState = HIGH;//Record the last state of button
long lastChangeTime = 0;// record time point of state chang
long captureTime = 50;// set the time needed to get stable state
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPin, ledState);// Set the initial state of LED
}
void loop() {
  int reading = digitalRead(buttonPin);// Read the current state of button
  if (reading != lastButtonState) {
// If the button state has changed, record the time point.
    lastChangeTime = millis();
  }
  // If changing-state of the button last beyond the time we set, we considered that the current button state is an effective change rather than a buffeting.
  if (millis() - lastChangeTime > captureTime) {
    // Determine if the state is changed. If it is, update and save the state of button.
    if (reading != buttonState) {
      buttonState = reading;
 // If the state is high, the action is pressing. If it is low, the action is releasing.
      if (buttonState == LOW) {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(ledPin, ledState);// In each cycle, the state of the LED will be updated.
  lastButtonState = reading;// Update the last Button State ,and then start the next round of reading.
}
