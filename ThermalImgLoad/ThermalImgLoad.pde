//Seek resolution: 206 x 156

void setup()
{
  size(205, 156);
  background(0xFF);
  colorMode(RGB);
  noStroke();
}

void draw()
{
  // Open a file and read its binary data 
  byte b[] = loadBytes("/home/ian/C++/70.bin"); 
  
  println(hex(b[1]));
  // Print each value, from 0 to 255 
  /*for (int i = 0; i < b.length; i++) { 
    // Every tenth number, start a new line 
    if ((i % 10) == 0) { 
      println(); 
    } 
    // bytes are from -128 to 127, this converts to 0 to 255 
    int a = b[i] & 0xff; 
    print(hex(a) + " "); 
  } 
  // Print a blank line at the end 
  println(); */
  int cnt = 0;
  for (int i = 0; i < 156; i++) {
    for (int j = 0; j < 206; j++) {
      stroke((b[cnt] + b[cnt + 1]) / 2);
      point(j, i);
      if (i % 2 == 0) {
        cnt++;
      }
    }
  }
}
