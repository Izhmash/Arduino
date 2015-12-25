static const uint8_t analogPins[] = {
  A0, A1, A2, A3, A4, A5, A6
};
int thermData[7];

void setup() 
{
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() 
{
  for (int i = 0; i < 8; ++i) {
    thermData[i] = analogRead(analogPins[i]);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(thermData[i]);
  }
  Serial1.println(thermData[0]);
  delay(1000);
}
