#ifndef __RYU__
#define __RYU__
#include "../character.h"

/* -------------- IDLE ----------------- */
extern const short RYU_IDLE_X[4];
extern const short RYU_IDLE_Y[4];
//extern const short RYU_IDLE_DRAW_W[4];
//extern const short RYU_IDLE_DRAW_H[4];
#define RYU_IDLE_DRAW_W 43
#define RYU_IDLE_DRAW_H 82
//extern const short RYU_IDLE_HURT_W[4];
//extern const short RYU_IDLE_HURT_H[4];
#define RYU_IDLE_HURT_W 36
#define RYU_IDLE_HURT_H 80

/* ---------------- WALKING ---------------- */
extern const short RYU_WALK_X[5];
extern const short RYU_WALK_Y[5];
//extern const short RYU_WALK_DRAW_W[5];
//extern const short RYU_WALK_DRAW_H[5];
#define RYU_WALK_DRAW_W 43
#define RYU_WALK_DRAW_H 81
//extern const short RYU_WALK_HURT_W[5];
//extern const short RYU_WALK_HURT_H[5];
#define RYU_WALK_HURT_W 37
#define RYU_WALK_HURT_H 79

/* --------------- CROUCHING --------------- */
extern const short RYU_CROUCH_X[1];
extern const short RYU_CROUCH_Y[1];
//extern const short RYU_CROUCH_DRAW_W[1];
//extern const short RYU_CROUCH_DRAW_H[1];
#define RYU_CROUCH_DRAW_W 43
#define RYU_CROUCH_DRAW_H 55
//extern const short RYU_CROUCH_HURT_W[1];
//extern const short RYU_CROUCH_HURT_H[1];
#define RYU_CROUCH_HURT_W 35
#define RYU_CROUCH_HURT_H 53


/* --------------- JUMPING ---------------- */
extern const short RYU_JUMP_X[7];
extern const short RYU_JUMP_Y[7];
extern const short RYU_JUMP_DRAW_W_ARRAY[7];
extern const short RYU_JUMP_DRAW_H_ARRAY[7];

#define RYU_JUMP_DRAW_W 33
#define RYU_JUMP_DRAW_H 90

#define RYU_JUMP_HURT_W 30
#define RYU_JUMP_HURT_H 73

/* --------------- GOT HIT ---------------- */
extern const short RYU_HIT_X[4];
extern const short RYU_HIT_Y[4];
extern const short RYU_HIT_DRAW_W_ARRAY[4];
extern const short RYU_HIT_DRAW_H_ARRAY[4];

#define RYU_HIT_DRAW_W 43
#define RYU_HIT_DRAW_H 76

#define RYU_HIT_HURT_W 34
#define RYU_HIT_HURT_H 72


/* --------------- GOT FACE HIT ---------------- */
extern const short RYU_FACE_HIT_X[4];
extern const short RYU_FACE_HIT_Y[4];
extern const short RYU_FACE_HIT_DRAW_W_ARRAY[4];
extern const short RYU_FACE_HIT_DRAW_H_ARRAY[4];

#define RYU_FACE_HIT_DRAW_W 48
#define RYU_FACE_HIT_DRAW_H 79

#define RYU_FACE_HIT_HURT_W 37
#define RYU_FACE_HIT_HURT_H 79

/* --------------- GOT CROUCH HIT ---------------- */
extern const short RYU_CROUCH_HIT_X[4];
extern const short RYU_CROUCH_HIT_Y[4];
extern const short RYU_CROUCH_HIT_DRAW_W_ARRAY[4];
extern const short RYU_CROUCH_HIT_DRAW_H_ARRAY[4];

#define RYU_CROUCH_HIT_DRAW_W 45
#define RYU_CROUCH_HIT_DRAW_H 62

#define RYU_CROUCH_HIT_HURT_W 39
#define RYU_CROUCH_HIT_HURT_H 61


/* ---------------- DEFENDING -------------- */
extern const short RYU_DEFENDING_X[4];
extern const short RYU_DEFENDING_Y[4];
extern const short RYU_DEFENDING_DRAW_W_ARRAY[4];
extern const short RYU_DEFENDING_DRAW_H_ARRAY[4];


