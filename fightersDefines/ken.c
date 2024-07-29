#include "ken.h"

/* -------------- STEADY ----------------- */
const short KEN_IDLE_X[4] = {6, 55, 105, 154};
const short KEN_IDLE_Y[4] = {18, 19, 18, 17};
// const short KEN_IDLE_DRAW_W[4] = {43, 43, 43, 43};
// const short KEN_IDLE_DRAW_H[4] = {81, 80, 82, 82};
//  const short KEN_IDLE_HURT_W[4] = {31, 36, 35, 35};
//  const short KEN_IDLE_HURT_H[4] = {80, 80, 79, 80};

/* ---------------- WALKING ---------------- */
const short KEN_WALK_X[5] = {205, 252, 301, 351, 401};
const short KEN_WALK_Y[5] = {24, 19, 18, 19, 19};
// const short KEN_WALK_DRAW_W[5] = {43, 43, 43, 43, 43};
// const short KEN_WALK_DRAW_H[5] = {75, 80, 81, 80, 80};
//  const short KEN_WALK_HURT_W[5] = {30, 37, 37, 32, 31};
//  const short KEN_WALK_HURT_H[5] = {73, 78, 79, 78, 79};

/* --------------- CROUCHING --------------- */
const short KEN_CROUCH_X[1] = {1160};
const short KEN_CROUCH_Y[1] = {44};
// const short KEN_CROUCH_DRAW_W[1] = {43};
// const short KEN_CROUCH_DRAW_H[1] = {55};
//  const short KEN_CROUCH_HURT_W[1] = {35};
//  const short KEN_CROUCH_HURT_H[1] = {53};

/* --------------- JUMPING ---------------- */
const short KEN_JUMP_X[7] = {452, 503, 545, 582, 619, 656, 696};
const short KEN_JUMP_Y[7] = {24, 9, 17, 19, 17, 9, 24};
const short KEN_JUMP_DRAW_W_ARRAY[7] = {43, 33, 29, 31, 29, 33, 43};
const short KEN_JUMP_DRAW_H_ARRAY[7] = {75, 90, 78, 67, 78, 90, 75};

/* --------------- GOT HIT ---------------- */
const short KEN_HIT_X[4] = {5, 53, 106, 163};
const short KEN_HIT_Y[4] = {785, 789, 795, 779};
const short KEN_HIT_DRAW_W_ARRAY[4] = {43, 47, 49, 43};
const short KEN_HIT_DRAW_H_ARRAY[4] = {76, 75, 65, 82};

/* ---------------- GOT FACE HIT -------------- */
const short KEN_FACE_HIT_X[4] = {217, 270, 326, 391};
const short KEN_FACE_HIT_Y[4] = {782, 783, 777, 779};
const short KEN_FACE_HIT_DRAW_W_ARRAY[4] = {48, 53, 60, 43};
const short KEN_FACE_HIT_DRAW_H_ARRAY[4] = {79, 77, 83, 81};

/* ---------------- DEFENDING -------------- */
const short KEN_DEFENDING_X[1] = {1211};
const short KEN_DEFENDING_Y[1] = {16};
const short KEN_DEFENDING_DRAW_W_ARRAY[1] = {43};
const short KEN_DEFENDING_DRAW_H_ARRAY[1] = {83};

/* --------------- PUNCHING ------------- */
const short KEN_PUNCH_X[3] = {3, 52, 117};
const short KEN_PUNCH_Y[3] = {134, 134, 134};
const short KEN_PUNCH_DRAW_W_ARRAY[3] = {43, 57, 43};
const short KEN_PUNCH_DRAW_H_ARRAY[3] = {81, 81, 81};

/* --------------- KICKING --------------- */
const short KEN_KICK_X[3] = {6, 62, 135};
const short KEN_KICK_Y[3] = {261, 259, 261};
const short KEN_KICK_DRAW_W_ARRAY[3] = {49, 67, 49};
const short KEN_KICK_DRAW_H_ARRAY[3] = {85, 87, 85};

