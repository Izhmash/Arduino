#include <TVout.h>
#include <video_gen.h>
#include <fontALL.h> 
#include <i2cmaster.h>
#include <nunchuck.h>

#define SCREEN_WIDTH    112
#define SCREEN_HEIGHT   90  

TVout TV;
Nunchuck player1;

typedef struct
{
  int x, y;
} Ship;

typedef struct
{
  int x, y;
  unsigned long time;
  boolean init, isAlive;
} Shot;

Ship ship;
Shot shot1, shot2;

void setup()
{
  TV.begin(NTSC, SCREEN_WIDTH, SCREEN_HEIGHT);
  TV.select_font(font6x8);
  player1.begin(NUNCHUCK_PLAYER_1);
  /*for(int x = 0; x < SCREEN_WIDTH; x++)
    for(int y = 0; y < SCREEN_HEIGHT; y++)
    {
      TV.set_pixel(x, y, 1);
      //TV.delay(1);
    }*/
  ship.x = SCREEN_WIDTH / 2;
  ship.y = SCREEN_HEIGHT / 2;
  shot1.isAlive = false;
  shot2.isAlive = false;
  shot1.init = false;
  shot2.init = false;
}

void loop()
{
  player1.update();
  
  update();
  render();
  
}

void update()
{
  if (player1.joy_y() > 127 + 5)
  {
    ship.y -= 1;
    if(ship.y <= 0) ship.y = SCREEN_HEIGHT;
  }
  
  if (player1.joy_y() < 127 - 5)
  {
    ship.y += 1;
    if(ship.y >= SCREEN_HEIGHT) ship.y = 0;
  }
  
  if (player1.joy_x() > 127 + 5)
  {
    ship.x += 1;
    if(ship.x >= SCREEN_WIDTH) ship.x = 0;
  }
  
  if (player1.joy_x() < 127 - 5)
  {
    ship.x -= 1;
    if(ship.x <= 0) ship.x = SCREEN_WIDTH;
  }
  
  if (player1.button_c() &! shot2.isAlive)
  {
    if(shot1.isAlive)
    {
      if(millis() - shot1.time > 250)  
        shot2.init = true;
    }
    else
      shot1.init = true;
  }
  
  if(shot1.init)
  {
    shot1.time = millis();
    shot1.x = ship.x + 2;
    shot1.y = ship.y;
    shot1.init = false;
    shot1.isAlive = true;
    TV.tone(800, 10);
  }
  if(shot2.init)
  {
    shot2.time = millis();
    shot2.x = ship.x + 2;
    shot2.y = ship.y;
    shot2.init = false;
    shot2.isAlive = true;
    TV.tone(800, 10);
  }
  
  if(shot1.isAlive)
  {
    if(shot1.x < SCREEN_WIDTH)
      shot1.x += 2;
    else shot1.isAlive = false;
  } 
  if(shot2.isAlive)
  {
    if(shot2.x < SCREEN_WIDTH)
      shot2.x += 2;
    else shot2.isAlive = false;
  } 
}

void render()
{
  
  TV.delay_frame(1);
  TV.clear_screen();
  TV.set_pixel(ship.x, ship.y, 1);
  TV.set_pixel(ship.x + 1, ship.y, 1);
  TV.set_pixel(ship.x, ship.y - 1, 1);
  TV.set_pixel(ship.x, ship.y + 1, 1);
  
  if(shot1.isAlive)
  {
    TV.set_pixel(shot1.x, shot1.y, 1);
  }
  if(shot2.isAlive)
  {
    TV.set_pixel(shot2.x, shot2.y, 1);
  }
  //TV.tone(abs(player1.joy_x())); 
}



