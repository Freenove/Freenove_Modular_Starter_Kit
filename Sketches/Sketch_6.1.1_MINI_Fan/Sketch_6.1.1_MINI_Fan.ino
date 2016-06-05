/*
  Sketch_6.1.1_MINI_Fan
  
  modified 2016/6/5
  by http://www.freenove.com
*/
int relayPin = 12;     // the number of the relay pin
int buttonPin = 8;   // the number of the push button pin

int buttonState = HIGH; // Record state of the button, the initial state is high level
int relayState = LOW;   // Record state of the relay, the initial state is low level
int lastButtonState = HIGH; // Record the last button state
long lastChangeTime = 0;    // Record time point of state change

void setup() {
  pinMode(buttonPin, INPUT);  // Set Push Button pin to input mode
  pinMode(relayPin, OUTPUT);  // Set Relay pin to output mode
  digitalWrite(relayPin, relayState); // Set initial state of the relay to “close”
}

void loop() {
  int nowButtonState = digitalRead(buttonPin);// Read the current state of the button pin
  // If the button pin state changes, record the time point
  if (nowButtonState != lastButtonState) {
    lastChangeTime = millis();
  }
  // If the state of button has been stable for some time after changing, then we think it has skiped the buffeting period.
  if (millis() - lastChangeTime > 10) {
    if (buttonState != nowButtonState) {  // Confirm that the state of button has changed.
      buttonState = nowButtonState;
      if (buttonState == LOW) {     // If buttonState is low, the button is pressed.
        relayState = !relayState;           // Reverse the state of relay
        digitalWrite(relayPin, relayState); // Update the state of relay
      }
    }
  }
  lastButtonState = nowButtonState; // Save the last state of the button
}

