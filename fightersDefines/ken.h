#ifndef __KEN__
#define __KEN__
#include "../character.h"

/* -------------- IDLE ----------------- */
extern const short KEN_IDLE_X[4];
extern const short KEN_IDLE_Y[4];
//extern const short KEN_IDLE_DRAW_W[4];
//extern const short KEN_IDLE_DRAW_H[4];
#define KEN_IDLE_DRAW_W 43
#define KEN_IDLE_DRAW_H 82
//extern const short KEN_IDLE_HURT_W[4];
//extern const short KEN_IDLE_HURT_H[4];
#define KEN_IDLE_HURT_W 36
#define KEN_IDLE_HURT_H 80

/* ---------------- WALKING ---------------- */
extern const short KEN_WALK_X[5];
extern const short KEN_WALK_Y[5];
//extern const short KEN_WALK_DRAW_W[5];
//extern const short KEN_WALK_DRAW_H[5];
#define KEN_WALK_DRAW_W 43
#define KEN_WALK_DRAW_H 81
//extern const short KEN_WALK_HURT_W[5];
//extern const short KEN_WALK_HURT_H[5];
#define KEN_WALK_HURT_W 37
#define KEN_WALK_HURT_H 79

/* --------------- CROUCHING --------------- */
extern const short KEN_CROUCH_X[1];
extern const short KEN_CROUCH_Y[1];
//extern const short KEN_CROUCH_DRAW_W[1];
//extern const short KEN_CROUCH_DRAW_H[1];
#define KEN_CROUCH_DRAW_W 43
#define KEN_CROUCH_DRAW_H 55
//extern const short KEN_CROUCH_HURT_W[1];
//extern const short KEN_CROUCH_HURT_H[1];
#define KEN_CROUCH_HURT_W 35
#define KEN_CROUCH_HURT_H 53


/* --------------- JUMPING ---------------- */
extern const short KEN_JUMP_X[7];
extern const short KEN_JUMP_Y[7];
extern const short KEN_JUMP_DRAW_W_ARRAY[7];
extern const short KEN_JUMP_DRAW_H_ARRAY[7];

#define KEN_JUMP_DRAW_W 33
#define KEN_JUMP_DRAW_H 90

#define KEN_JUMP_HURT_W 30
#define KEN_JUMP_HURT_H 73

/* --------------- GOT HIT ---------------- */
extern const short KEN_HIT_X[4];
extern const short KEN_HIT_Y[4];
extern const short KEN_HIT_DRAW_W_ARRAY[4];
extern const short KEN_HIT_DRAW_H_ARRAY[4];

#define KEN_HIT_DRAW_W 43
#define KEN_HIT_DRAW_H 76

#define KEN_HIT_HURT_W 34
#define KEN_HIT_HURT_H 72


/* --------------- GOT FACE HIT ---------------- */
extern const short KEN_FACE_HIT_X[4];
extern const short KEN_FACE_HIT_Y[4];
extern const short KEN_FACE_HIT_DRAW_W_ARRAY[4];
extern const short KEN_FACE_HIT_DRAW_H_ARRAY[4];

#define KEN_FACE_HIT_DRAW_W 48
#define KEN_FACE_HIT_DRAW_H 79

#define KEN_FACE_HIT_HURT_W 37
#define KEN_FACE_HIT_HURT_H 79

/* --------------- GOT CROUCH HIT ---------------- */
extern const short KEN_CROUCH_HIT_X[4];
extern const short KEN_CROUCH_HIT_Y[4];
extern const short KEN_CROUCH_HIT_DRAW_W_ARRAY[4];
extern const short KEN_CROUCH_HIT_DRAW_H_ARRAY[4];

#define KEN_CROUCH_HIT_DRAW_W 47
#define KEN_CROUCH_HIT_DRAW_H 62

#define KEN_CROUCH_HIT_HURT_W 39
#define KEN_CROUCH_HIT_HURT_H 62


/* ---------------- DEFENDING -------------- */
extern const short KEN_DEFENDING_X[4];
extern const short KEN_DEFENDING_Y[4];
extern const short KEN_DEFENDING_DRAW_W_ARRAY[4];
extern const short KEN_DEFENDING_DRAW_H_ARRAY[4];


#define KEN_DEFENDING_DRAW_W 43
#define KEN_DEFENDING_DRAW_H 83

#define KEN_DEFENDING_HURT_W 37
#define KEN_DEFENDING_HURT_H 81

/* ---------------- CROUCH BLOCK -------------- */
extern const short KEN_CROUCH_BLOCK_X[4];
extern const short KEN_CROUCH_BLOCK_Y[4];
extern const short KEN_CROUCH_CLOCK_DRAW_W_ARRAY[4];
extern const short KEN_CROUCH_BLOCK_DRAW_H_ARRAY[4];

#define KEN_CROUCH_BLOCK_DRAW_W 43
#define KEN_CROUCH_BLOCK_DRAW_H 61

#define KEN_CROUCH_BLOCK_HURT_W 35
#define KEN_CROUCH_BLOCK_HURT_H 59

/* -------------- PUNCHING --------------- */
extern const short KEN_PUNCH_X[3];
extern const short KEN_PUNCH_Y[3];
extern const short KEN_PUNCH_DRAW_W_ARRAY[3];
extern const short KEN_PUNCH_DRAW_H_ARRAY[3];

#define KEN_PUNCH_DRAW_W 57
#define KEN_PUNCH_DRAW_H 81

#define KEN_PUNCH_HURT_W 37
#define KEN_PUNCH_HURT_H 79

/* -------------- CROUCH PUNCH --------------- */
extern const short KEN_CROUCH_PUNCH_X[3];
extern const short KEN_CROUCH_PUNCH_Y[3];
extern const short KEN_CROUCH_PUNCH_DRAW_W_ARRAY[3];
extern const short KEN_CROUCH_PUNCH_DRAW_H_ARRAY[3];

#define KEN_CROUCH_PUNCH_DRAW_W 62 
#define KEN_CROUCH_PUNCH_DRAW_H 54

#define KEN_CROUCH_PUNCH_HURT_W 32 
#define KEN_CROUCH_PUNCH_HURT_H 54


/* -------------- KICKING --------------- */
extern const short KEN_KICK_X[3];
extern const short KEN_KICK_Y[3];
extern const short KEN_KICK_DRAW_W_ARRAY[3];
extern const short KEN_KICK_DRAW_H_ARRAY[3];

#define KEN_KICK_DRAW_W 49
#define KEN_KICK_DRAW_H 85

#define KEN_KICK_HURT_W 39
#define KEN_KICK_HURT_H 80

/* --------------- JUMP KICK --------------- */
extern const short KEN_JUMP_KICK_X[4];
extern const short KEN_JUMP_KICK_Y[4];
extern const short KEN_JUMP_KICK_DRAW_W_ARRAY[4];
extern const short KEN_JUMP_KICK_DRAW_H_ARRAY[4];

#define KEN_JUMP_KICK_DRAW_W 63   
#define KEN_JUMP_KICK_DRAW_H 51

#define KEN_JUMP_KICK_HURT_W 31
#define KEN_JUMP_KICK_HURT_H 51


/*
  Initialize KEN
*/
FIGHTER_SPRITES* initKen();

#endif
