#include <allegro5/allegro5.h>
#include <allegro5/bitmap.h>
#include <allegro5/color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
 
#include "display.h"
#include "player.h"

#ifndef __MATCH_INTERFACE__
#define __MATCH_INTERFACE__

// ROUND DEFINES
#define ROUND_S_W 61
#define FROUND_S_W 77
#define ROUND_S_H 21
#define ROUND_S_X 272
#define FROUND_S_X 256
#define ROUND_S_Y 168

// NUMBER DEFINES
#define NUMBER_S_H 21
#define NUMBER_S_Y 168

#define N_ONE_S_X 106
#define N_TWO_S_X 120
#define N_ONE_S_W 9
#define N_TWO_S_W 19

// FIGHT DEFINES
#define FIGHT_S_W 63
#define FIGHT_S_H 18

#define FIGHT_S_X 16
#define FIGHT_S_Y 168

// ROUND COUNT DEFINES
#define RC_S_W 18
#define RC_S_H 18

#define RC_S_X 343
#define RC_S_Y 15

typedef struct{

  // Lifebar things
  int lifebarY;
  int lifebarP1X;
  int lifebarP2X;
  int lifebarP1Width;
  int lifebarP2Width;
  int lifebarHeight;
  ALLEGRO_COLOR lifebarColor;

  // Sprites
  ALLEGRO_BITMAP* sheet;
  ALLEGRO_BITMAP* roundSprite;
  ALLEGRO_BITMAP* fRoundSprite;
  ALLEGRO_BITMAP* numOneSprite;
  ALLEGRO_BITMAP* numTwoSprite;
  ALLEGRO_BITMAP* fightSprite;
  ALLEGRO_BITMAP* countWonSprite;

  bool matchUP;
  bool roundUP;
  unsigned short rounds;
  

} MATCH_INTERFACE;

/*
  Initialize a new match interface
*/
MATCH_INTERFACE* initMatchInterface(PLAYER* player1, PLAYER* player2);

/*
  Updates the match interface
*/
void matchInterfaceUpdate(MATCH_INTERFACE* matchInterface, PLAYER* player1,
                          PLAYER* player2);

/*
  Update all the matchs flag that control our rounds
  It is going to return false when someone dies, to turn off the control of the
  players
*/
bool matchUpdate(MATCH_INTERFACE* matchInterface, PLAYER* player1,
                 PLAYER* player2);

/*
  Draw the match interface
*/
void drawMatchInterface(MATCH_INTERFACE* matchInterface, PLAYER *player1, PLAYER *player2);

/*
  Draw the initial text of the fight
  It deactivate the players controls for a 3 seconds then turn it on back again
  so the fight can start

  return the flag that control the controls
*/
bool roundStartWriter(MATCH_INTERFACE* matchInterface, unsigned short* frames,
                        ALLEGRO_FONT* font);
/*
  Ends a round writting K.O, return true when the writting ends so the code can
  reset the players or end the match
*/
bool roundEndWriter(MATCH_INTERFACE* matchInterface, unsigned short* frames,
                    ALLEGRO_FONT* font);

/*
  Show the winner on the screen for 3 seconds, then close the game
*/
bool drawWinnerGreater(MATCH_INTERFACE* matchInterface, unsigned short* frames,
                       ALLEGRO_FONT* font, bool playerOneWon);


/*
  Destroy a match interface
*/
void matchInterfaceDestroyer(MATCH_INTERFACE* matchInterface);

#endif // !__MATCH_INTERFACE__
