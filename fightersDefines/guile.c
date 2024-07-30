#include "guile.h"

/* -------------- STEADY ----------------- */
const short GUILE_IDLE_X[3] = {2, 54, 109};
const short GUILE_IDLE_Y[3] = {23, 22, 22};
const short GUILE_IDLE_DRAW_W_ARRAY[3] = {48, 47, 48};
const short GUILE_IDLE_DRAW_H_ARRAY[3] = {81, 82, 82};
//  const short GUILE_IDLE_HURT_W[4] = {31, 36, 35, 35};
//  const short GUILE_IDLE_HURT_H[4] = {80, 80, 79, 80};

/* ---------------- WALKING ---------------- */
const short GUILE_WALK_X[5] = {166, 219, 273, 327, 385};
const short GUILE_WALK_Y[5] = {22, 21, 20, 21, 23};
const short GUILE_WALK_DRAW_W_ARRAY[5] = {47, 47, 47, 47, 48};
const short GUILE_WALK_DRAW_H_ARRAY[5] = {82, 83, 84, 83, 81};
//  const short GUILE_WALK_HURT_W[5] = {30, 37, 37, 32, 31};
//  const short GUILE_WALK_HURT_H[5] = {73, 78, 79, 78, 79};

/* --------------- CROUCHING --------------- */
const short GUILE_CROUCH_X[1] = {1125};
const short GUILE_CROUCH_Y[1] = {50};
const short GUILE_CROUCH_DRAW_W_ARRAY[1] = {45};
const short GUILE_CROUCH_DRAW_H_ARRAY[1] = {54};
//  const short GUILE_CROUCH_HURT_W[1] = {35};
//  const short GUILE_CROUCH_HURT_H[1] = {53};

/* --------------- JUMPING ---------------- */
const short GUILE_JUMP_X[5] = {539, 586, 626, 662, 698};
const short GUILE_JUMP_Y[5] = {10, 15, 17, 15, 10};
const short GUILE_JUMP_DRAW_W_ARRAY[5] = {40, 32, 31, 32, 40};
const short GUILE_JUMP_DRAW_H_ARRAY[5] = {93, 80, 58, 80, 94};

/* --------------- GOT HIT ---------------- */
const short GUILE_HIT_X[3] = {3, 52, 103};
const short GUILE_HIT_Y[3] = {844, 852, 863};
const short GUILE_HIT_DRAW_W_ARRAY[3] = {43, 46, 62};
const short GUILE_HIT_DRAW_H_ARRAY[3] = {75, 67, 56};

/* ---------------- GOT FACE HIT -------------- */
const short GUILE_FACE_HIT_X[3] = {173, 233, 300};
const short GUILE_FACE_HIT_Y[3] = {838, 846, 844};
const short GUILE_FACE_HIT_DRAW_W_ARRAY[3] = {56, 60, 66};
const short GUILE_FACE_HIT_DRAW_H_ARRAY[3] = {81, 73, 75};

/* ---------------- DEFENDING -------------- */
const short GUILE_DEFENDING_X[1] = {1178};
const short GUILE_DEFENDING_Y[1] = {32};
const short GUILE_DEFENDING_DRAW_W_ARRAY[1] = {51};
const short GUILE_DEFENDING_DRAW_H_ARRAY[1] = {72};

/* --------------- PUNCHING ------------- */
const short GUILE_PUNCH_X[3] = {2, 62, 134};
const short GUILE_PUNCH_Y[3] = {148, 148, 148};
const short GUILE_PUNCH_DRAW_W_ARRAY[3] = {54, 67, 54};
const short GUILE_PUNCH_DRAW_H_ARRAY[3] = {82, 82, 82};

/* --------------- KICKING --------------- */
const short GUILE_KICK_X[3] = {3, 55, 140};
const short GUILE_KICK_Y[3] = {271, 271, 271};
const short GUILE_KICK_DRAW_W_ARRAY[3] = {43, 80, 43};
const short GUILE_KICK_DRAW_H_ARRAY[3] = {84, 84, 84};

