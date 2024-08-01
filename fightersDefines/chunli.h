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

/* --------------- GOT CROUCH HIT ---------------- */
extern const short CHUNLI_CROUCH_HIT_X[4];
extern const short CHUNLI_CROUCH_HIT_Y[4];
extern const short CHUNLI_CROUCH_HIT_DRAW_W_ARRAY[4];
extern const short CHUNLI_CROUCH_HIT_DRAW_H_ARRAY[4];

#define CHUNLI_CROUCH_HIT_DRAW_W 53
#define CHUNLI_CROUCH_HIT_DRAW_H 55

#define CHUNLI_CROUCH_HIT_HURT_W 47
#define CHUNLI_CROUCH_HIT_HURT_H 53


/* ---------------- DEFENDING -------------- */
extern const short CHUNLI_DEFENDING_X[4];
extern const short CHUNLI_DEFENDING_Y[4];
extern const short CHUNLI_DEFENDING_DRAW_W_ARRAY[4];
extern const short CHUNLI_DEFENDING_DRAW_H_ARRAY[4];


#define CHUNLI_DEFENDING_DRAW_W 49
#define CHUNLI_DEFENDING_DRAW_H 76

#define CHUNLI_DEFENDING_HURT_W 29
#define CHUNLI_DEFENDING_HURT_H 74

/* ---------------- CROUCH BLOCK -------------- */
extern const short CHUNLI_CROUCH_BLOCK_X[4];
extern const short CHUNLI_CROUCH_BLOCK_Y[4];
extern const short CHUNLI_CROUCH_CLOCK_DRAW_W_ARRAY[4];
extern const short CHUNLI_CROUCH_BLOCK_DRAW_H_ARRAY[4];

#define CHUNLI_CROUCH_BLOCK_DRAW_W 45
#define CHUNLI_CROUCH_BLOCK_DRAW_H 61

#define CHUNLI_CROUCH_BLOCK_HURT_W 40
#define CHUNLI_CROUCH_BLOCK_HURT_H 59


/* -------------- PUNCHING --------------- */
extern const short CHUNLI_PUNCH_X[3];
extern const short CHUNLI_PUNCH_Y[3];
extern const short CHUNLI_PUNCH_DRAW_W_ARRAY[3];
extern const short CHUNLI_PUNCH_DRAW_H_ARRAY[3];

#define CHUNLI_PUNCH_DRAW_W 61
#define CHUNLI_PUNCH_DRAW_H 80

#define CHUNLI_PUNCH_HURT_W 25
#define CHUNLI_PUNCH_HURT_H 78

/* -------------- CROUCH PUNCH --------------- */
extern const short CHUNLI_CROUCH_PUNCH_X[3];
extern const short CHUNLI_CROUCH_PUNCH_Y[3];
extern const short CHUNLI_CROUCH_PUNCH_DRAW_W_ARRAY[3];
extern const short CHUNLI_CROUCH_PUNCH_DRAW_H_ARRAY[3];

#define CHUNLI_CROUCH_PUNCH_DRAW_W 83 
#define CHUNLI_CROUCH_PUNCH_DRAW_H 60

#define CHUNLI_CROUCH_PUNCH_HURT_W 47
#define CHUNLI_CROUCH_PUNCH_HURT_H 59


/* -------------- KICKING --------------- */
extern const short CHUNLI_KICK_X[5];
extern const short CHUNLI_KICK_Y[5];
extern const short CHUNLI_KICK_DRAW_W_ARRAY[5];
extern const short CHUNLI_KICK_DRAW_H_ARRAY[5];

#define CHUNLI_KICK_DRAW_W 69
#define CHUNLI_KICK_DRAW_H 85

#define CHUNLI_KICK_HURT_W 25
#define CHUNLI_KICK_HURT_H 83

/* --------------- JUMP KICK --------------- */
extern const short CHUNLI_JUMP_KICK_X[4];
extern const short CHUNLI_JUMP_KICK_Y[4];
extern const short CHUNLI_JUMP_KICK_DRAW_W_ARRAY[4];
extern const short CHUNLI_JUMP_KICK_DRAW_H_ARRAY[4];

#define CHUNLI_JUMP_KICK_DRAW_W 65  
#define CHUNLI_JUMP_KICK_DRAW_H 49

#define CHUNLI_JUMP_KICK_HURT_W 44
#define CHUNLI_JUMP_KICK_HURT_H 49


/*
  Initialize CHUNLI
*/
FIGHTER_SPRITES* initChunli();

#endif
