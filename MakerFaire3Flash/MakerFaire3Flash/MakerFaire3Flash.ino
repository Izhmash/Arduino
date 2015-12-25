#include <Adafruit_NeoPixel.h>

#define PIN 0

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

static uint32_t red = strip.Color(255, 0, 0);
static uint32_t blue = strip.Color(0, 255, 0);
static uint32_t green = strip.Color(0, 0, 255);
static uint32_t white = strip.Color(0, 0, 0);
static uint32_t purple = strip.Color(178, 102, 255);
static uint32_t orange = strip.Color(255, 128, 0);
static uint32_t yellow = strip.Color(255, 255, 0);

static uint32_t colorArray[3] = { red, green, blue };

void setup() {
  strip.begin();
  strip.show(); 
  strip.setBrightness(40);
}

void loop(){
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 8; j++) {
      strip.setPixelColor(j, colorArray[i]);
    }
    delay(500);
    strip.show();
  }
}




