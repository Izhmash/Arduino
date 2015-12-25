static const uint8_t IRPins[] = {
  30, 31, 32, 33, 34, 35, 36, 37
};

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
byte data;
byte dataOld;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  for (int i = 0; i < sizeof(IRPins) / sizeof(uint8_t); ++i) {
    pinMode(IRPins[i], INPUT);
  }
}

void loop()
{
  if (Serial1.available() > 0) {   //wait for call to send temp data
    for (int j = 0; j < 10; ++j) {
      Serial1.read();
      Serial1.print('#');
      //Serial.println("DATA IN");
      for (int i = 0; i < 8; ++i) {
        thermData[i] = ((bValue / log((((vRef * rBias) / ((analogRead(thermPins[i]) / adcRes) * vRef)) - rBias) / rAlpha)) - c2Kelvin) * 9 / 5 + 32;
        delay(100);
        Serial1.print(thermData[i]);
        Serial.print(thermData[i]);
        if (i < 7) {
          Serial1.print(",");
          Serial.print(",");
        }
      }
      Serial1.println();
      Serial.println();
    }
  }
  dataOld = data;
  for (int i = 0; i < sizeof(IRPins) / sizeof(uint8_t); ++i) {
    data = data << 1;
    data |= (byte) digitalRead(IRPins[i]);  //bits shifted in
  }
  if (dataOld != data) {
    Serial1.print('!');
    Serial1.write(data);
    Serial.println("1 2 3 4");
    Serial.println(data, BIN);
  }
}
