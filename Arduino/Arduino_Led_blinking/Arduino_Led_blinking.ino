int led=13;

void setup() {
   //for (i=5; i<10;i++){
  // pinMode (i,OUTPUT);}}
  pinMode (led, OUTPUT);}
   

void loop() {
  
  //for (i=5; i<10;i++){
    digitalWrite(led,HIGH);
    delay(200);
    digitalWrite(led,LOW);
    delay(100);
 }




