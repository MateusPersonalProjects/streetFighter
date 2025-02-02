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

/* ---------------- GOT CROUCH HIT -------------- */
const short GUILE_CROUCH_HIT_X[4] = {373, 373, 373, 373};
const short GUILE_CROUCH_HIT_Y[4] = {862, 862, 862, 862};
const short GUILE_CROUCH_HIT_DRAW_W_ARRAY[4] = {51, 51, 51, 51};
const short GUILE_CROUCH_HIT_DRAW_H_ARRAY[4] = {57, 57, 57, 57};

/* ---------------- DEFENDING -------------- */
const short GUILE_DEFENDING_X[4] = {1178, 1178, 1178, 1178};
const short GUILE_DEFENDING_Y[4] = {32, 32, 32, 32};
const short GUILE_DEFENDING_DRAW_W_ARRAY[4] = {51, 51, 51, 51};
const short GUILE_DEFENDING_DRAW_H_ARRAY[4] = {72, 72, 72, 72};

/* ---------------- CROUCH BLOCK -------------- */
const short GUILE_CROUCH_BLOCK_X[4] = {1238, 1238, 1238, 1238};
const short GUILE_CROUCH_BLOCK_Y[4] = {45, 45, 45, 45};
const short GUILE_CROUCH_BLOCK_DRAW_W_ARRAY[4] = {43, 43, 43, 43};
const short GUILE_CROUCH_BLOCK_DRAW_H_ARRAY[4] = {59, 59, 59, 59};

/* --------------- PUNCHING ------------- */
const short GUILE_PUNCH_X[3] = {2, 62, 134};
const short GUILE_PUNCH_Y[3] = {148, 148, 148};
const short GUILE_PUNCH_DRAW_W_ARRAY[3] = {54, 67, 54};
const short GUILE_PUNCH_DRAW_H_ARRAY[3] = {82, 82, 82};

/* --------------- CROUCH PUNCH ------------- */
const short GUILE_CROUCH_PUNCH_X[3] = {3, 65, 134};
const short GUILE_CROUCH_PUNCH_Y[3] = {435, 436, 435};
const short GUILE_CROUCH_PUNCH_DRAW_W_ARRAY[3] = {56, 64, 56};
const short GUILE_CROUCH_PUNCH_DRAW_H_ARRAY[3] = {55, 54, 55};

/* --------------- KICKING --------------- */
const short GUILE_KICK_X[3] = {3, 55, 140};
const short GUILE_KICK_Y[3] = {271, 271, 271};
const short GUILE_KICK_DRAW_W_ARRAY[3] = {43, 80, 43};
const short GUILE_KICK_DRAW_H_ARRAY[3] = {84, 84, 84};

/* --------------- JUMP KICK --------------- */
const short GUILE_JUMP_KICK_X[4] = {510, 557, 557, 659};
const short GUILE_JUMP_KICK_Y[4] = {532, 531, 531, 527};
const short GUILE_JUMP_KICK_DRAW_W_ARRAY[4] = {33, 83, 83, 53};
const short GUILE_JUMP_KICK_DRAW_H_ARRAY[4] = {50, 57, 57, 54};

/* -------------- DEAD ---------------- */
const short GUILE_DEAD_X[6] = {8, 72, 142, 231, 297, 368};
const short GUILE_DEAD_Y[6] = {976, 974, 1010, 974, 1001, 1010};
const short GUILE_DEAD_DRAW_W_ARRAY[6] = {48, 61, 83, 61, 67, 83};
const short GUILE_DEAD_DRAW_H_ARRAY[6] = {64, 52, 30, 53, 39, 30};