/*
  Initialize KEN
*/
FIGHTER_SPRITES* initKen() {
  FIGHTER_SPRITES* ken = (FIGHTER_SPRITES*)malloc(sizeof(FIGHTER_SPRITES));
  if (ken == NULL) exit(1);

  ken->sheet = al_load_bitmap("./images/fighters/kenSheet.png");
  alCheckInit(ken->sheet, "ken sprite sheet");
  al_convert_mask_to_alpha(ken->sheet, al_map_rgb(128, 184, 168));

  /* ------------------- IDLE THINGS ---------------------- */

  // Getting memory for idle bitmaps
  ken->movesSprites[STEADY].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (ken->movesSprites[STEADY].sprites == NULL) exit(1);

  ken->movesSprites[STEADY].modAnimation = 10;

  movimentSpritesInit(ken, STEADY, 4, 0, KEN_IDLE_DRAW_H, KEN_IDLE_DRAW_W,
                      KEN_IDLE_HURT_H, KEN_IDLE_HURT_W, KEN_IDLE_X, KEN_IDLE_Y);

  /* ------------------- WALKING THINGS -------------------- */

  // Getting memory for the sprites
  ken->movesSprites[WALKING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 5);
  if (ken->movesSprites[WALKING].sprites == NULL) exit(1);

  ken->movesSprites[WALKING].modAnimation = 4;

  movimentSpritesInit(ken, WALKING, 5, 0, KEN_WALK_DRAW_H, KEN_WALK_DRAW_W,
                      KEN_WALK_HURT_H, KEN_WALK_HURT_W, KEN_WALK_X, KEN_WALK_Y);

  /* -------------------- JUMPING --------------------- */

  // Getting memory for the sprites
  ken->movesSprites[JUMPING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 7);
  if (ken->movesSprites[JUMPING].sprites == NULL) exit(1);

  ken->movesSprites[JUMPING].modAnimation = 5;

  attackSpritesInit(ken, JUMPING, 7, 0, KEN_JUMP_DRAW_H, KEN_JUMP_DRAW_W,
                    KEN_JUMP_HURT_H, KEN_JUMP_HURT_W, KEN_JUMP_X, KEN_JUMP_Y, 0,
                    0, 0, KEN_JUMP_DRAW_W_ARRAY, KEN_JUMP_DRAW_H_ARRAY);

  /* ------------------- CROUCHING THINGS ------------------- */

  // Getting memory for the sprites
  ken->movesSprites[CROUCHING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 1);
  if (ken->movesSprites[CROUCHING].sprites == NULL) exit(1);

  movimentSpritesInit(ken, CROUCHING, 1, 0, KEN_CROUCH_DRAW_H,
                      KEN_CROUCH_DRAW_W, KEN_CROUCH_HURT_H, KEN_CROUCH_HURT_W,
                      KEN_CROUCH_X, KEN_CROUCH_Y);

  /* --------------------- GOT HIT ------------------- */

  // Getting memory for the sprites
  ken->movesSprites[GOT_HIT].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (ken->movesSprites[GOT_HIT].sprites == NULL) exit(1);

  ken->movesSprites[GOT_HIT].modAnimation = 3;

  attackSpritesInit(ken, GOT_HIT, 4, 0, KEN_HIT_DRAW_H, KEN_HIT_DRAW_W,
                    KEN_HIT_HURT_H, KEN_HIT_HURT_W, KEN_HIT_X, KEN_HIT_Y, 0, 0,
                    0, KEN_HIT_DRAW_W_ARRAY, KEN_HIT_DRAW_H_ARRAY);

  /* --------------------- GOT FACE HIT ------------------- */

  // Getting memory for the sprites
  ken->movesSprites[GOT_FACE_HIT].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (ken->movesSprites[GOT_FACE_HIT].sprites == NULL) exit(1);

  ken->movesSprites[GOT_FACE_HIT].modAnimation = 3;

  attackSpritesInit(ken, GOT_FACE_HIT, 4, 0, KEN_FACE_HIT_DRAW_H,
                    KEN_FACE_HIT_DRAW_W, KEN_FACE_HIT_HURT_H,
                    KEN_FACE_HIT_HURT_W, KEN_FACE_HIT_X, KEN_FACE_HIT_Y, 0, 0,
                    0, KEN_FACE_HIT_DRAW_W_ARRAY, KEN_FACE_HIT_DRAW_H_ARRAY);

  /* --------------------- DEFENDING ------------------- */

  // Getting memory for the sprites
  ken->movesSprites[DEFENDING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 1);
  if (ken->movesSprites[DEFENDING].sprites == NULL) exit(1);

  attackSpritesInit(ken, DEFENDING, 1, 0, KEN_DEFENDING_DRAW_H,
                    KEN_DEFENDING_DRAW_W, KEN_DEFENDING_HURT_H,
                    KEN_DEFENDING_HURT_W, KEN_DEFENDING_X, KEN_DEFENDING_Y, 0,
                    0, 0, KEN_DEFENDING_DRAW_W_ARRAY,
                    KEN_DEFENDING_DRAW_H_ARRAY);

  /* ------------------- PUNCHING THINGS -------------------- */

  // Getting memory for the sprites
  ken->movesSprites[PUNCHING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (ken->movesSprites[PUNCHING].sprites == NULL) exit(1);

  ken->movesSprites[PUNCHING].modAnimation = 3;

  attackSpritesInit(ken, PUNCHING, 3, 0, KEN_PUNCH_DRAW_H, KEN_PUNCH_DRAW_W,
                    KEN_PUNCH_HURT_H, KEN_PUNCH_HURT_W, KEN_PUNCH_X,
                    KEN_PUNCH_Y, 19, 8, 17, KEN_PUNCH_DRAW_W_ARRAY,
                    KEN_PUNCH_DRAW_H_ARRAY);

  /* ------------------- KICKING THINGS ----------------------- */

  // Getting memory for sprites
  ken->movesSprites[KICKING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (ken->movesSprites[KICKING].sprites == NULL) exit(1);

  ken->movesSprites[KICKING].modAnimation = 3;

  attackSpritesInit(ken, KICKING, 3, 0, KEN_KICK_DRAW_H, KEN_KICK_DRAW_W,
                    KEN_KICK_HURT_H, KEN_KICK_HURT_W, KEN_KICK_X, KEN_KICK_Y,
                    28, 12, 1, KEN_KICK_DRAW_W_ARRAY, KEN_KICK_DRAW_H_ARRAY);
  return ken;
}
