int val;
int tempPin = A0;
int led= PB0;
void setup()
{
Serial.begin(9600);
}
void loop()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

if(cel>30){
//digitalWrite(led);
pinMode(led, OUTPUT);
}  
Serial.print("TEMPRATURE = ");

Serial.print(cel);
Serial.print("*C");
Serial.print(" or ");


Serial.print(farh);
Serial.print("*F");
Serial.println();
delay(1000);



}

