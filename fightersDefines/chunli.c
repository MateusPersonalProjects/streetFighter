#include "chunli.h"

/* -------------- STEADY ----------------- */
const short CHUNLI_IDLE_X[4] = {4, 57, 109, 162};
const short CHUNLI_IDLE_Y[4] = {35, 34, 33, 34};
const short CHUNLI_IDLE_DRAW_W[4] = {46, 46, 46, 46};
const short CHUNLI_IDLE_DRAW_H[4] = {77, 78, 79, 78};

/* ---------------- WALKING ---------------- */
const short CHUNLI_WALK_X[8] = {220, 276, 337, 394, 452, 509, 565, 622};
const short CHUNLI_WALK_Y[8] = {36, 36, 32, 33, 34, 33, 32, 33};
const short CHUNLI_WALK_DRAW_W[8] = {48, 49, 50, 51, 51, 51, 50, 49};
const short CHUNLI_WALK_DRAW_H[8] = {76, 79, 80, 80, 78, 79, 80, 79};
//  const short CHUNLI_WALK_HURT_W[5] = {30, 37, 37, 32, 31};
//  const short CHUNLI_WALK_HURT_H[5] = {73, 78, 79, 78, 79};

/* --------------- CROUCHING --------------- */
const short CHUNLI_CROUCH_X[1] = {1362};
const short CHUNLI_CROUCH_Y[1] = {52};
// const short CHUNLI_CROUCH_DRAW_W[1] = {43};
// const short CHUNLI_CROUCH_DRAW_H[1] = {55};
//  const short CHUNLI_CROUCH_HURT_W[1] = {35};
//  const short CHUNLI_CROUCH_HURT_H[1] = {53};

/* --------------- JUMPING ---------------- */
const short CHUNLI_JUMP_X[7] = {912, 950, 1013, 1086, 1125, 1194, 1272};
const short CHUNLI_JUMP_Y[7] = {17, 22, 24, 15, 33, 39, 17};
const short CHUNLI_JUMP_DRAW_W_ARRAY[7] = {29, 52, 64, 31, 63, 71, 29};
const short CHUNLI_JUMP_DRAW_H_ARRAY[7] = {95, 74, 77, 92, 71, 63, 95};

/* --------------- GOT HIT ---------------- */
const short CHUNLI_HIT_X[2] = {5, 62};
const short CHUNLI_HIT_Y[2] = {867, 871};
const short CHUNLI_HIT_DRAW_W_ARRAY[2] = {53, 65};
const short CHUNLI_HIT_DRAW_H_ARRAY[2] = {68, 64};

/* ---------------- GOT FACE HIT -------------- */
const short CHUNLI_FACE_HIT_X[2] = {137, 187};
const short CHUNLI_FACE_HIT_Y[2] = {852, 860};
const short CHUNLI_FACE_HIT_DRAW_W_ARRAY[2] = {46, 59};
const short CHUNLI_FACE_HIT_DRAW_H_ARRAY[2] = {83, 75};

/* ---------------- DEFENDING -------------- */
const short CHUNLI_DEFENDING_X[1] = {1211};
const short CHUNLI_DEFENDING_Y[1] = {16};
const short CHUNLI_DEFENDING_DRAW_W_ARRAY[1] = {43};
const short CHUNLI_DEFENDING_DRAW_H_ARRAY[1] = {83};

/* --------------- PUNCHING ------------- */
const short CHUNLI_PUNCH_X[3] = {3, 52, 117};
const short CHUNLI_PUNCH_Y[3] = {134, 134, 134};
const short CHUNLI_PUNCH_DRAW_W_ARRAY[3] = {43, 57, 43};
const short CHUNLI_PUNCH_DRAW_H_ARRAY[3] = {81, 81, 81};

/* --------------- KICKING --------------- */
const short CHUNLI_KICK_X[3] = {6, 62, 135};
const short CHUNLI_KICK_Y[3] = {261, 259, 261};
const short CHUNLI_KICK_DRAW_W_ARRAY[3] = {49, 67, 49};
const short CHUNLI_KICK_DRAW_H_ARRAY[3] = {85, 87, 85};

