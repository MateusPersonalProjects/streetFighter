#include "character.h"
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


/*
  Initialize a new player
*/
PLAYER *initPlayer(CHARACTER *character, int xPosit, int yPosit,
                   bool facingRight);

/*
  Update things for player 1
*/
void player1Update(PLAYER *player, unsigned char *keyboardKeys);

/*
  Draw the player on the screen
*/
void drawPlayer(PLAYER *player);

/*
  Free up the space that were being utilized by a Player instance
*/
void playerDestroyer(PLAYER *player);

#endif // !__PLAYER__
