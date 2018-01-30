void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    Serial.println("error_check!!!");
  }
  Serial.println("enter any word-")
}

void loop() {
  // put your main code here, to run repeatedly:
  String takebyte = "";
  
  if (Serial.available() > 0) {
    
    String takechar = Serial.readString();
    
    int x = takechar.toInt();
    Serial.println("dec of the input");
    Serial.println(x, DEC);
   
    
    /*
      Serial.print("hex: ");
      Serial.print(takebyte, HEX);
      Serial.print("bin: ");
      Serial.print(takebyte, BIN);
      Serial.print("oct: ");
      Serial.print(takebyte, OCT);
    */

  }
}
