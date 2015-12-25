#define PIR  11
#define LED  13

boolean t;

void setup()
{
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  t = false;
}

void loop()
{
  if (digitalRead(PIR) == HIGH && !t) {
    Serial.write('P');
    t = true;
    digitalWrite(LED, HIGH);
  }
  if (digitalRead(PIR) == LOW && t) {
    t = false;
    digitalWrite(LED, LOW);
  }
}
