#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define MATRIX_PIN 6

//uint16_t red = matrix.Color

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, MATRIX_PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);
  
int x = matrix.width();
  
void setup(){
  matrix.begin();
  matrix.setBrightness(10);
  matrix.fillScreen(0);
}

void loop(){
  matrix.setCursor(x, 0);

  //matrix.drawRect(0, 0, 8, 8, matrix.Color(255, 0, 0));
  if(--x < -36) {
    x = matrix.width();
    //if(++pass >= 3) pass = 0;
    matrix.setTextColor(matrix.Color(255, 0, 0));
  }
  matrix.show();
}
