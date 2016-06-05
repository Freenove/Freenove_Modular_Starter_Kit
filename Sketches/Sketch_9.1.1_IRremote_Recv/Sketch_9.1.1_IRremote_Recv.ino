/*
  Sketch_9.1.1_IRremote_Recv
  
  modified 2016/6/5
  by http://www.freenove.com
*/
#include <IRremote.h> // Include library file
int RECV_PIN = 11;// Infrared receiving pin
IRrecv irrecv(RECV_PIN);// Create a class object used to receive class
decode_results results;// Create a decoding results class object
void setup()
{
  Serial.begin(9600);// Configurate serial port
  irrecv.enableIRIn(); // Start the receiver
}
void loop() {
  // Waiting for decoding
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);// Print out the decoding results
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

