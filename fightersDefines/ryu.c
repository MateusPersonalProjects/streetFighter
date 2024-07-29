#include "ryu.h"

/* -------------- STEADY ----------------- */
const short RYU_IDLE_X[4] = {6, 55, 105, 154};
const short RYU_IDLE_Y[4] = {18, 19, 18, 17};
// const short RYU_IDLE_DRAW_W[4] = {43, 43, 43, 43};
// const short RYU_IDLE_DRAW_H[4] = {81, 80, 82, 82};
//  const short RYU_IDLE_HURT_W[4] = {31, 36, 35, 35};
//  const short RYU_IDLE_HURT_H[4] = {80, 80, 79, 80};

/* ---------------- WALKING ---------------- */
const short RYU_WALK_X[5] = {205, 252, 301, 351, 401};
const short RYU_WALK_Y[5] = {24, 19, 18, 19, 19};
// const short RYU_WALK_DRAW_W[5] = {43, 43, 43, 43, 43};
// const short RYU_WALK_DRAW_H[5] = {75, 80, 81, 80, 80};
//  const short RYU_WALK_HURT_W[5] = {30, 37, 37, 32, 31};
//  const short RYU_WALK_HURT_H[5] = {73, 78, 79, 78, 79};

/* --------------- CROUCHING --------------- */
const short RYU_CROUCH_X[1] = {1160};
const short RYU_CROUCH_Y[1] = {44};
// const short RYU_CROUCH_DRAW_W[1] = {43};
// const short RYU_CROUCH_DRAW_H[1] = {55};
//  const short RYU_CROUCH_HURT_W[1] = {35};
//  const short RYU_CROUCH_HURT_H[1] = {53};

/* --------------- JUMPING ---------------- */
const short RYU_JUMP_X[7] = {452, 503, 545, 582, 619, 656, 696};
const short RYU_JUMP_Y[7] = {24, 9, 17, 19, 17, 9, 24};
const short RYU_JUMP_DRAW_W_ARRAY[7] = {43, 33, 29, 31, 29, 33, 43};
const short RYU_JUMP_DRAW_H_ARRAY[7] = {75, 90, 78, 67, 78, 90, 75};

/* --------------- GOT HIT ---------------- */
const short RYU_HIT_X[4] = {5, 53, 106, 163};
const short RYU_HIT_Y[4] = {760, 761, 771, 754};
const short RYU_HIT_DRAW_W_ARRAY[4] = {43, 47, 49, 43};
const short RYU_HIT_DRAW_H_ARRAY[4] = {76, 75, 65, 82};

/* ---------------- GOT FACE HIT -------------- */
const short RYU_FACE_HIT_X[4] = {217, 271, 328, 391};
const short RYU_FACE_HIT_Y[4] = {757, 757, 753, 754};
const short RYU_FACE_HIT_DRAW_W_ARRAY[4] = {48, 52, 58, 43};
const short RYU_FACE_HIT_DRAW_H_ARRAY[4] = {79, 79, 83, 82};

/* ---------------- DEFENDING -------------- */
const short RYU_DEFENDING_X[1] = {1211};
const short RYU_DEFENDING_Y[1] = {16};
const short RYU_DEFENDING_DRAW_W_ARRAY[1] = {43};
const short RYU_DEFENDING_DRAW_H_ARRAY[1] = {83};

/* --------------- PUNCHING ------------- */
const short RYU_PUNCH_X[3] = {3, 52, 117};
const short RYU_PUNCH_Y[3] = {134, 134, 134};
const short RYU_PUNCH_DRAW_W_ARRAY[3] = {43, 57, 43};
const short RYU_PUNCH_DRAW_H_ARRAY[3] = {81, 81, 81};

/* --------------- KICKING --------------- */
const short RYU_KICK_X[3] = {6, 62, 135};
const short RYU_KICK_Y[3] = {261, 259, 261};
const short RYU_KICK_DRAW_W_ARRAY[3] = {49, 67, 49};
const short RYU_KICK_DRAW_H_ARRAY[3] = {85, 87, 85};

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

  /* -------------------- JUMPING --------------------- */

  // Getting memory for the sprites
  ryu->movesSprites[JUMPING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 7);
  if (ryu->movesSprites[JUMPING].sprites == NULL) exit(1);

  attackSpritesInit(ryu, JUMPING, 7, 0, RYU_JUMP_DRAW_H, RYU_JUMP_DRAW_W,
                    RYU_JUMP_HURT_H, RYU_JUMP_HURT_W, RYU_JUMP_X, RYU_JUMP_Y, 0,
                    0, 0, RYU_JUMP_DRAW_W_ARRAY, RYU_JUMP_DRAW_H_ARRAY);

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