/*
  Initialize GUILE
*/
FIGHTER_SPRITES* initGuile() {
  FIGHTER_SPRITES* guile = (FIGHTER_SPRITES*)malloc(sizeof(FIGHTER_SPRITES));
  if (guile == NULL) exit(1);

  guile->sheet = al_load_bitmap("./images/fighters/guileSheet.png");
  alCheckInit(guile->sheet, "guile sprite sheet");
  al_convert_mask_to_alpha(guile->sheet, al_map_rgb(72, 152, 224));

  /* ------------------- IDLE THINGS ---------------------- */

  // Getting memory for idle bitmaps
  guile->movesSprites[STEADY].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (guile->movesSprites[STEADY].sprites == NULL) exit(1);

  guile->movesSprites[STEADY].modAnimation = 10;

  movimentSpritesInit(guile, STEADY, 3, 0, GUILE_IDLE_DRAW_H, GUILE_IDLE_DRAW_W,
                      GUILE_IDLE_HURT_H, GUILE_IDLE_HURT_W, GUILE_IDLE_X,
                      GUILE_IDLE_Y);

  /* ------------------- WALKING THINGS -------------------- */

  // Getting memory for the sprites
  guile->movesSprites[WALKING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 5);
  if (guile->movesSprites[WALKING].sprites == NULL) exit(1);

  guile->movesSprites[WALKING].modAnimation = 4;

  movimentSpritesInit(guile, WALKING, 5, 0, GUILE_WALK_DRAW_H,
                      GUILE_WALK_DRAW_W, GUILE_WALK_HURT_H, GUILE_WALK_HURT_W,
                      GUILE_WALK_X, GUILE_WALK_Y);

  /* -------------------- JUMPING --------------------- */

  // Getting memory for the sprites
  guile->movesSprites[JUMPING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 5);
  if (guile->movesSprites[JUMPING].sprites == NULL) exit(1);

  guile->movesSprites[JUMPING].modAnimation = 5;

  attackSpritesInit(guile, JUMPING, 5, 0, GUILE_JUMP_DRAW_H, GUILE_JUMP_DRAW_W,
                    GUILE_JUMP_HURT_H, GUILE_JUMP_HURT_W, GUILE_JUMP_X,
                    GUILE_JUMP_Y, 0, 0, 0, GUILE_JUMP_DRAW_W_ARRAY,
                    GUILE_JUMP_DRAW_H_ARRAY);

  /* ------------------- CROUCHING THINGS ------------------- */

  // Getting memory for the sprites
  guile->movesSprites[CROUCHING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 1);
  if (guile->movesSprites[CROUCHING].sprites == NULL) exit(1);

  movimentSpritesInit(guile, CROUCHING, 1, 0, GUILE_CROUCH_DRAW_H,
                      GUILE_CROUCH_DRAW_W, GUILE_CROUCH_HURT_H,
                      GUILE_CROUCH_HURT_W, GUILE_CROUCH_X, GUILE_CROUCH_Y);

  /* --------------------- GOT HIT ------------------- */

  // Getting memory for the sprites
  guile->movesSprites[GOT_HIT].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (guile->movesSprites[GOT_HIT].sprites == NULL) exit(1);

  guile->movesSprites[GOT_HIT].modAnimation = 3;

  attackSpritesInit(guile, GOT_HIT, 3, 0, GUILE_HIT_DRAW_H, GUILE_HIT_DRAW_W,
                    GUILE_HIT_HURT_H, GUILE_HIT_HURT_W, GUILE_HIT_X,
                    GUILE_HIT_Y, 0, 0, 0, GUILE_HIT_DRAW_W_ARRAY,
                    GUILE_HIT_DRAW_H_ARRAY);

  /* --------------------- GOT FACE HIT ------------------- */

  // Getting memory for the sprites
  guile->movesSprites[GOT_FACE_HIT].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (guile->movesSprites[GOT_FACE_HIT].sprites == NULL) exit(1);

  guile->movesSprites[GOT_FACE_HIT].modAnimation = 3;

  attackSpritesInit(guile, GOT_FACE_HIT, 3, 0, GUILE_FACE_HIT_DRAW_H,
                    GUILE_FACE_HIT_DRAW_W, GUILE_FACE_HIT_HURT_H,
                    GUILE_FACE_HIT_HURT_W, GUILE_FACE_HIT_X, GUILE_FACE_HIT_Y,
                    0, 0, 0, GUILE_FACE_HIT_DRAW_W_ARRAY,
                    GUILE_FACE_HIT_DRAW_H_ARRAY);

  /* --------------------- DEFENDING ------------------- */

  // Getting memory for the sprites
  guile->movesSprites[DEFENDING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 1);
  if (guile->movesSprites[DEFENDING].sprites == NULL) exit(1);

  attackSpritesInit(guile, DEFENDING, 1, 0, GUILE_DEFENDING_DRAW_H,
                    GUILE_DEFENDING_DRAW_W, GUILE_DEFENDING_HURT_H,
                    GUILE_DEFENDING_HURT_W, GUILE_DEFENDING_X,
                    GUILE_DEFENDING_Y, 0, 0, 0, GUILE_DEFENDING_DRAW_W_ARRAY,
                    GUILE_DEFENDING_DRAW_H_ARRAY);

  /* ------------------- PUNCHING THINGS -------------------- */

  // Getting memory for the sprites
  guile->movesSprites[PUNCHING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (guile->movesSprites[PUNCHING].sprites == NULL) exit(1);

  guile->movesSprites[PUNCHING].modAnimation = 3;

  attackSpritesInit(guile, PUNCHING, 3, 0, GUILE_PUNCH_DRAW_H,
                    GUILE_PUNCH_DRAW_W, GUILE_PUNCH_HURT_H, GUILE_PUNCH_HURT_W,
                    GUILE_PUNCH_X, GUILE_PUNCH_Y, 27, 11, 10,
                    GUILE_PUNCH_DRAW_W_ARRAY, GUILE_PUNCH_DRAW_H_ARRAY);

  /* ------------------- KICKING THINGS ----------------------- */

  // Getting memory for sprites
  guile->movesSprites[KICKING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (guile->movesSprites[KICKING].sprites == NULL) exit(1);

  guile->movesSprites[KICKING].modAnimation = 3;

  attackSpritesInit(guile, KICKING, 3, 0, GUILE_KICK_DRAW_H, GUILE_KICK_DRAW_W,
                    GUILE_KICK_HURT_H, GUILE_KICK_HURT_W, GUILE_KICK_X,
                    GUILE_KICK_Y, 37, 25, 30, GUILE_KICK_DRAW_W_ARRAY,
                    GUILE_KICK_DRAW_H_ARRAY);
  return guile;
}
