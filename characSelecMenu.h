#include <allegro5/allegro5.h>
#include <allegro5/bitmap.h>
#include <allegro5/color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/events.h>
#include "display.h"
#include "misc.h"

#ifndef __CHARAC_SELEC_MENU__
#define __CHARAC_SELEC_MENU__

#define SELECT_BOX_WIDTH 60
#define SELECT_BOX_HEIGHT 100
#define SELECT_BOX_THICKNESS 2.5

#define CHARAC_SELECT_SPRITE_W 57
#define CHARAC_SELECT_SPRITE_H 94

#define CHARAC_SELECT_SPRITE_Y 229

#define CHARAC_SELECT_SPRITE_X_RYU 10
#define CHARAC_SELECT_SPRITE_X_KEN 260
#define CHARAC_SELECT_SPRITE_X_CHUNLI 324
#define CHARAC_SELECT_SPRITE_X_GUILE 198

#define PORTRAIT_W 76
#define PORTRAIT_H 97

#define PORTRAIT_X 7

#define PORTRAIT_Y_RYU 0
#define PORTRAIT_Y_KEN 419
#define PORTRAIT_Y_CHUNLI 516
#define PORTRAIT_Y_GUILE 319

#define LOGO_W 224
#define LOGO_H 124

#define LOGO_Y 565
#define LOGO_X 276

#define VS_X 123
#define VS_Y 21
#define VS_W 94
#define VS_H 56

typedef struct{
  int xPosit;
  int yPosit;
  bool selected;
  ALLEGRO_COLOR color;
  ALLEGRO_BITMAP* image;
  ALLEGRO_BITMAP* portraitImage;
} SELECTION_BOX;

typedef struct{
  ALLEGRO_BITMAP* sheet;
  ALLEGRO_BITMAP* sheetPortrait;
 
  ALLEGRO_BITMAP* logo;
  ALLEGRO_BITMAP* ryu;
  ALLEGRO_BITMAP* ken;
  ALLEGRO_BITMAP* chunli;
  ALLEGRO_BITMAP* guile;
  ALLEGRO_BITMAP* ryuPortrait;
  ALLEGRO_BITMAP* kenPortrait;
  ALLEGRO_BITMAP* chunliPortrait;
  ALLEGRO_BITMAP* guilePortrait;
  ALLEGRO_BITMAP* vs_sprite;

} CHARAC_SELECT_SPRITES;


/*
  Initialize all the four selection boxes
*/
void initSelectionBoxes(SELECTION_BOX* allSelectionBoxes, CHARAC_SELECT_SPRITES* characSelecSprites);

/*
  Init all the character select menu sprites
*/
CHARAC_SELECT_SPRITES* initCharacSelectSprites();

/*
  Reset all the boxes 
*/
void resetSelectionBoxes(SELECTION_BOX* allSelectionBoxes);

/*
  Reset all the boxes to the white color
*/
void resetSelectionBoxesColor(SELECTION_BOX* allSelectionBoxes);

/*
  Update the selection boxes color
*/
void updateSelectionBoxesColor(SELECTION_BOX* allSelectionBoxes, short* idSelcP,
                               ALLEGRO_COLOR color) ;
 
/*
  Update the selection boxes
*/
bool updateSelectionBoxes(SELECTION_BOX* allSelectionBoxes, short* idSelcP,
                          unsigned char* keyboardKeys,
                          unsigned char* playerKeys, ALLEGRO_EVENT event);
/*
  Draw the main menu
*/
void drawMainMenu(ALLEGRO_BITMAP* logo, ALLEGRO_FONT* font, long timer,
                  short* twinkle);

/*
  Draw all the four selection boxes
*/
void drawSelectionBoxes(SELECTION_BOX* allSelectionBoxes, ALLEGRO_BITMAP* logo);

/*
  Draw portraits for the selection screen
*/
void drawCharacterCursorOver(SELECTION_BOX* allSelectionBoxes, short p1Over,
                             short p2Over, ALLEGRO_FONT* font, bool p1selected,
                             bool p2selected, long timer, short* twinkle);
 
void drawVersusScreen(ALLEGRO_BITMAP* p1, ALLEGRO_BITMAP* p2, ALLEGRO_BITMAP* vsImage);

/*
  Destroy all the charact select sprites
*/
void destroyCharacSelectSprites(CHARAC_SELECT_SPRITES* characSelectSprites);

#endif
