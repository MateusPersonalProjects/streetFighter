#include <allegro5/allegro5.h>
#include <allegro5/bitmap.h>
#include <allegro5/color.h>
#include <allegro5/allegro_primitives.h>
#include "display.h"

#ifndef __CHARAC_SELEC_MENU__
#define __CHARAC_SELEC_MENU__

#define SELECT_BOX_WIDTH 100
#define SELECT_BOX_HEIGHT 100
#define SELECT_BOX_THICKNESS 2.5

typedef struct{
  int xPosit;
  int yPosit;
  bool selected;
  ALLEGRO_COLOR color;
  ALLEGRO_BITMAP* image;
} SELECTION_BOX;

/*
  Initialize all the four selection boxes
*/
void initSelectionBoxes(SELECTION_BOX* allSelectionBoxes);

/*
  Draw all the four selection boxes
*/
void drawSelectionBoxes(SELECTION_BOX* allSelectionBoxes);


#endif