/*
  Initialize CHUNLI
*/
FIGHTER_SPRITES* initChunli() {
  FIGHTER_SPRITES* chunli = (FIGHTER_SPRITES*)malloc(sizeof(FIGHTER_SPRITES));
  if (chunli == NULL) exit(1);

  chunli->sheet = al_load_bitmap("./images/fighters/chunliSheet.png");
  alCheckInit(chunli->sheet, "chunli sprite sheet");
  al_convert_mask_to_alpha(chunli->sheet, al_map_rgb(0, 0, 0));

  /* ------------------- IDLE THINGS ---------------------- */

  // Getting memory for idle bitmaps
  chunli->movesSprites[STEADY].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (chunli->movesSprites[STEADY].sprites == NULL) exit(1);

  movimentSpritesInit(chunli, STEADY, 4, 0, CHUNLI_IDLE_DRAW_H[2], CHUNLI_IDLE_DRAW_W[0],
                      CHUNLI_IDLE_HURT_H, CHUNLI_IDLE_HURT_W, CHUNLI_IDLE_X, CHUNLI_IDLE_Y);

  /* ------------------- WALKING THINGS -------------------- */

  // Getting memory for the sprites
  chunli->movesSprites[WALKING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 8);
  if (chunli->movesSprites[WALKING].sprites == NULL) exit(1);

  movimentSpritesInit(chunli, WALKING, 8, 0, CHUNLI_WALK_DRAW_H[2], CHUNLI_WALK_DRAW_W[3],
                      CHUNLI_WALK_HURT_H, CHUNLI_WALK_HURT_W, CHUNLI_WALK_X, CHUNLI_WALK_Y);

  /* -------------------- JUMPING --------------------- */

  // Getting memory for the sprites
  chunli->movesSprites[JUMPING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 7);
  if (chunli->movesSprites[JUMPING].sprites == NULL) exit(1);

  attackSpritesInit(chunli, JUMPING, 7, 0, CHUNLI_JUMP_DRAW_H, CHUNLI_JUMP_DRAW_W,
                    CHUNLI_JUMP_HURT_H, CHUNLI_JUMP_HURT_W, CHUNLI_JUMP_X, CHUNLI_JUMP_Y, 0,
                    0, 0, CHUNLI_JUMP_DRAW_W_ARRAY, CHUNLI_JUMP_DRAW_H_ARRAY);

  /* ------------------- CROUCHING THINGS ------------------- */

  // Getting memory for the sprites
  chunli->movesSprites[CROUCHING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 1);
  if (chunli->movesSprites[CROUCHING].sprites == NULL) exit(1);

  movimentSpritesInit(chunli, CROUCHING, 1, 0, CHUNLI_CROUCH_DRAW_H,
                      CHUNLI_CROUCH_DRAW_W, CHUNLI_CROUCH_HURT_H, CHUNLI_CROUCH_HURT_W,
                      CHUNLI_CROUCH_X, CHUNLI_CROUCH_Y);

  /* --------------------- GOT HIT ------------------- */

  // Getting memory for the sprites
  chunli->movesSprites[GOT_HIT].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 2);
  if (chunli->movesSprites[GOT_HIT].sprites == NULL) exit(1);

  attackSpritesInit(chunli, GOT_HIT, 2, 0, CHUNLI_HIT_DRAW_H, CHUNLI_HIT_DRAW_W,
                    CHUNLI_HIT_HURT_H, CHUNLI_HIT_HURT_W, CHUNLI_HIT_X, CHUNLI_HIT_Y, 0, 0,
                    0, CHUNLI_HIT_DRAW_W_ARRAY, CHUNLI_HIT_DRAW_H_ARRAY);

  /* --------------------- GOT FACE HIT ------------------- */

  // Getting memory for the sprites
  chunli->movesSprites[GOT_FACE_HIT].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (chunli->movesSprites[GOT_FACE_HIT].sprites == NULL) exit(1);

  attackSpritesInit(chunli, GOT_FACE_HIT, 4, 0, CHUNLI_FACE_HIT_DRAW_H,
                    CHUNLI_FACE_HIT_DRAW_W, CHUNLI_FACE_HIT_HURT_H,
                    CHUNLI_FACE_HIT_HURT_W, CHUNLI_FACE_HIT_X, CHUNLI_FACE_HIT_Y, 0, 0,
                    0, CHUNLI_FACE_HIT_DRAW_W_ARRAY, CHUNLI_FACE_HIT_DRAW_H_ARRAY);

  /* --------------------- DEFENDING ------------------- */

  // Getting memory for the sprites
  chunli->movesSprites[DEFENDING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 1);
  if (chunli->movesSprites[DEFENDING].sprites == NULL) exit(1);

  attackSpritesInit(chunli, DEFENDING, 1, 0, CHUNLI_DEFENDING_DRAW_H,
                    CHUNLI_DEFENDING_DRAW_W, CHUNLI_DEFENDING_HURT_H,
                    CHUNLI_DEFENDING_HURT_W, CHUNLI_DEFENDING_X, CHUNLI_DEFENDING_Y, 0,
                    0, 0, CHUNLI_DEFENDING_DRAW_W_ARRAY,
                    CHUNLI_DEFENDING_DRAW_H_ARRAY);

  /* ------------------- PUNCHING THINGS -------------------- */

  // Getting memory for the sprites
  chunli->movesSprites[PUNCHING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (chunli->movesSprites[PUNCHING].sprites == NULL) exit(1);

  attackSpritesInit(chunli, PUNCHING, 3, 0, CHUNLI_PUNCH_DRAW_H, CHUNLI_PUNCH_DRAW_W,
                    CHUNLI_PUNCH_HURT_H, CHUNLI_PUNCH_HURT_W, CHUNLI_PUNCH_X,
                    CHUNLI_PUNCH_Y, 19, 8, 17, CHUNLI_PUNCH_DRAW_W_ARRAY,
                    CHUNLI_PUNCH_DRAW_H_ARRAY);

  /* ------------------- KICKING THINGS ----------------------- */

  // Getting memory for sprites
  chunli->movesSprites[KICKING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (chunli->movesSprites[KICKING].sprites == NULL) exit(1);

  attackSpritesInit(chunli, KICKING, 3, 0, CHUNLI_KICK_DRAW_H, CHUNLI_KICK_DRAW_W,
                    CHUNLI_KICK_HURT_H, CHUNLI_KICK_HURT_W, CHUNLI_KICK_X, CHUNLI_KICK_Y,
                    28, 12, 1, CHUNLI_KICK_DRAW_W_ARRAY, CHUNLI_KICK_DRAW_H_ARRAY);
  return chunli;
}
