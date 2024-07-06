#include "characSelecMenu.h"

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/bitmap_io.h>
#include <allegro5/color.h>

/*
  Initialize all the four selection boxes
*/
void initSelectionBoxes(SELECTION_BOX* allSelectionBoxes,
                        CHARAC_SELECT_SPRITES* characSelecSprites) {
  int midScreenY = BUFFER_H / 2;
  int midScreenX = BUFFER_W / 2;
  ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

  allSelectionBoxes[0].xPosit = midScreenX - (SELECT_BOX_WIDTH / 2) - 10;
  allSelectionBoxes[0].yPosit = midScreenY - (SELECT_BOX_HEIGHT / 2) - 10;
  allSelectionBoxes[0].image = characSelecSprites->ryu;
  allSelectionBoxes[0].portraitImage = characSelecSprites->ryuPortrait;

  allSelectionBoxes[1].xPosit = midScreenX + (SELECT_BOX_WIDTH / 2) + 10;
  allSelectionBoxes[1].yPosit = midScreenY - (SELECT_BOX_HEIGHT / 2) - 10;
  allSelectionBoxes[1].image = characSelecSprites->ken;
  allSelectionBoxes[1].portraitImage = characSelecSprites->kenPortrait;

  allSelectionBoxes[2].xPosit = midScreenX - (SELECT_BOX_WIDTH / 2) - 10;
  allSelectionBoxes[2].yPosit = midScreenY + (SELECT_BOX_HEIGHT / 2) + 10;
  allSelectionBoxes[2].image = characSelecSprites->chunli;
  allSelectionBoxes[2].portraitImage = characSelecSprites->chunliPortrait;

  allSelectionBoxes[3].xPosit = midScreenX + (SELECT_BOX_WIDTH / 2) + 10;
  allSelectionBoxes[3].yPosit = midScreenY + (SELECT_BOX_HEIGHT / 2) + 10;
  allSelectionBoxes[3].image = characSelecSprites->guile;
  allSelectionBoxes[3].portraitImage = characSelecSprites->guilePortrait;

  for (int i = 0; i < 4; i++) {
    allSelectionBoxes[i].color = color;
    allSelectionBoxes[i].selected = false;
  }
}

/*
  Init all the character select menu sprites
*/
CHARAC_SELECT_SPRITES* initCharacSelectSprites() {
  CHARAC_SELECT_SPRITES* characSelecSprites =
      (CHARAC_SELECT_SPRITES*)malloc(sizeof(CHARAC_SELECT_SPRITES));
  characSelecSprites->sheet =
      al_load_bitmap("./images/characMenu/characSelectSpriteSheet.png");
  alCheckInit(characSelecSprites->sheet, "characMenu spritesheet");

  characSelecSprites->sheetPortrait = al_load_bitmap(
      "./images/characMenu/characSelectSpriteSheetPortraits.png");
  alCheckInit(characSelecSprites->sheetPortrait, "portrait sheet");

  characSelecSprites->ken = grabSprite(
      characSelecSprites->sheet, CHARAC_SELECT_SPRITE_X_KEN,
      CHARAC_SELECT_SPRITE_Y, CHARAC_SELECT_SPRITE_W, CHARAC_SELECT_SPRITE_H);
  characSelecSprites->ryu = grabSprite(
      characSelecSprites->sheet, CHARAC_SELECT_SPRITE_X_RYU,
      CHARAC_SELECT_SPRITE_Y, CHARAC_SELECT_SPRITE_W, CHARAC_SELECT_SPRITE_H);
  characSelecSprites->guile = grabSprite(
      characSelecSprites->sheet, CHARAC_SELECT_SPRITE_X_GUILE,
      CHARAC_SELECT_SPRITE_Y, CHARAC_SELECT_SPRITE_W, CHARAC_SELECT_SPRITE_H);
  characSelecSprites->chunli = grabSprite(
      characSelecSprites->sheet, CHARAC_SELECT_SPRITE_X_CHUNLI,
      CHARAC_SELECT_SPRITE_Y, CHARAC_SELECT_SPRITE_W, CHARAC_SELECT_SPRITE_H);

  characSelecSprites->kenPortrait =
      grabSprite(characSelecSprites->sheetPortrait, PORTRAIT_X, PORTRAIT_Y_KEN,
                 PORTRAIT_W, PORTRAIT_H);
  characSelecSprites->ryuPortrait =
      grabSprite(characSelecSprites->sheetPortrait, PORTRAIT_X, PORTRAIT_Y_RYU,
                 PORTRAIT_W, PORTRAIT_H);
  characSelecSprites->guilePortrait =
      grabSprite(characSelecSprites->sheetPortrait, PORTRAIT_X,
                 PORTRAIT_Y_GUILE, PORTRAIT_W, PORTRAIT_H);
  characSelecSprites->chunliPortrait =
      grabSprite(characSelecSprites->sheetPortrait, PORTRAIT_X,
                 PORTRAIT_Y_CHUNLI, PORTRAIT_W, PORTRAIT_H);
  return characSelecSprites;
}

