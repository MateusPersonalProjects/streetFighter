#ifndef __MISC__
#define __MISC__
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/bitmap.h>

// Checks if an allegro module was initialized correctly
void alCheckInit(bool test, char* description);

/*
  Returns true if two box collided
*/
bool boxCollision(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2); 

/*
  Grabs a sprite inside a spritesheet
*/
ALLEGRO_BITMAP* grabSprite(ALLEGRO_BITMAP* sheet, int x, int y, int w, int h);

#endif // !__MISC__
