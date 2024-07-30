#ifndef __GUILE__
#define __GUILE__
#include "../character.h"

/* -------------- IDLE ----------------- */
extern const short GUILE_IDLE_X[3];
extern const short GUILE_IDLE_Y[3];
extern const short GUILE_IDLE_DRAW_W_ARRAY[3];
extern const short GUILE_IDLE_DRAW_H_ARRAY[3];

#define GUILE_IDLE_DRAW_W 48
#define GUILE_IDLE_DRAW_H 82

#define GUILE_IDLE_HURT_W 34
#define GUILE_IDLE_HURT_H 80

/* ---------------- WALKING ---------------- */
extern const short GUILE_WALK_X[5];
extern const short GUILE_WALK_Y[5];
extern const short GUILE_WALK_DRAW_W_ARRAY[5];
extern const short GUILE_WALK_DRAW_H_ARRAY[5];

#define GUILE_WALK_DRAW_W 48
#define GUILE_WALK_DRAW_H 84

#define GUILE_WALK_HURT_W 33
#define GUILE_WALK_HURT_H 78

/* --------------- CROUCHING --------------- */
extern const short GUILE_CROUCH_X[1];
extern const short GUILE_CROUCH_Y[1];
extern const short GUILE_CROUCH_DRAW_W_ARRAY[1];
extern const short GUILE_CROUCH_DRAW_H_ARRAY[1];

#define GUILE_CROUCH_DRAW_W 45
#define GUILE_CROUCH_DRAW_H 54
//extern const short GUILE_CROUCH_HURT_W[1];
//extern const short GUILE_CROUCH_HURT_H[1];
#define GUILE_CROUCH_HURT_W 31
#define GUILE_CROUCH_HURT_H 52


/* --------------- JUMPING ---------------- */
extern const short GUILE_JUMP_X[5];
extern const short GUILE_JUMP_Y[5];
extern const short GUILE_JUMP_DRAW_W_ARRAY[5];
extern const short GUILE_JUMP_DRAW_H_ARRAY[5];

#define GUILE_JUMP_DRAW_W 40
#define GUILE_JUMP_DRAW_H 94

#define GUILE_JUMP_HURT_W 31
#define GUILE_JUMP_HURT_H 58

/* --------------- GOT HIT ---------------- */
extern const short GUILE_HIT_X[3];
extern const short GUILE_HIT_Y[3];
extern const short GUILE_HIT_DRAW_W_ARRAY[3];
extern const short GUILE_HIT_DRAW_H_ARRAY[3];

#define GUILE_HIT_DRAW_W 43
#define GUILE_HIT_DRAW_H 75

#define GUILE_HIT_HURT_W 26
#define GUILE_HIT_HURT_H 63


/* --------------- GOT FACE HIT ---------------- */
extern const short GUILE_FACE_HIT_X[3];
extern const short GUILE_FACE_HIT_Y[3];
extern const short GUILE_FACE_HIT_DRAW_W_ARRAY[3];
extern const short GUILE_FACE_HIT_DRAW_H_ARRAY[3];

#define GUILE_FACE_HIT_DRAW_W 56
#define GUILE_FACE_HIT_DRAW_H 81

#define GUILE_FACE_HIT_HURT_W 37
#define GUILE_FACE_HIT_HURT_H 78

/* ---------------- DEFENDING -------------- */
extern const short GUILE_DEFENDING_X[1];
extern const short GUILE_DEFENDING_Y[1];
extern const short GUILE_DEFENDING_DRAW_W_ARRAY[1];
extern const short GUILE_DEFENDING_DRAW_H_ARRAY[1];


#define GUILE_DEFENDING_DRAW_W 43
#define GUILE_DEFENDING_DRAW_H 83

#define GUILE_DEFENDING_HURT_W 37
#define GUILE_DEFENDING_HURT_H 81

/* -------------- PUNCHING --------------- */
extern const short GUILE_PUNCH_X[3];
extern const short GUILE_PUNCH_Y[3];
extern const short GUILE_PUNCH_DRAW_W_ARRAY[3];
extern const short GUILE_PUNCH_DRAW_H_ARRAY[3];

#define GUILE_PUNCH_DRAW_W 57
#define GUILE_PUNCH_DRAW_H 81

#define GUILE_PUNCH_HURT_W 37
#define GUILE_PUNCH_HURT_H 79

/* -------------- KICKING --------------- */
extern const short GUILE_KICK_X[3];
extern const short GUILE_KICK_Y[3];
extern const short GUILE_KICK_DRAW_W_ARRAY[3];
extern const short GUILE_KICK_DRAW_H_ARRAY[3];

#define GUILE_KICK_DRAW_W 49
#define GUILE_KICK_DRAW_H 85

#define GUILE_KICK_HURT_W 39
#define GUILE_KICK_HURT_H 80

/*
  Initialize GUILE
*/
FIGHTER_SPRITES* initGuile();

#endif