/*
  Reset all the boxes to the white color
*/
void resetSelectionBoxes(SELECTION_BOX* allSelectionBoxes) {
  ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

  for (int i = 0; i < 4; i++) {
    allSelectionBoxes[i].selected = false;
  }
}

/*
  Reset all the boxes to the white color
*/
void resetSelectionBoxesColor(SELECTION_BOX* allSelectionBoxes) {
  ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

  for (int i = 0; i < 4; i++) {
    if (!allSelectionBoxes[i].selected) allSelectionBoxes[i].color = color;
  }
}

/*
  Update the selection boxes
*/
bool updateSelectionBoxes(SELECTION_BOX* allSelectionBoxes, short* idSelcP,
                          unsigned char* keyboardKeys,
                          unsigned char* playerKeys, ALLEGRO_COLOR color) {
  bool playerSelected = false;
  if (keyboardKeys[playerKeys[0]]) {
    (*idSelcP) -= 2;
    if ((*idSelcP) < 0) (*idSelcP) += 2;
  }

  if (keyboardKeys[playerKeys[1]]) {
    (*idSelcP) += 2;
    if ((*idSelcP) > 3) (*idSelcP) -= 2;
  }

  if (keyboardKeys[playerKeys[2]]) {
    (*idSelcP) -= 1;
    if ((*idSelcP) < 0) (*idSelcP) += 1;
  }

  if (keyboardKeys[playerKeys[3]]) {
    (*idSelcP) += 1;
    if ((*idSelcP) > 3) (*idSelcP) -= 1;
  }

  /*
    if the box was not selected yet select it and turn it green
  */
  if (keyboardKeys[playerKeys[4]]) {
    if (!allSelectionBoxes[(*idSelcP)].selected) {
      playerSelected = true;
      allSelectionBoxes[(*idSelcP)].color = al_map_rgb(0, 255, 0);
      allSelectionBoxes[(*idSelcP)].selected = true;
    }
  }

  /*
    if the box was not selected turn it into the color of the player
  */
  if (!allSelectionBoxes[(*idSelcP)].selected)
    allSelectionBoxes[(*idSelcP)].color = color;

  return playerSelected;
}
/*
  Draw all the four selection boxes
*/
void drawSelectionBoxes(SELECTION_BOX* allSelectionBoxes) {
  float x1, y1, x2, y2;
  for (int i = 0; i < 4; i++) {
    x1 = allSelectionBoxes[i].xPosit - (SELECT_BOX_WIDTH / 2.0);
    y1 = allSelectionBoxes[i].yPosit - (SELECT_BOX_HEIGHT / 2.0);
    x2 = allSelectionBoxes[i].xPosit + (SELECT_BOX_WIDTH / 2.0);
    y2 = allSelectionBoxes[i].yPosit + (SELECT_BOX_HEIGHT / 2.0);

    // Draw the crazy dude
    al_draw_bitmap(allSelectionBoxes[i].image, x1 + 2, y1 + 3, 0);
    al_draw_rectangle(x1, y1, x2, y2, allSelectionBoxes[i].color,
                      SELECT_BOX_THICKNESS);
  }
}

/*
  Draw the versus screen
*/
void drawVersusScreen(ALLEGRO_BITMAP* p1, ALLEGRO_BITMAP* p2,
                      ALLEGRO_FONT* font) {
  float p1X = 10;
  float p2X = BUFFER_W - (PORTRAIT_W * 2) - 10;
  float pY = (BUFFER_H / 2.0) - (PORTRAIT_H / 2.0);
  al_draw_scaled_bitmap(p1, 0, 0, PORTRAIT_W, PORTRAIT_H, p1X, pY,
                        PORTRAIT_W * 2, PORTRAIT_H * 2, 0);
  al_draw_scaled_bitmap(p2, 0, 0, PORTRAIT_W, PORTRAIT_H, p2X, pY,
                        PORTRAIT_W * 2, PORTRAIT_H * 2,
                        ALLEGRO_FLIP_HORIZONTAL);

  al_draw_text(font, al_map_rgb_f(1, 1, 1), BUFFER_W / 2.0, BUFFER_H / 2.0,
               ALLEGRO_ALIGN_CENTER, "V . S");
}

/*
  Destroy all the charact select sprites
*/
void destroyCharacSelectSprites(CHARAC_SELECT_SPRITES* characSelectSprites) {
  al_destroy_bitmap(characSelectSprites->chunli);
  al_destroy_bitmap(characSelectSprites->guile);
  al_destroy_bitmap(characSelectSprites->ryu);
  al_destroy_bitmap(characSelectSprites->ken);
  al_destroy_bitmap(characSelectSprites->sheet);
  al_destroy_bitmap(characSelectSprites->chunliPortrait);
  al_destroy_bitmap(characSelectSprites->guilePortrait);
  al_destroy_bitmap(characSelectSprites->ryuPortrait);
  al_destroy_bitmap(characSelectSprites->kenPortrait);
  al_destroy_bitmap(characSelectSprites->sheetPortrait);
  free(characSelectSprites);
}
