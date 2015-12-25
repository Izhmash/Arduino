// the value of the 'other' resistor
#define SERIESRESISTOR 10000    
 
// What pin to connect the sensor to
#define THERMISTORPIN A0 

static const uint8_t analogPins[] = {
  A0, A1, A2, A3, A4, A5, A6
};

int thermData[7];
 
void setup(void) {
  Serial.begin(9600);
}
 
void loop(void) {
  float reading;
  Serial.write('?');
  for (int i = 0; i < 8; ++i) {
    reading = analogRead(analogPins[i]);
   
    Serial.print(i);
    Serial.print(": ");
    Serial.print("Analog reading "); 
    Serial.println(reading);
   
    // convert the value to resistance
    reading = (1023 / reading)  - 1;
    reading = SERIESRESISTOR / reading;
    Serial.print("Thermistor resistance "); 
    Serial.println(reading);
  }
  Serial.write('!');
  delay(1000);
}
