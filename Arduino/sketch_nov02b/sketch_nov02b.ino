int a=2;
int b=3;
int c=4;
int d=5;
int e=6;
int f=8;
int g=9;

void setup() {
  // put your setup code here, to run once:
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
}

void turnOff(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);  
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void displayDigit(int digit){
  if(digit != 1 && digit != 4){
    digitalWrite(a,HIGH);
  }
    if(digit != 5 && digit != 6){
    digitalWrite(b,HIGH);
  }
    if(digit != 2){
    digitalWrite(c,HIGH);
  }
    if(digit != 1 && digit != 4 && digit != 7){
    digitalWrite(d,HIGH);
  }
    if(digit != 1 && digit != 3 && digit != 4 && digit != 5 && digit != 7 && digit != 9 ){
    digitalWrite(e,HIGH);
  }
    if(digit != 1 && digit != 2 && digit != 3 && digit != 7){
    digitalWrite(f,HIGH);
  }
    if(digit != 0 && digit != 1 && digit != 7){
    digitalWrite(g,HIGH);
  }
}





void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0; i<10; i++){
    displayDigit(i);
    delay(100);
    turnOff(); 
  }

}
