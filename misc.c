#include "misc.h"

#include <allegro5/bitmap.h>

// Checks if an allegro module was initialized correctly
void alCheckInit(bool test, char* description) {
  if (test) return;

  printf("Couldn't initialize %s\n", description);
  exit(1);
}

/*
  Returns true if two box collided
*/
bool boxCollision(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
  if (ax1 > bx2) return false;
  if (ax2 < bx1) return false;
  if (ay1 > by2) return false;
  if (ay2 < by1) return false;

  return true;
}

/*
  Grabs a sprite inside a spritesheet
*/
ALLEGRO_BITMAP* grabSprite(ALLEGRO_BITMAP* sheet, int x, int y, int w, int h) {
  ALLEGRO_BITMAP* sprite = al_create_sub_bitmap(sheet, x, y, w, h);
  alCheckInit(sprite, "grab sprite");
  return sprite;
}
