#ifndef __RYU__
#define __RYU__


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

/* ---------------- DEFENDING -------------- */
extern const short RYU_DEFENDING_X[1];
extern const short RYU_DEFENDING_Y[1];
extern const short RYU_DEFENDING_DRAW_W_ARRAY[1];
extern const short RYU_DEFENDING_DRAW_H_ARRAY[1];


#define RYU_DEFENDING_DRAW_W 43
#define RYU_DEFENDING_DRAW_H 83

#define RYU_DEFENDING_HURT_W 37
#define RYU_DEFENDING_HURT_H 81

/* -------------- PUNCHING --------------- */
extern const short RYU_PUNCH_X[3];
extern const short RYU_PUNCH_Y[3];
extern const short RYU_PUNCH_DRAW_W_ARRAY[3];
extern const short RYU_PUNCH_DRAW_H_ARRAY[3];

#define RYU_PUNCH_DRAW_W 57
#define RYU_PUNCH_DRAW_H 81

#define RYU_PUNCH_HURT_W 37
#define RYU_PUNCH_HURT_H 79

/* -------------- KICKING --------------- */
extern const short RYU_KICK_X[3];
extern const short RYU_KICK_Y[3];
extern const short RYU_KICK_DRAW_W_ARRAY[3];
extern const short RYU_KICK_DRAW_H_ARRAY[3];

#define RYU_KICK_DRAW_W 49
#define RYU_KICK_DRAW_H 85

#define RYU_KICK_HURT_W 39
#define RYU_KICK_HURT_H 80

#endif
