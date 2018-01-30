char mystr[5];
const int analog_pin = A0; 
int analog_In = 0;
String val ="sensor value";
void setup() {
  Serial.begin(9600);    // serial / USB port
  
}

byte rx_byte = 0;        // stores received byte
char buf[4];
void loop() {

  if (Serial.available()>0) {
    analog_In = analogRead(analog_pin);
    rx_byte = Serial.read();
    if (rx_byte == '1'){
//      val = analog_In;
    itoa(analog_In, buf, 10);
      Serial.write(buf, 4);
 //   Serial.print("/");
 //   Serial.println("\n");
//    Serial.write(char(analog_In));
    }
    else {
     //Serial.write(6);
    }
  }
  
}
