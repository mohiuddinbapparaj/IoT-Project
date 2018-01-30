#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(1,0);
  lcd.print("DATA");
  delay(50);
  
  lcd.setCursor(1,1);
  lcd.print("SOFT");
  delay(50);
}

void loop() {
  
  for (int p = 0; p < 13; p++) 
  {   
    lcd.scrollDisplayLeft();
    delay(50);
  }

  for (int p = 0; p < 42; p++) 
    {
    lcd.scrollDisplayRight();
    delay(50);
    }

  for (int p = 0; p < 29; p++) 
    {
    lcd.scrollDisplayLeft();
    delay(50);
    }  
    //delay(1000);
  }





