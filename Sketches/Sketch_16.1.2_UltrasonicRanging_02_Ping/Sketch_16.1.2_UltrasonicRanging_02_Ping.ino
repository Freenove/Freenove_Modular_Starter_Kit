/*
  Sketch_16.1.2_UltrasonicRanging_02_Ping
  
  modified 2016/6/5
  by http://www.freenove.com
*/
#include <NewPing.h>
#define trigPin  12  // define TrigPin
#define echoPin     11  // define EchoPin.
#define MAX_DISTANCE 200 //  Maximum sensor distance is rated at 400-500cm.

NewPing sonar(trigPin, echoPin, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}

