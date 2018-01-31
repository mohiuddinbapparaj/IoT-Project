
#include <Arduino.h>
#include<LiquidCrystal.h>

const int up=10;
const int set=9;
const int down=8;
const int led=7;
int buttonState = 0;
int buttonState_down = 0;
int buttonState_set = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
const int sensor=A1; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading
int x=30; int y=30;

void setup()
{
pinMode(sensor,INPUT); // Configuring pin A1 as input
Serial.begin(9600);
lcd.begin(16,2);  
  delay(500);
 pinMode(led, OUTPUT);
 pinMode(up, INPUT);
 pinMode(down, INPUT);
 pinMode(set, INPUT);
 
}
void loop() 
{
vout=analogRead(sensor);
vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
tempf=(vout*1.8)+32; // Converting to Fahrenheit 
lcd.setCursor(0,0);
lcd.print("in DegreeC= ");
lcd.print(tempc);



buttonState = digitalRead(up);
buttonState_down = digitalRead(down);
buttonState_set = digitalRead(set);

// check if the pushbutton is pressed. If it is, the buttonState is HIGH:
if (buttonState == HIGH) {
	x=x+1;
	}
	if (buttonState_down == HIGH) {
	x=x-1;
	}
	if (buttonState_set == HIGH) {
	y = x;
	}
if (vout>y) {
	digitalWrite(led, HIGH);
	} else {
	digitalWrite(led, LOW);
}
lcd.setCursor(0,1);
lcd.print("Setpoint: ");
lcd.print(x);
delay(1000); //Delay of 1 second for ease of viewing in serial monitor
}
