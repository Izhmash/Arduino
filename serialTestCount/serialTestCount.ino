int i;
void setup() {
  Serial1.begin(9600);
  i = 0;
}

void loop() {
  i = i + 1;
  Serial1.print(i);
  delay(1000);
}
