/*
  Sketch_14.1.1_hygrothermograph
  
  modified 2016/6/5
  by http://www.freenove.com
*/
#include <LiquidCrystal_I2C.h> // include header file of I2C LCD1602
#include <dht.h> // include DHT library file
dht DHT;// create DHT object
#define DHT11_PIN 8 // define pin for sensor
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
void setup()
{
  lcd.init();  // initialize LCD
  lcd.backlight();//Turn on LCD backlight
}
void loop()
{
  int chk = DHT.read11(DHT11_PIN); // read DHT11 and judge the state according to the return value 
  lcd.setCursor(0, 0); // Set cursor (0,0)
  lcd.clear();        // clear all contents on LCD
  switch (chk)
  {
    case DHTLIB_OK:// if DHT state is OK, print temperature and humidity data
      lcd.print("H:");
      lcd.print(DHT.humidity);// display humidity data
      lcd.print("%");
      lcd.setCursor(0, 1);
      lcd.print("T:");
      lcd.print(DHT.temperature);// display temperature data
      lcd.print("C");
      lcd.setCursor(14, 0);
      lcd.print("OK");
      break;
    case DHTLIB_ERROR_CHECKSUM:// data verification and error
      lcd.print("Checksum error");
      break;
    case DHTLIB_ERROR_TIMEOUT:// connection timeouts
      lcd.print("Time out error");
      break;
    default:// other erro
      lcd.print("Unknown error");
      break;
  }
  delay(1000);
}

