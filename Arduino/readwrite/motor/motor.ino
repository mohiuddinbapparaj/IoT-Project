//L293D
//Motor A
const int motorPin1  = 2;  
const int motorPin2  = 3; 
const int motorPin3  = 4; 
const int motorPin4  = 5;  


void setup(){
 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    
    

    
  
}


void loop(){
  
//This code  will turn Motor A clockwise for 2 sec.
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(2000); 
    //This code will turn Motor A counter-clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(2000);
    
    //This code will turn Motor B clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(2000); 
    //This code will turn Motor B counter-clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(2000);    
    
    //And this code will stop motors
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
}

