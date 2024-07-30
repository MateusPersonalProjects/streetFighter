#ifndef __CHUNLI__
#define __CHUNLI__
#include "../character.h"

/* -------------- IDLE ----------------- */
extern const short CHUNLI_IDLE_X[4];
extern const short CHUNLI_IDLE_Y[4];
extern const short CHUNLI_IDLE_DRAW_W[4];
extern const short CHUNLI_IDLE_DRAW_H[4];

#define CHUNLI_IDLE_HURT_W 34
#define CHUNLI_IDLE_HURT_H 76

/* ---------------- WALKING ---------------- */
extern const short CHUNLI_WALK_X[8];
extern const short CHUNLI_WALK_Y[8];
extern const short CHUNLI_WALK_DRAW_W[8];
extern const short CHUNLI_WALK_DRAW_H[8];

#define CHUNLI_WALK_HURT_W 33 
#define CHUNLI_WALK_HURT_H 78

/* --------------- CROUCHING --------------- */
extern const short CHUNLI_CROUCH_X[1];
extern const short CHUNLI_CROUCH_Y[1];
//extern const short CHUNLI_CROUCH_DRAW_W[1];
//extern const short CHUNLI_CROUCH_DRAW_H[1];
#define CHUNLI_CROUCH_DRAW_W 46
#define CHUNLI_CROUCH_DRAW_H 60
//extern const short CHUNLI_CROUCH_HURT_W[1];
//extern const short CHUNLI_CROUCH_HURT_H[1];
#define CHUNLI_CROUCH_HURT_W 42
#define CHUNLI_CROUCH_HURT_H 48


/* --------------- JUMPING ---------------- */
extern const short CHUNLI_JUMP_X[7];
extern const short CHUNLI_JUMP_Y[7];
extern const short CHUNLI_JUMP_DRAW_W_ARRAY[7];
extern const short CHUNLI_JUMP_DRAW_H_ARRAY[7];

#define CHUNLI_JUMP_DRAW_W 64
#define CHUNLI_JUMP_DRAW_H 77

#define CHUNLI_JUMP_HURT_W 64
#define CHUNLI_JUMP_HURT_H 77

/* --------------- GOT HIT ---------------- */
extern const short CHUNLI_HIT_X[2];
extern const short CHUNLI_HIT_Y[2];
extern const short CHUNLI_HIT_DRAW_W_ARRAY[2];
extern const short CHUNLI_HIT_DRAW_H_ARRAY[2];

#define CHUNLI_HIT_DRAW_W 65
#define CHUNLI_HIT_DRAW_H 64

#define CHUNLI_HIT_HURT_W 37
#define CHUNLI_HIT_HURT_H 66


/* --------------- GOT FACE HIT ---------------- */
extern const short CHUNLI_FACE_HIT_X[2];
extern const short CHUNLI_FACE_HIT_Y[2];
extern const short CHUNLI_FACE_HIT_DRAW_W_ARRAY[2];
extern const short CHUNLI_FACE_HIT_DRAW_H_ARRAY[2];

#define CHUNLI_FACE_HIT_DRAW_W 48
#define CHUNLI_FACE_HIT_DRAW_H 79

#define CHUNLI_FACE_HIT_HURT_W 37
#define CHUNLI_FACE_HIT_HURT_H 79

/* ---------------- DEFENDING -------------- */
extern const short CHUNLI_DEFENDING_X[1];
extern const short CHUNLI_DEFENDING_Y[1];
extern const short CHUNLI_DEFENDING_DRAW_W_ARRAY[1];
extern const short CHUNLI_DEFENDING_DRAW_H_ARRAY[1];


#define CHUNLI_DEFENDING_DRAW_W 49
#define CHUNLI_DEFENDING_DRAW_H 76

#define CHUNLI_DEFENDING_HURT_W 29
#define CHUNLI_DEFENDING_HURT_H 74

/* -------------- PUNCHING --------------- */
extern const short CHUNLI_PUNCH_X[3];
extern const short CHUNLI_PUNCH_Y[3];
extern const short CHUNLI_PUNCH_DRAW_W_ARRAY[3];
extern const short CHUNLI_PUNCH_DRAW_H_ARRAY[3];

#define CHUNLI_PUNCH_DRAW_W 61
#define CHUNLI_PUNCH_DRAW_H 80

#define CHUNLI_PUNCH_HURT_W 25
#define CHUNLI_PUNCH_HURT_H 78

/* -------------- KICKING --------------- */
extern const short CHUNLI_KICK_X[5];
extern const short CHUNLI_KICK_Y[5];
extern const short CHUNLI_KICK_DRAW_W_ARRAY[5];
extern const short CHUNLI_KICK_DRAW_H_ARRAY[5];

#define CHUNLI_KICK_DRAW_W 69
#define CHUNLI_KICK_DRAW_H 85

#define CHUNLI_KICK_HURT_W 25
#define CHUNLI_KICK_HURT_H 83

/*
  Initialize CHUNLI
*/
FIGHTER_SPRITES* initChunli();

#endif
