byte file[] = loadBytes("1.bin");

void setup()
{
  size(208,156);
  
  loadPixels();
  
  int index = 0;
  
  for(int i = 0; i < 208 * 156; ++i)
  {
    pixels[i] = color(file[index++], file[index++], file[index++]);
  }
  
  updatePixels();
}

void loop { }
