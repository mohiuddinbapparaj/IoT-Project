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
  pinMode(a,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(a,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0; i<10; i++){
    displayDigit(i);
    delay(1000);
    turnOff(); 
  }

}
