#ifndef __PLAYER__
#define __PLAYER__
#include <stdbool.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/color.h>
#include <allegro5/events.h>
#include <allegro5/keycodes.h>
#include <stdlib.h>
#include <time.h>

#include "attacks_SpecialMoves.h"
#include "character.h"
#include "display.h"
#include "environment.h"
#include "misc.h"

#define PLAYER_VEL 5
#define PLAYER_LIFE 145


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
void resetPlayer(PLAYER *player, int xPosit, int yPosit, bool facingRight);

/*
  This function updates the state of an attack animation going to the next
  frame,and if the frames return to 0 the animation is turned off
*/
void updateAnimation(PLAYER *player, long timerCount);

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
void drawPlayer(PLAYER *player);

/*
  Free up the space that were being utilized by a Player instance
*/
void playerDestroyer(PLAYER *player);
#endif // !__PLAYER__
