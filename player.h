#include <allegro5/color.h>
#include <stdbool.h>
#ifndef __PLAYER__
#define __PLAYER__

#include "attacks_SpecialMoves.h"
#include "character.h"
typedef struct {
  CHARACTER *character;
  int xPosition;
  int yPosition;
  int yAcel;
  bool facingRight;
  bool crouching;
  bool blocking;
  short int life;
  short int roundsWon;
} PLAYER;

typedef enum{
  JUMP = 0,
  CROUCH,
  MOVE_LEFT,
  MOVE_RIGHT,
  PUNCH,
} BASIC_MOVE;

/*
  Initialize a new player
*/
PLAYER *initPlayer(CHARACTER *character, int xPosit, int yPosit,
                   bool facingRight);

/*
  Update things for player
*/
void playerUpdateMovements(PLAYER *player, PLAYER *anotherPlayer, unsigned char *keyboardKeys, unsigned char *whichKey);


/*
 * Update things for the player attacks
 */
void playerUpdateAttacks(PLAYER *player, PLAYER *anotherPlayer,
                         unsigned char *keyboardKeys, unsigned char *whichKey);

/*
  Draw the player on the screen
*/
void drawPlayer(PLAYER *player, ALLEGRO_COLOR playerColor);

/*
  Free up the space that were being utilized by a Player instance
*/
void playerDestroyer(PLAYER *player);

#endif // !__PLAYER__
