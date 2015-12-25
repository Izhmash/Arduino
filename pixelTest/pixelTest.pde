void setup()
{
  size(640, 480);
  background(0xFF);
  colorMode(RGB); 
  noStroke();
}

void draw()
{
  for(int i = 0; i < 0xFF; i++) {
    for(int j = 0; j < 0xFF; j++) {
      stroke(i);
      point(i, j); 
    }
  }
}
