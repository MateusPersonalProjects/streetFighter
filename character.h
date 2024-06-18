#ifndef __CHARACTER__
#define __CHARACTER__
#include "misc.h"

typedef enum{
  STEADY = 0,
  WALKING,
  JUMPING,
  CROUCHING,
  PUNCHING
} SPRITE_LIST;

typedef struct{
  int width;
  int height;
  int crouchHeight;
  SPRITE_LIST currentSprite;
  // MOVE LIST (array de ponteiro para funções)
  // SPRITES :)
} CHARACTER;

/*
  Initialize a new character
*/
CHARACTER* characterInit(int width, int height, int crouchHeight);

/*
  Free the memory that a character was being utilized by a character
*/
void characterDestroyer(CHARACTER* character);

#endif // !__CHARACTER__

