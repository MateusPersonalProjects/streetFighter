#include "character.h"

#include <allegro5/bitmap_io.h>
#include <stdlib.h>

/*
  Initialize a new character
*/
CHARACTER* characterInit(FIGHTER_SPRITES* fighterSprite) {
  CHARACTER* newChar = (CHARACTER*)malloc(sizeof(CHARACTER));
  if (newChar == NULL) exit(1);

  newChar->width = fighterSprite->movesSprites[0].width;
  newChar->height = fighterSprite->movesSprites[0].height;
  newChar->crouchHeight = 0;
  newChar->currentSprite = STEADY;
  newChar->Sprites = fighterSprite;
  return newChar;
}

/*
  Initialize RYU
*/
FIGHTER_SPRITES* initRyu() {
  FIGHTER_SPRITES* ryu = (FIGHTER_SPRITES*)malloc(sizeof(FIGHTER_SPRITES));
  if (ryu == NULL) exit(1);

  ryu->sheet = al_load_bitmap("./images/fighters/ryuSheet.png");
  alCheckInit(ryu->sheet, "ryu sprite sheet");
  al_convert_mask_to_alpha(ryu->sheet, al_map_rgb(112, 136, 136));
  // IDLE THINGS
  ryu->movesSprites[0].width = RYU_IDLE_W;
  ryu->movesSprites[0].height = RYU_IDLE_H;
  ryu->movesSprites[0].numFrames = 4;
  ryu->movesSprites[0].currentFrame = 0;

  // Getting memory for bitmaps
  ryu->movesSprites[0].Sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (ryu->movesSprites[0].Sprites == NULL) exit(1);

  ryu->movesSprites[0].Sprites[0] =
      grabSprite(ryu->sheet, RYU_IDLE_1_X, RYU_IDLE_Y, RYU_IDLE_W, RYU_IDLE_H);
  ryu->movesSprites[0].Sprites[1] =
      grabSprite(ryu->sheet, RYU_IDLE_2_X, RYU_IDLE_Y, RYU_IDLE_W, RYU_IDLE_H);
  ryu->movesSprites[0].Sprites[2] =
      grabSprite(ryu->sheet, RYU_IDLE_3_X, RYU_IDLE_Y, RYU_IDLE_W, RYU_IDLE_H);
  ryu->movesSprites[0].Sprites[3] =
      grabSprite(ryu->sheet, RYU_IDLE_4_X, RYU_IDLE_Y, RYU_IDLE_W, RYU_IDLE_H);

  return ryu;
}

/*
  Free the memory that a character was being utilized by a character
*/
void characterDestroyer(CHARACTER* character) { free(character); }
