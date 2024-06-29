#include <allegro5/allegro5.h>
#include <allegro5/bitmap.h>
#include <allegro5/color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
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
  Reset all the boxes 
*/
void resetSelectionBoxes(SELECTION_BOX* allSelectionBoxes);

/*
  Reset all the boxes to the white color
*/
void resetSelectionBoxesColor(SELECTION_BOX* allSelectionBoxes);
/*
  Update the selection boxes
*/
bool updateSelectionBoxes(SELECTION_BOX* allSelectionBoxes, short* idSelcP,
                          unsigned char* keyboardKeys,
                          unsigned char* playerKeys, ALLEGRO_COLOR color);

/*
  Draw all the four selection boxes
*/
void drawSelectionBoxes(SELECTION_BOX* allSelectionBoxes, ALLEGRO_COLOR* boxOfColors);

void drawVersusScreen(ALLEGRO_COLOR p1, ALLEGRO_COLOR p2, ALLEGRO_FONT* font);
#endif
