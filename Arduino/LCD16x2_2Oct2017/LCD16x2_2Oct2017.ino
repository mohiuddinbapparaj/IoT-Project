/*
  LiquidCrystal Library - display() and noDisplay()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal  library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you  can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the  display() and noDisplay() functions to turn on and off  the display.
*/
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);           // set up the LCD's number of columns and rows:
  lcd.print("!!DATASOFT IOT!!");       // Print a message to the LCD.
}

void loop() {
  lcd.setCursor(14,1);
  lcd.print(millis()/1000);
 
//  lcd.noDisplay();     // Turn off the display:
//  delay(100);
//  lcd.display();        // Turn on the display:
//  delay(100);
}

