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

  newChar->width = fighterSprite->movesSprites[STEADY].drawBoxWidth;
  newChar->height = fighterSprite->movesSprites[STEADY].drawBoxHeight;
  newChar->hurtWidth = fighterSprite->movesSprites[STEADY].hurtBoxWidth;
  newChar->hurtHeight = fighterSprite->movesSprites[STEADY].hurtBoxHeight;
  // newChar->crouchHeight = 0;
  newChar->currentSprite = STEADY;
  newChar->fighterGraphics = fighterSprite;
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

  /* ------------------- IDLE THINGS ---------------------- */
  ryu->movesSprites[STEADY].numFrames = 4;
  ryu->movesSprites[STEADY].currentFrame = 0;

  // Draw box width and height information
  ryu->movesSprites[STEADY].drawBoxHeight = RYU_IDLE_DRAW_H;
  ryu->movesSprites[STEADY].drawBoxWidth = RYU_IDLE_DRAW_W;

  // Hurt box width and height information
  ryu->movesSprites[STEADY].hurtBoxHeight = RYU_IDLE_HURT_H;
  ryu->movesSprites[STEADY].hurtBoxWidth = RYU_IDLE_HURT_W;

  // Getting memory for idle bitmaps
  ryu->movesSprites[STEADY].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (ryu->movesSprites[STEADY].sprites == NULL) exit(1);

  for (int i = 0; i < 4; i++)
    ryu->movesSprites[STEADY].sprites[i] =
        grabSprite(ryu->sheet, RYU_IDLE_X[i], RYU_IDLE_Y[i], RYU_IDLE_DRAW_W,
                   RYU_IDLE_DRAW_H);

  /* ------------------- WALKING THINGS -------------------- */
  ryu->movesSprites[WALKING].numFrames = 5;
  ryu->movesSprites[WALKING].currentFrame = 0;

  // Draw box width and height information
  ryu->movesSprites[WALKING].drawBoxHeight = RYU_WALK_DRAW_H;
  ryu->movesSprites[WALKING].drawBoxWidth = RYU_WALK_DRAW_W;

  // Hurt box width and height information
  ryu->movesSprites[WALKING].hurtBoxHeight = RYU_WALK_HURT_H;
  ryu->movesSprites[WALKING].hurtBoxWidth = RYU_WALK_HURT_W;

  // Getting memory for the sprites
  ryu->movesSprites[WALKING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 5);
  if (ryu->movesSprites[WALKING].sprites == NULL) exit(1);

  for (int i = 0; i < 5; i++)
    ryu->movesSprites[WALKING].sprites[i] =
        grabSprite(ryu->sheet, RYU_WALK_X[i], RYU_WALK_Y[i], RYU_WALK_DRAW_W,
                   RYU_WALK_DRAW_H);

  /* ------------------- CROUCHING THINGS ------------------- */
  ryu->movesSprites[CROUCHING].numFrames = 1;
  ryu->movesSprites[CROUCHING].currentFrame = 0;

  // Draw box width and height information
  ryu->movesSprites[CROUCHING].drawBoxHeight = RYU_CROUCH_DRAW_H;
  ryu->movesSprites[CROUCHING].drawBoxWidth = RYU_CROUCH_DRAW_W;

  // Hurt box width and height information
  ryu->movesSprites[CROUCHING].hurtBoxHeight = RYU_CROUCH_HURT_H;
  ryu->movesSprites[CROUCHING].hurtBoxWidth = RYU_CROUCH_HURT_W;

  // Getting memory for the sprites
  ryu->movesSprites[CROUCHING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 1);
  if (ryu->movesSprites[CROUCHING].sprites == NULL) exit(1);

  ryu->movesSprites[CROUCHING].sprites[0] =
      grabSprite(ryu->sheet, RYU_CROUCH_X[0], RYU_CROUCH_Y[0],
                 RYU_CROUCH_DRAW_W, RYU_CROUCH_DRAW_H);

  /* ------------------- PUNCHING THINGS -------------------- */
  ryu->movesSprites[PUNCHING].numFrames = 3;
  ryu->movesSprites[PUNCHING].currentFrame = 0;

  // Draw box width and height information
  ryu->movesSprites[PUNCHING].drawBoxHeight = RYU_PUNCH_DRAW_H;
  ryu->movesSprites[PUNCHING].drawBoxWidth = RYU_PUNCH_DRAW_W;

  // Hurt box width and height information
  ryu->movesSprites[PUNCHING].hurtBoxHeight = RYU_PUNCH_HURT_H;
  ryu->movesSprites[PUNCHING].hurtBoxWidth = RYU_PUNCH_HURT_W;

  ryu->movesSprites[PUNCHING].hitBox_Y = 17;
  ryu->movesSprites[PUNCHING].hitBoxWidth = 19;
  ryu->movesSprites[PUNCHING].hitBoxHeight = 8;

  // Getting memory for the sprites
  ryu->movesSprites[PUNCHING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (ryu->movesSprites[PUNCHING].sprites == NULL) exit(1);

  for (int i = 0; i < 3; i++)
    ryu->movesSprites[PUNCHING].sprites[i] =
        grabSprite(ryu->sheet, RYU_PUNCH_X[i], RYU_PUNCH_Y[i], RYU_PUNCH_DRAW_W,
                   RYU_PUNCH_DRAW_H);

  return ryu;
}

/*
  Free the memory that a character was being utilized by a character
*/
void characterDestroyer(CHARACTER* character) { free(character); }
