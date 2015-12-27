void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  //Read
  while(Serial1.available() > 0) {
    int xbeeInput = Serial1.read();
    if(xbeeInput != -1) {
      Serial.write(xbeeInput);
    }
  }
    
  //Write
  while(Serial.available() > 0){
    int serialInput = Serial.read();
    if(serialInput != -1) {
      Serial1.write(serialInput);
    }
  }
}
