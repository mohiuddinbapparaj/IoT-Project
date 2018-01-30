
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
