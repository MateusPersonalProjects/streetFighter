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

void movimentSpritesInit(FIGHTER_SPRITES* fighter, SPRITE_LIST sprite,
                         short numFrames, short currentFrame, short draw_h,
                         short draw_w, short hurt_h, short hurt_w,
                         const short* idle_x, const short* idle_y) {
  // Gets information for animations
  fighter->movesSprites[sprite].numFrames = numFrames;
  fighter->movesSprites[sprite].currentFrame = currentFrame;

  // Gets information for the draw box
  fighter->movesSprites[sprite].drawBoxHeight = draw_h;
  fighter->movesSprites[sprite].drawBoxWidth = draw_w;

  // Gets information for the hurt box
  fighter->movesSprites[sprite].hurtBoxHeight = hurt_h;
  fighter->movesSprites[sprite].hurtBoxWidth = hurt_w;

  // Loop to grab the sprites
  for (int i = 0; i < numFrames; i++)
    fighter->movesSprites[sprite].sprites[i] =
        grabSprite(fighter->sheet, idle_x[i], idle_y[i], draw_w, draw_h);
}

void attackSpritesInit(FIGHTER_SPRITES* fighter, SPRITE_LIST sprite,
                       short numFrames, short currentFrame, short draw_h,
                       short draw_w, short hurt_h, short hurt_w,
                       const short* idle_x, const short* idle_y, short hit_w,
                       short hit_h, short hit_y, const short* draw_w_array,
                       const short* draw_h_array) {
  // Gets information for animations
  fighter->movesSprites[sprite].numFrames = numFrames;
  fighter->movesSprites[sprite].currentFrame = currentFrame;

  // Gets information for the draw box
  fighter->movesSprites[sprite].drawBoxHeight = draw_h;
  fighter->movesSprites[sprite].drawBoxWidth = draw_w;

  // Gets information for the hurt box
  fighter->movesSprites[sprite].hurtBoxHeight = hurt_h;
  fighter->movesSprites[sprite].hurtBoxWidth = hurt_w;

  // Gets information for the hit box
  fighter->movesSprites[sprite].hitBoxWidth = hit_w;
  fighter->movesSprites[sprite].hitBoxHeight = hit_h;
  fighter->movesSprites[sprite].hitBox_Y = hit_y;

  // Loop to grab the sprites
  for (int i = 0; i < numFrames; i++)
    fighter->movesSprites[sprite].sprites[i] = grabSprite(
        fighter->sheet, idle_x[i], idle_y[i], draw_w_array[i], draw_h_array[i]);
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

  // Getting memory for idle bitmaps
  ryu->movesSprites[STEADY].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (ryu->movesSprites[STEADY].sprites == NULL) exit(1);

  movimentSpritesInit(ryu, STEADY, 4, 0, RYU_IDLE_DRAW_H, RYU_IDLE_DRAW_W,
                      RYU_IDLE_HURT_H, RYU_IDLE_HURT_W, RYU_IDLE_X, RYU_IDLE_Y);

  /* ------------------- WALKING THINGS -------------------- */

  // Getting memory for the sprites
  ryu->movesSprites[WALKING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 5);
  if (ryu->movesSprites[WALKING].sprites == NULL) exit(1);

  movimentSpritesInit(ryu, WALKING, 5, 0, RYU_WALK_DRAW_H, RYU_WALK_DRAW_W,
                      RYU_WALK_HURT_H, RYU_WALK_HURT_W, RYU_WALK_X, RYU_WALK_Y);

  /* ------------------- CROUCHING THINGS ------------------- */

  // Getting memory for the sprites
  ryu->movesSprites[CROUCHING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 1);
  if (ryu->movesSprites[CROUCHING].sprites == NULL) exit(1);

  movimentSpritesInit(ryu, CROUCHING, 1, 0, RYU_CROUCH_DRAW_H,
                      RYU_CROUCH_DRAW_W, RYU_CROUCH_HURT_H, RYU_CROUCH_HURT_W,
                      RYU_CROUCH_X, RYU_CROUCH_Y);

  /* --------------------- GOT HIT ------------------- */

  // Getting memory for the sprites
  ryu->movesSprites[GOT_HIT].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (ryu->movesSprites[GOT_HIT].sprites == NULL) exit(1);

  attackSpritesInit(ryu, GOT_HIT, 4, 0, RYU_HIT_DRAW_H, RYU_HIT_DRAW_W,
                    RYU_HIT_HURT_H, RYU_HIT_HURT_W, RYU_HIT_X, RYU_HIT_Y, 0, 0,
                    0, RYU_HIT_DRAW_W_ARRAY, RYU_HIT_DRAW_H_ARRAY);

  /* --------------------- GOT FACE HIT ------------------- */

  // Getting memory for the sprites
  ryu->movesSprites[GOT_FACE_HIT].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (ryu->movesSprites[GOT_FACE_HIT].sprites == NULL) exit(1);

  attackSpritesInit(ryu, GOT_FACE_HIT, 4, 0, RYU_FACE_HIT_DRAW_H,
                    RYU_FACE_HIT_DRAW_W, RYU_FACE_HIT_HURT_H,
                    RYU_FACE_HIT_HURT_W, RYU_FACE_HIT_X, RYU_FACE_HIT_Y, 0, 0,
                    0, RYU_FACE_HIT_DRAW_W_ARRAY, RYU_FACE_HIT_DRAW_H_ARRAY);

  /* --------------------- DEFENDING ------------------- */

  // Getting memory for the sprites
  ryu->movesSprites[DEFENDING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 1);
  if (ryu->movesSprites[DEFENDING].sprites == NULL) exit(1);

  attackSpritesInit(ryu, DEFENDING, 1, 0, RYU_DEFENDING_DRAW_H,
                    RYU_DEFENDING_DRAW_W, RYU_DEFENDING_HURT_H,
                    RYU_DEFENDING_HURT_W, RYU_DEFENDING_X, RYU_DEFENDING_Y, 0,
                    0, 0, RYU_DEFENDING_DRAW_W_ARRAY,
                    RYU_DEFENDING_DRAW_H_ARRAY);

  /* ------------------- PUNCHING THINGS -------------------- */

  // Getting memory for the sprites
  ryu->movesSprites[PUNCHING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (ryu->movesSprites[PUNCHING].sprites == NULL) exit(1);

  attackSpritesInit(ryu, PUNCHING, 3, 0, RYU_PUNCH_DRAW_H, RYU_PUNCH_DRAW_W,
                    RYU_PUNCH_HURT_H, RYU_PUNCH_HURT_W, RYU_PUNCH_X,
                    RYU_PUNCH_Y, 19, 8, 17, RYU_PUNCH_DRAW_W_ARRAY,
                    RYU_PUNCH_DRAW_H_ARRAY);

  /* ------------------- KICKING THINGS ----------------------- */

  // Getting memory for sprites
  ryu->movesSprites[KICKING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (ryu->movesSprites[KICKING].sprites == NULL) exit(1);

  attackSpritesInit(ryu, KICKING, 3, 0, RYU_KICK_DRAW_H, RYU_KICK_DRAW_W,
                    RYU_KICK_HURT_H, RYU_KICK_HURT_W, RYU_KICK_X, RYU_KICK_Y,
                    28, 12, 1, RYU_KICK_DRAW_W_ARRAY, RYU_KICK_DRAW_H_ARRAY);
  return ryu;
}

/*
  Free the memory that a character was being utilized by a character
*/
void characterDestroyer(CHARACTER* character) { free(character); }
