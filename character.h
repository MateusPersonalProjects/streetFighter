#ifndef __CHARACTER__
#define __CHARACTER__
#include "misc.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/bitmap.h>

typedef enum{
  STEADY = 0,
  WALKING,
  JUMPING,
  CROUCHING,
  DEFENDING,
  CROUCH_BLOCK,
  GOT_HIT,
  GOT_FACE_HIT,
  GOT_CROUCH_HIT,
  PUNCHING,
  CROUCH_PUNCH,
  KICKING,
  JUMP_KICK,
  DEAD,
  VICTORY,
  SPRITE_LIST_NUM
} SPRITE_LIST;

typedef struct{
  short numFrames;
  short currentFrame;
  short modAnimation;
  short drawBoxHeight;
  short drawBoxWidth;
  short hurtBoxHeight;
  short hurtBoxWidth;
  short hitBox_X;
  short hitBox_Y;
  short hitBoxWidth;
  short hitBoxHeight;
  ALLEGRO_BITMAP** sprites;
} MOVE_SPRITES;

// IDEIA DO ATTACK_SPRITES VOU TER UM STRUCT CHAMA HITBOX ALI DENTRO QUE ARMAZENA AS COORDENADAS BONITAMENTE PRA PASSAR PRAS FUNÇÕES DE ATAQUE
typedef struct{
  ALLEGRO_BITMAP* sheet;

  MOVE_SPRITES movesSprites[SPRITE_LIST_NUM];
} FIGHTER_SPRITES;

typedef struct{
  int width;
  int height;
  int hurtWidth;
  int hurtHeight;
  SPRITE_LIST currentSprite;
  FIGHTER_SPRITES* fighterGraphics;
} CHARACTER;

/*
  Initialize a new character
*/
CHARACTER* characterInit(FIGHTER_SPRITES* fighterSprite);

/*
  Load moviment sprites
*/
void movimentSpritesInit(FIGHTER_SPRITES* fighter, SPRITE_LIST sprite,
                         short numFrames, short currentFrame, short draw_h,
                         short draw_w, short hurt_h, short hurt_w,
                         const short* idle_x, const short* idle_y);

/*
  Load sprites with arrays for draw w and draw h
*/
void attackSpritesInit(FIGHTER_SPRITES* fighter, SPRITE_LIST sprite,
                       short numFrames, short currentFrame, short draw_h,
                       short draw_w, short hurt_h, short hurt_w,
                       const short* idle_x, const short* idle_y, short hit_w,
                       short hit_h, short hit_y, const short* draw_w_array,
                       const short* draw_h_array);

/*
  Free the memory that a character was being utilized by a character
*/
void characterDestroyer(CHARACTER* character);

#endif // !__CHARACTER__

