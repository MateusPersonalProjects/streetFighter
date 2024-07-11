#include "character.h"

#include <allegro5/bitmap_io.h>
#include <stdlib.h>

/*
  Initialize a new character
*/
CHARACTER* characterInit(int width, int height, int crouchHeight) {
  CHARACTER* newChar = (CHARACTER*)malloc(sizeof(CHARACTER));
  if (newChar == NULL) exit(1);

  newChar->width = width;
  newChar->height = height;
  newChar->crouchHeight = crouchHeight;
  newChar->currentSprite = STEADY;
  return newChar;
}

FIGHTER_SPRITES* initRyu() {
  FIGHTER_SPRITES* ryu = (FIGHTER_SPRITES*)malloc(sizeof(FIGHTER_SPRITES));

  ryu->sheet = al_load_bitmap("./images/fighters/ryuSheet.gif");
  alCheckInit(ryu->sheet, "ryu sprite sheet");

  // IDLE THINGS
  ryu->movesSprites[1].width = RYU_IDLE_W;
  ryu->movesSprites[1].height = RYU_IDLE_H;
  ryu->movesSprites[1].numFrames = 4;
  ryu->movesSprites[1].currentFrame = 0;

  // Getting memory for bitmaps
  ryu->movesSprites[1].Sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  ryu->movesSprites[1].Sprites[0] =
      grabSprite(ryu->sheet, RYU_IDLE_1_X, RYU_IDLE_Y, RYU_IDLE_W, RYU_IDLE_H);
  ryu->movesSprites[1].Sprites[1] =
      grabSprite(ryu->sheet, RYU_IDLE_2_X, RYU_IDLE_Y, RYU_IDLE_W, RYU_IDLE_H);
  ryu->movesSprites[1].Sprites[2] =
      grabSprite(ryu->sheet, RYU_IDLE_3_X, RYU_IDLE_Y, RYU_IDLE_W, RYU_IDLE_H);
  ryu->movesSprites[1].Sprites[3] =
      grabSprite(ryu->sheet, RYU_IDLE_4_X, RYU_IDLE_Y, RYU_IDLE_W, RYU_IDLE_H);

  return ryu;
}

/*
  Free the memory that a character was being utilized by a character
*/
void characterDestroyer(CHARACTER* character) { free(character); }
