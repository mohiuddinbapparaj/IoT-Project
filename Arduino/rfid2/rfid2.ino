#include <SPI.h>
#include <RFID.h>
#include <Wire.h>
#define SERVO_PIN  6
RFID rfid(10,9);

byte serNum[4];
long int data[4];
long int ID=0;
int LED_access = 3;
int i=1;

int incomingByte=0;
void setup() {
  Serial.begin(9600);
  SPI.begin(); // SPI communication initialization
  rfid.init(); // RFID module initialization
  pinMode(LED_access,OUTPUT);
  pinMode(SERVO_PIN,OUTPUT); 
 
}

void loop() 
{

if (rfid.isCard())// valid card found
{
  digitalWrite(LED_access,1);
  if (rfid.readCardSerial()) // reads the card
  { 
    data[0] = rfid.serNum[0]; // stores the serial number
    data[1] = rfid.serNum[1];
    data[2] = rfid.serNum[2];
    data[3] = rfid.serNum[3];   
  }

  for(int i=0; i<3; i++)
  {
    if(data[i+1]>=100) data[i]=data[i]*1000;
    else if(data[i+1]>=10) data[i]=data[i]*100;
    else data[i]=data[i]*10;
    data[i+1]=data[i]+data[i+1];
  }
ID=abs(data[3]);
data[0] = 0;
data[1] = 0;
data[2] = 0;
data[3] = 0;
  
  
  if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                if(incomingByte=='0')
                Serial.println(ID); 
                
                }
}

digitalWrite(LED_access,0);

}