#define RYU_DEFENDING_DRAW_W 43
#define RYU_DEFENDING_DRAW_H 83

#define RYU_DEFENDING_HURT_W 37
#define RYU_DEFENDING_HURT_H 81

/* ---------------- CROUCH BLOCK -------------- */
extern const short RYU_CROUCH_BLOCK_X[4];
extern const short RYU_CROUCH_BLOCK_Y[4];
extern const short RYU_CROUCH_CLOCK_DRAW_W_ARRAY[4];
extern const short RYU_CROUCH_BLOCK_DRAW_H_ARRAY[4];

#define RYU_CROUCH_BLOCK_DRAW_W 43
#define RYU_CROUCH_BLOCK_DRAW_H 61

#define RYU_CROUCH_BLOCK_HURT_W 35
#define RYU_CROUCH_BLOCK_HURT_H 59

/* -------------- PUNCHING --------------- */
extern const short RYU_PUNCH_X[3];
extern const short RYU_PUNCH_Y[3];
extern const short RYU_PUNCH_DRAW_W_ARRAY[3];
extern const short RYU_PUNCH_DRAW_H_ARRAY[3];

#define RYU_PUNCH_DRAW_W 57
#define RYU_PUNCH_DRAW_H 81

#define RYU_PUNCH_HURT_W 37
#define RYU_PUNCH_HURT_H 79

/* -------------- CROUCH PUNCH --------------- */
extern const short RYU_CROUCH_PUNCH_X[3];
extern const short RYU_CROUCH_PUNCH_Y[3];
extern const short RYU_CROUCH_PUNCH_DRAW_W_ARRAY[3];
extern const short RYU_CROUCH_PUNCH_DRAW_H_ARRAY[3];

#define RYU_CROUCH_PUNCH_DRAW_W 62
#define RYU_CROUCH_PUNCH_DRAW_H 55

#define RYU_CROUCH_PUNCH_HURT_W 36
#define RYU_CROUCH_PUNCH_HURT_H 53

/* -------------- KICKING --------------- */
extern const short RYU_KICK_X[3];
extern const short RYU_KICK_Y[3];
extern const short RYU_KICK_DRAW_W_ARRAY[3];
extern const short RYU_KICK_DRAW_H_ARRAY[3];

#define RYU_KICK_DRAW_W 49
#define RYU_KICK_DRAW_H 85

#define RYU_KICK_HURT_W 39
#define RYU_KICK_HURT_H 80

/* --------------- JUMP KICK --------------- */
extern const short RYU_JUMP_KICK_X[4];
extern const short RYU_JUMP_KICK_Y[4];
extern const short RYU_JUMP_KICK_DRAW_W_ARRAY[4];
extern const short RYU_JUMP_KICK_DRAW_H_ARRAY[4];

#define RYU_JUMP_KICK_DRAW_W 63 
#define RYU_JUMP_KICK_DRAW_H 54

#define RYU_JUMP_KICK_HURT_W 35 
#define RYU_JUMP_KICK_HURT_H 54

/* -------------- DEAD ---------------- */
extern const short RYU_DEAD_X[5];
extern const short RYU_DEAD_Y[5];
extern const short RYU_DEAD_DRAW_W_ARRAY[5];
extern const short RYU_DEAD_DRAW_H_ARRAY[5];

#define RYU_DEAD_DRAW_W 74
#define RYU_DEAD_DRAW_H 30

#define RYU_DEAD_HURT_W 74
#define RYU_DEAD_HURT_H 30

/* -------------- VICTORY ---------------- */
extern const short RYU_VICTORY_X[3];
extern const short RYU_VICTORY_Y[3];
extern const short RYU_VICTORY_DRAW_W_ARRAY[3];
extern const short RYU_VICTORY_DRAW_H_ARRAY[3];

#define RYU_VICTORY_DRAW_W 43
#define RYU_VICTORY_DRAW_H 87

#define RYU_VICTORY_HURT_W 43
#define RYU_VICTORY_HURT_H 87


/*
  Initialize RYU
*/
FIGHTER_SPRITES* initRyu();

#endif
