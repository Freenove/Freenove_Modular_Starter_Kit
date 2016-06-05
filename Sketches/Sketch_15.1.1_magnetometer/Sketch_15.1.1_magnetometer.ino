/*
  Sketch_15.1.1_magnetometer
  
  modified 2016/6/5
  by http://www.freenove.com
*/
#define sensorPin A0 // define the pin for sensor
const float zeroVolt=2.5;// Set the voltage (affected by temperature, magnetic field and other factors) in the static state.
float B, sVolt;// define two variables to save magnetic induction intensity and output voltage
void setup() {
  Serial.begin(9600);
}
void loop() {
  int reading = analogRead(A0);// read sensor voltage and convert it to digital
  sVolt = (float)reading / 1023 * 5;// calculate output voltage of the sensor
  B = (sVolt - zeroVolt) / 1.8 * 1000;// calculate the magnetic induction intensity according to zero-point voltage(when magnetic intensity is zero) and sensitivity
  // display contents above in the serial port
  Serial.print("sVolt:"); Serial.print(sVolt); Serial.print("V\t");
  Serial.print("B:"); Serial.print(B); Serial.print("G\t"); Serial.println();
  delay(100);
}

