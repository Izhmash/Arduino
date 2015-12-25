static const uint8_t thermPins[] = {
  A0, A1, A2, A3, A4, A5, A6
};

int thermData[7];
float rBias  = 10000.00;
float bValue = 3435;
float rAlpha  = 0.09919;
float c2Kelvin = 273.15;
float adcRes = 1024.00;
float vRef = 5.00;

void setup() 
{
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() 
{
  for (int i = 0; i < 8; ++i) {
    thermData[i] = ((bValue/log((((vRef*rBias)/((analogRead(thermPins[i])/adcRes)*vRef))-rBias)/rAlpha))-c2Kelvin)*9/5+32;
    Serial1.print(thermData[i]);
    Serial.print(thermData[i]);
    if (i < 7) {
      Serial1.print(",");
      Serial.print(",");
    }
  }
  Serial1.println();
  Serial.println();
  //Serial1.println(thermData[0]);
  delay(10);
}
