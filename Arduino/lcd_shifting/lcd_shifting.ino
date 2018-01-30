#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,6,5,4,3);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<16;i++){
    if (i%2==0){
      
        lcd.setCursor(5,0);
        lcd.print("Avijit");
        delay(500);
        
      
      }
     else{
      lcd.setCursor(6,1);
      lcd.print("Nandi");
      delay(500);
       
     }
  }
  
}
