#include "character.h"
#include <allegro5/color.h>
#include <stdbool.h>
#ifndef __PLAYER__
#define __PLAYER__

typedef struct {
  CHARACTER *character;
  int xPosition;
  int yPosition;
  bool facingRight;
  short int life;
  short int roundsWon;
} PLAYER;

typedef enum{
  JUMP = 0,
  CROUCH,
  MOVE_LEFT,
  MOVE_RIGHT,
} BASIC_MOVE;

/*
  Initialize a new player
*/
PLAYER *initPlayer(CHARACTER *character, int xPosit, int yPosit,
                   bool facingRight);

/*
  Update things for player
*/
void playerUpdate(PLAYER *player, PLAYER *anotherPlayer, unsigned char *keyboardKeys, unsigned char *whichKey);

/*
  Draw the player on the screen
*/
void drawPlayer(PLAYER *player, ALLEGRO_COLOR playerColor);

/*
  Free up the space that were being utilized by a Player instance
*/
void playerDestroyer(PLAYER *player);

#endif // !__PLAYER__
