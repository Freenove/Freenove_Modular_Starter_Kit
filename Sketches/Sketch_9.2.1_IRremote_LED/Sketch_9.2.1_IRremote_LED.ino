/*
  Sketch_9.2.1_IRremote_LED
  
  modified 2016/6/5
  by http://www.freenove.com
*/
#include <IRremote.h> // include library file
int RECV_PIN = 11;// define infrared receiving pin
int ledPin = 13;// define LED pin
boolean ledState = false;// define the LED state
IRrecv irrecv(RECV_PIN);// Create a object for receiver class
decode_results results;// Create a object for decoding result class
void setup()
{
  pinMode(ledPin, OUTPUT);// set ledPin to output mode
  digitalWrite(ledPin, ledState);// update the original LED sate
  Serial.begin(9600);// Configure serial port
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  //wait for decoding
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);// print out decoding result
    if (results.value == 0xFF6897) {// if "0"is pressed, chang the LED state.
      ledState = !ledState;//reverse the state
      digitalWrite(ledPin, ledState);//update the LED state
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

