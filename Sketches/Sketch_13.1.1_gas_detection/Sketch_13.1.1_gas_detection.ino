/*
  Sketch_13.1.1_gas_detection
  
  modified 2016/6/5
  by http://www.freenove.com
*/
#define sensorPin A0 //define the pin for sensor
int buzzerPin = 8;// define the pin for buzzer
int gasThreshold = 700;// Define a threshold. When the sensor data is higher than it, buzzer starts alarm.
void setup() {
  pinMode(buzzerPin, OUTPUT); // set buzzer pin to output mode
  Serial.begin(9600);//Configure the serial port
}

void loop() {
  int reading = analogRead(sensorPin);// read the voltage of sensor
  Serial.print("Sensor ADC Value: ");// print ADC value of sensor
  Serial.println(reading);
  if (reading > gasThreshold) { // If the gas detected is too dense, the buzzer starts salarms.
    alert(); //alarm
  }
  else
    noTone(buzzerPin);//stop to alarm
}
void alert() {
  float sinVal;         //define a variable to save the sine value
  int toneVal;          //define a variable to save the sound frequency
  for (int x = 0; x < 360; x++) {       // x is from 0°to 360°
    sinVal = sin(x * (PI / 180));       //calculat sine value of x
    toneVal = 2000 + sinVal * 500;     //calculat sound frequency according to sine value of x
    tone(buzzerPin, toneVal);       //buzzerPin output sound frequency to buzzerPin
    delay(1);
  }
}

