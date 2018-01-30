int button=2;
int out = 13;
int buttonState = 0;

void setup() {
  pinMode(button, INPUT);
  pinMode(out,OUTPUT);
  
}

void loop() {
  buttonState = digitalRead(button);
  if(buttonState == LOW)
  { digitalWrite(output, LOW);
  }
  else
  {digitalWrite(output, HIGH);}
}
