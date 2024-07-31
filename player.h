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
  bool animationDone;
} PLAYER;

typedef enum{
  JUMP = 0,
  CROUCH,
  MOVE_LEFT,
  MOVE_RIGHT,
  PUNCH,
  KICK
} BASIC_MOVE;

/*
  Initialize a new player
*/
PLAYER *initPlayer(CHARACTER *character, int xPosit, int yPosit,
                   bool facingRight);

/*
 Reset the player
*/
void resetPlayer(PLAYER *player, int xPosit, int yPosit, bool facingRight, bool matchEnd);

/*
  This function updates the state of an attack animation going to the next
  frame,and if the frames return to 0 the animation is turned off
*/
void updateAnimation(PLAYER *player, long timerCount);

/*
  Update things for player
*/
void playerUpdateMovements(PLAYER *player, PLAYER *anotherPlayer, unsigned char *keyboardKeys, unsigned char *whichKey, long timerCount);


/*
 * Update things for the player attacks
 */
void playerUpdateAttacks(PLAYER *player, PLAYER *anotherPlayer,
                         unsigned char *keyboardKeys, unsigned char *whichKey);

/*
  Draw the player on the screen
*/
void drawPlayer(PLAYER *player, ALLEGRO_COLOR playerColor, long timerIdle);

/*
  Free up the space that were being utilized by a Player instance
*/
void playerDestroyer(PLAYER *player);
#endif // !__PLAYER__
