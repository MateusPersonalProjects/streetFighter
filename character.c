#include "character.h"

#include <allegro5/bitmap_io.h>
#include <stdlib.h>
#include <time.h>

#include "fightersDefines/ryu.h"

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
  ryu->movesSprites[STEADY].width = RYU_IDLE_W;
  ryu->movesSprites[STEADY].height = RYU_IDLE_H;
  ryu->movesSprites[STEADY].numFrames = 4;
  ryu->movesSprites[STEADY].currentFrame = 0;

  // Getting memory for idle bitmaps
  ryu->movesSprites[STEADY].Sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (ryu->movesSprites[STEADY].Sprites == NULL) exit(1);

  ryu->movesSprites[STEADY].Sprites[0] =
      grabSprite(ryu->sheet, RYU_IDLE_1_X, RYU_IDLE_Y, RYU_IDLE_W, RYU_IDLE_H);
  ryu->movesSprites[STEADY].Sprites[1] =
      grabSprite(ryu->sheet, RYU_IDLE_2_X, RYU_IDLE_Y, RYU_IDLE_W, RYU_IDLE_H);
  ryu->movesSprites[STEADY].Sprites[2] =
      grabSprite(ryu->sheet, RYU_IDLE_3_X, RYU_IDLE_Y, RYU_IDLE_W, RYU_IDLE_H);
  ryu->movesSprites[STEADY].Sprites[3] =
      grabSprite(ryu->sheet, RYU_IDLE_4_X, RYU_IDLE_Y, RYU_IDLE_W, RYU_IDLE_H);

  // WALKING THINGS
  ryu->movesSprites[WALKING].width = RYU_WALK_W_1;
  ryu->movesSprites[WALKING].height = RYU_WALK_H_2;
  ryu->movesSprites[WALKING].numFrames = 5;
  ryu->movesSprites[WALKING].currentFrame = 0;

  ryu->movesSprites[WALKING].Sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 5);
  if (ryu->movesSprites[WALKING].Sprites == NULL) exit(1);

  ryu->movesSprites[WALKING].Sprites[0] = grabSprite(
      ryu->sheet, RYU_WALK_X_1, RYU_WALK_Y_1, RYU_WALK_W_1, RYU_WALK_H_1);
  ryu->movesSprites[WALKING].Sprites[1] = grabSprite(
      ryu->sheet, RYU_WALK_X_2, RYU_WALK_Y_2, RYU_WALK_W_2, RYU_WALK_H_2);
  ryu->movesSprites[WALKING].Sprites[2] = grabSprite(
      ryu->sheet, RYU_WALK_X_3, RYU_WALK_Y_3, RYU_WALK_W_3, RYU_WALK_H_3);
  ryu->movesSprites[WALKING].Sprites[3] = grabSprite(
      ryu->sheet, RYU_WALK_X_4, RYU_WALK_Y_4, RYU_WALK_W_4, RYU_WALK_H_4);
  ryu->movesSprites[WALKING].Sprites[4] = grabSprite(
      ryu->sheet, RYU_WALK_X_5, RYU_WALK_Y_5, RYU_WALK_W_5, RYU_WALK_H_5);

  return ryu;
}

/*
  Free the memory that a character was being utilized by a character
*/
void characterDestroyer(CHARACTER* character) { free(character); }
