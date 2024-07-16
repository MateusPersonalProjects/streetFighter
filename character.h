#ifndef __CHARACTER__
#define __CHARACTER__
#include "misc.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/bitmap.h>
#include "fightersDefines/ryu.h"

typedef enum{
  STEADY = 0,
  WALKING,
  JUMPING,
  CROUCHING,
  DEFENDING,
  GOT_HIT,
  PUNCHING
} SPRITE_LIST;

typedef struct{
  short numFrames;
  short currentFrame;
  short height;
  short width;
  ALLEGRO_BITMAP** Sprites;
} MOVE_SPRITES;

typedef struct{
  ALLEGRO_BITMAP* sheet;

  MOVE_SPRITES movesSprites[7];
} FIGHTER_SPRITES;

typedef struct{
  int width;
  int height;
  int crouchHeight;
  SPRITE_LIST currentSprite;
  FIGHTER_SPRITES* Sprites;
  // MOVE LIST (array de ponteiro para funções)
  // SPRITES :)
} CHARACTER;

/*
  Initialize a new character
*/
CHARACTER* characterInit(FIGHTER_SPRITES* fighterSprite);

/*
  Initialize RYU
*/
FIGHTER_SPRITES* initRyu();

/*
  Free the memory that a character was being utilized by a character
*/
void characterDestroyer(CHARACTER* character);

#endif // !__CHARACTER__

