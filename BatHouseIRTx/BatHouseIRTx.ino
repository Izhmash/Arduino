static const uint8_t IRPins[] = {
  30, 31, 32, 33, 34, 35, 36, 37
};

byte data;

void setup() 
{
  Serial.begin(9600);
  Serial1.begin(9600);
  for (int i = 0; i < sizeof(IRPins)/sizeof(uint8_t); ++i) {
    pinMode(IRPins[i], INPUT);
  }
}

void loop() 
{
  data = 0;
  for (int i = 0; i < sizeof(IRPins)/sizeof(uint8_t); ++i) {
    data = data << 1;
    data |= (byte) digitalRead(IRPins[i]);  //bits shifted in
  } 
  Serial.println("1 2 3 4");
  Serial.println(data, BIN);
  delay(250);
}
