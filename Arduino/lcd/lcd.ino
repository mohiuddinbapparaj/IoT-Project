const int LED = 13;
const int PushButton = 2;

int state = 0;

void setup()
{
  pinMode ( LED, OUTPUT );
  pinMode ( PushButton, INPUT);
}

void loop()
{
  state = digitalRead (PushButton);
  if ( state == HIGH)
  {
    digitalWrite (LED, HIGH);
  }
  else
  {
    digitalWrite (LED, LOW);
  }
}

