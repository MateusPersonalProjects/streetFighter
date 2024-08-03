#ifndef __DISPLAY__
#define __DISPLAY__
#include "misc.h"
#include <allegro5/allegro5.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/display.h>

// Size of the buffer that all the things are going to be draw
#define BUFFER_W 400
#define BUFFER_H 300

// The size of the display is a multiplication of the size of our buffer
#define DISP_SCALE 2
#define DISP_W (BUFFER_W * DISP_SCALE)
#define DISP_H (BUFFER_H * DISP_SCALE)

/*
  Initialize the display and the bitmap buffer that is going to be draw and
  scaleted to the game display
*/
void dispInit(ALLEGRO_DISPLAY **disp, ALLEGRO_BITMAP **buffer);

/*
  Destroy the game display and the bitmap buffer
*/
void dispDestroyer(ALLEGRO_DISPLAY *disp, ALLEGRO_BITMAP *buffer);

/*
  Sets where the program must draw the things (must be used before draw
  everything)
*/
void dispPreDraw(ALLEGRO_BITMAP *buffer);

/*
  Draw the things that were on the buffer display into the display but in
  another scale
*/
void dispPostDraw(ALLEGRO_DISPLAY *disp, ALLEGRO_BITMAP *buffer);

#endif // !__DISPLAY__
