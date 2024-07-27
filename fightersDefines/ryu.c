#include "ryu.h"
const short RYU_IDLE_X[4] = {6, 55, 105, 154};
const short RYU_IDLE_Y[4] = {18, 19, 18, 17};
// const short RYU_IDLE_DRAW_W[4] = {43, 43, 43, 43};
// const short RYU_IDLE_DRAW_H[4] = {81, 80, 82, 82};
//  const short RYU_IDLE_HURT_W[4] = {31, 36, 35, 35};
//  const short RYU_IDLE_HURT_H[4] = {80, 80, 79, 80};

/* ---------------- WALKING ---------------- */
const short RYU_WALK_X[5] = {205, 252, 301, 351, 401};
const short RYU_WALK_Y[5] = {24, 19, 18, 19, 19};
// const short RYU_WALK_DRAW_W[5] = {43, 43, 43, 43, 43};
// const short RYU_WALK_DRAW_H[5] = {75, 80, 81, 80, 80};
//  const short RYU_WALK_HURT_W[5] = {30, 37, 37, 32, 31};
//  const short RYU_WALK_HURT_H[5] = {73, 78, 79, 78, 79};

/* --------------- CROUCHING --------------- */
const short RYU_CROUCH_X[1] = {1160};
const short RYU_CROUCH_Y[1] = {44};
// const short RYU_CROUCH_DRAW_W[1] = {43};
// const short RYU_CROUCH_DRAW_H[1] = {55};
//  const short RYU_CROUCH_HURT_W[1] = {35};
//  const short RYU_CROUCH_HURT_H[1] = {53};

/* --------------- GOT HIT ---------------- */
const short RYU_HIT_X[4] = {5, 53, 106, 163};
const short RYU_HIT_Y[4] = {760, 761, 771, 754};
const short RYU_HIT_DRAW_W_ARRAY[4] = {43, 47, 49, 43};
const short RYU_HIT_DRAW_H_ARRAY[4] = {76, 75, 65, 82};

/* ---------------- GOT FACE HIT -------------- */
const short RYU_FACE_HIT_X[4] = {217, 271, 328, 391};
const short RYU_FACE_HIT_Y[4] = {757, 757, 753, 754};
const short RYU_FACE_HIT_DRAW_W_ARRAY[4] = {48, 52, 58, 43};
const short RYU_FACE_HIT_DRAW_H_ARRAY[4] = {79, 79, 83, 82};

/* ---------------- DEFENDING -------------- */
const short RYU_DEFENDING_X[1] = {1211};
const short RYU_DEFENDING_Y[1] = {16};
const short RYU_DEFENDING_DRAW_W_ARRAY[1] = {43};
const short RYU_DEFENDING_DRAW_H_ARRAY[1] = {83};

/* --------------- PUNCHING ------------- */
const short RYU_PUNCH_X[3] = {3, 52, 117};
const short RYU_PUNCH_Y[3] = {134, 134, 134};
const short RYU_PUNCH_DRAW_W_ARRAY[3] = {43, 57, 43};
const short RYU_PUNCH_DRAW_H_ARRAY[3] = {81, 81, 81};

/* --------------- KICKING --------------- */
const short RYU_KICK_X[3] = {6, 62, 135};
const short RYU_KICK_Y[3] = {261, 259, 261};
const short RYU_KICK_DRAW_W_ARRAY[3] = {49, 67, 49};
const short RYU_KICK_DRAW_H_ARRAY[3] = {85, 87, 85};