/* -------------- VICTORY ---------------- */
const short GUILE_VICTORY_X[8] = {461, 511, 561, 611, 661, 711, 760, 812};
const short GUILE_VICTORY_Y[8] = {945, 936, 946, 936, 946, 941, 944, 945};
const short GUILE_VICTORY_DRAW_W_ARRAY[8] = {43, 43, 43, 43, 43, 43, 43, 43};
const short GUILE_VICTORY_DRAW_H_ARRAY[8] = {97, 106, 96, 106, 96, 101, 98, 97};

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

  /* --------------------- GOT CROUCH HIT ------------------- */

  // Getting memory for the sprites
  guile->movesSprites[GOT_CROUCH_HIT].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (guile->movesSprites[GOT_CROUCH_HIT].sprites == NULL) exit(1);

  guile->movesSprites[GOT_CROUCH_HIT].modAnimation = 3;

  attackSpritesInit(guile, GOT_CROUCH_HIT, 4, 0, GUILE_CROUCH_HIT_DRAW_H,
                    GUILE_CROUCH_HIT_DRAW_W, GUILE_CROUCH_HIT_HURT_H,
                    GUILE_CROUCH_HIT_HURT_W, GUILE_CROUCH_HIT_X,
                    GUILE_CROUCH_HIT_Y, 0, 0, 0, GUILE_CROUCH_HIT_DRAW_W_ARRAY,
                    GUILE_CROUCH_HIT_DRAW_H_ARRAY);

  /* --------------------- DEFENDING ------------------- */

  // Getting memory for the sprites
  guile->movesSprites[DEFENDING].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (guile->movesSprites[DEFENDING].sprites == NULL) exit(1);

  guile->movesSprites[DEFENDING].modAnimation = 3;

  attackSpritesInit(guile, DEFENDING, 4, 0, GUILE_DEFENDING_DRAW_H,
                    GUILE_DEFENDING_DRAW_W, GUILE_DEFENDING_HURT_H,
                    GUILE_DEFENDING_HURT_W, GUILE_DEFENDING_X,
                    GUILE_DEFENDING_Y, 0, 0, 0, GUILE_DEFENDING_DRAW_W_ARRAY,
                    GUILE_DEFENDING_DRAW_H_ARRAY);

  /* --------------------- CROUCH_BLOCK ------------------- */

  // Getting memory for the sprites
  guile->movesSprites[CROUCH_BLOCK].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (guile->movesSprites[CROUCH_BLOCK].sprites == NULL) exit(1);

  guile->movesSprites[CROUCH_BLOCK].modAnimation = 3;

  attackSpritesInit(
      guile, CROUCH_BLOCK, 4, 0, GUILE_CROUCH_BLOCK_DRAW_H,
      GUILE_CROUCH_BLOCK_DRAW_W, GUILE_CROUCH_BLOCK_HURT_H,
      GUILE_CROUCH_BLOCK_HURT_W, GUILE_CROUCH_BLOCK_X, GUILE_CROUCH_BLOCK_Y, 0,
      0, 0, GUILE_CROUCH_BLOCK_DRAW_W_ARRAY, GUILE_CROUCH_BLOCK_DRAW_H_ARRAY);

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

  /* ------------------- CROUCH PUNCH THINGS -------------------- */

  // Getting memory for the sprites
  guile->movesSprites[CROUCH_PUNCH].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 3);
  if (guile->movesSprites[CROUCH_PUNCH].sprites == NULL) exit(1);

  guile->movesSprites[CROUCH_PUNCH].modAnimation = 3;

  attackSpritesInit(
      guile, CROUCH_PUNCH, 3, 0, GUILE_CROUCH_PUNCH_DRAW_H,
      GUILE_CROUCH_PUNCH_DRAW_W, GUILE_CROUCH_PUNCH_HURT_H,
      GUILE_CROUCH_PUNCH_HURT_W, GUILE_CROUCH_PUNCH_X, GUILE_CROUCH_PUNCH_Y, 22,
      9, 10, GUILE_CROUCH_PUNCH_DRAW_W_ARRAY, GUILE_CROUCH_PUNCH_DRAW_H_ARRAY);

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

  /* ------------------- JUMP KICK THINGS ----------------------- */

  // Getting memory for sprites
  guile->movesSprites[JUMP_KICK].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 4);
  if (guile->movesSprites[JUMP_KICK].sprites == NULL) exit(1);

  guile->movesSprites[JUMP_KICK].modAnimation = 3;

  attackSpritesInit(guile, JUMP_KICK, 4, 0, GUILE_JUMP_KICK_DRAW_H,
                    GUILE_JUMP_KICK_DRAW_W, GUILE_JUMP_KICK_HURT_H,
                    GUILE_JUMP_KICK_HURT_W, GUILE_JUMP_KICK_X,
                    GUILE_JUMP_KICK_Y, 37, 16, 27, GUILE_JUMP_KICK_DRAW_W_ARRAY,
                    GUILE_JUMP_KICK_DRAW_H_ARRAY);

  /* ------------------------- DEAD ---------------------------- */

  // Getting memory for sprites
  guile->movesSprites[DEAD].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 6);

  if (guile->movesSprites[DEAD].sprites == NULL) exit(1);

  guile->movesSprites[DEAD].modAnimation = 3;

  attackSpritesInit(guile, DEAD, 6, 0, GUILE_DEAD_DRAW_H, GUILE_DEAD_DRAW_W,
                    GUILE_DEAD_HURT_H, GUILE_DEAD_HURT_W, GUILE_DEAD_X,
                    GUILE_DEAD_Y, 0, 0, 0, GUILE_DEAD_DRAW_W_ARRAY,
                    GUILE_DEAD_DRAW_H_ARRAY);

  /* ------------------------- VICTORY ---------------------------- */

  // Getting memory for sprites
  guile->movesSprites[VICTORY].sprites =
      (ALLEGRO_BITMAP**)malloc(sizeof(ALLEGRO_BITMAP*) * 8);

  if (guile->movesSprites[VICTORY].sprites == NULL) exit(1);

  guile->movesSprites[VICTORY].modAnimation = 7;

  attackSpritesInit(guile, VICTORY, 8, 0, GUILE_VICTORY_DRAW_H,
                    GUILE_VICTORY_DRAW_W, GUILE_VICTORY_HURT_H,
                    GUILE_VICTORY_HURT_W, GUILE_VICTORY_X, GUILE_VICTORY_Y, 0,
                    0, 0, GUILE_VICTORY_DRAW_W_ARRAY,
                    GUILE_VICTORY_DRAW_H_ARRAY);

  return guile;
}
