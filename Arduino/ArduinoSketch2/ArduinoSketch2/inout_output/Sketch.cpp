/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio


int pushButton = 2;
int led =13;


void setup() {

  pinMode(led, OUTPUT);
  pinMode(pushButton, INPUT);
}


void loop() {
  int buttonState = digitalRead(pushButton);
    if(buttonState == 0){
      digitalWrite(led, LOW);}
    else
      {digitalWrite(led, HIGH);}
}
