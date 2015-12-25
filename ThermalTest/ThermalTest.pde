//Seek resolution: 206 x 156

int count = 0;
void setup()
{
  size(208, 156);
  //background(0xFF);
  //colorMode(RGB);
  //noStroke();
  /*loadPixels();
  
  
  int index = 0;
  
  byte b[] = loadBytes("/home/ian/Downloads/seek/1.bin");
  int cnt = 0;
  for(int i = 0; i < 208 * 156; ++i)
  {
    pixels[i] = color(b[cnt++], b[cnt++], b[cnt++]);
  }
  
  updatePixels();*/
}

void draw()
{
  loadPixels();
  // Open a file and read its binary data 
  String s = "" + count;
  byte b[] = loadBytes("/home/ian/Downloads/seek/" + s + ".bin"); 
  
  if (count >= 10) {
    count = 0;
  } else {
    count++;
  }
  println(count);
  /*try {
    print("Bin: " + count + " ");
    println((int)map(((b[0] << 8) + b[1]) & 0xFFFF, 0, 65535, 0, 255));
  }
  catch (ArrayIndexOutOfBoundsException e) {
  }*/
  // Print each value, from 0 to 255 
  /*for (int i = 0; i < b.length; i++){ 
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
  loadPixels();
  int cnt = 0;
  for (int i = 0; i < 208 * 156; ++i) {
    //for (int j = 0; j < 208; j++) {
      //try {
        //stroke((b[cnt] & 0xFF + b[cnt + 1] & 0xFF) / 2);
        //stroke((b[cnt]));
        //stroke((int)map(((b[cnt] << 8) + b[cnt+1]) & 0xFFFF, 0, 65535, 0, 255));
        //pixels[i] = (int)map(((b[cnt] << 8) + b[cnt+1]) & 0xFFFF, 0, 65535, 0, 255);
        //pixels[i] = color(b[i++], b[i++], b[i++]);
        //long temp = millis();
        //while(millis() - temp < 1000);
        //println("test");
        pixels[i] = color(b[cnt++], b[cnt++], b[cnt++]);
     // }
      //catch (ArrayIndexOutOfBoundsException e) {
      //}
      
      //point(j, i);
      
      //delay(1);
      //if (i % 2 == 0) {
        //cnt+=1;
      //}
    //}
  }
  int temp = millis();
  while(millis() - temp < 750);
  updatePixels();
}
