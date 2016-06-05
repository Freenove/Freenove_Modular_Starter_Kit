/*
  Sketch_8.1.1_I2C_LCD1602
  
  modified 2016/6/5
  by http://www.freenove.com
*/
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
int counter = 0;
void setup()
{
  lcd.init();                      // initialize the lcd
  lcd.backlight();                // Turn on backlight
  startingAnimation();            // subfunction of Boot animation
}

void loop()
{
  lcd.setCursor(0, 1);  // Set the cursor to the first column and the second row
  lcd.print(counter);  // Print variable
  delay(1000);
  counter++;          // counter=counter+1
}
void startingAnimation() {
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayRight();   // shift the screen right 1 character
  }
  lcd.setCursor(0, 0);     // Set the cursor to the end of the first line.
  lcd.print("Freenove");
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();  // shift the screen left 1 character
    delay(300);
  }
}

