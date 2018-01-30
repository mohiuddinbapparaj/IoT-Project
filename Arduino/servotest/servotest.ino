#include <Servo.h>
Servo servo;

void setup() {
  
  Serial.begin(9600);
  servo.attach(2); //D4
  servo.write(0);
  delay(2000);

}

void loop() {
  
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);
  if (voltage>2.5)
  {
    servo.write(180);
    
  }
  else
  {
    servo.write(0);
    
  }
}
