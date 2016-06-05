/*
  Sketch_12.1.1_flame_detection
  
  modified 2016/6/5
  by http://www.freenove.com
*/
#define sensorPin A0 // define the sensor pin
int buzzerPin = 8;// define the buzzer pin 
int flameThreshold = 500;// Define a threshold, when the sensor data is below it, the buzzer alarms.
void setup() {
  pinMode(buzzerPin, OUTPUT); // set buzzer pin to output mode 
  Serial.begin(9600);//configure serial port
}

void loop() {
  int reading = analogRead(sensorPin);// read voltage of sensor
  Serial.print("Sensor ADC Value: ");// print ADC value of the sensor
  Serial.println(reading);
  if (reading < flameThreshold) { // if thesensor detects theflame， the buzzer will alarm。
    alert(); //alarm
  }
  else
    noTone(buzzerPin);// stop alarming
}
void alert() {
  float sinVal;         // Define a variable to save the sine value
  int toneVal;          // Define a variable to save the sound frequency
  for (int x = 0; x < 360; x++) {       // xfrom 0°to 360°
    sinVal = sin(x * (PI / 180));       // calculat sine value of x
    toneVal = 2000 + sinVal * 500;      // calculate the sound frequency according to the sine value of X
    tone(buzzerPin, toneVal);           // output sound frequency to buzzerPin
    delay(1);
  }
}

