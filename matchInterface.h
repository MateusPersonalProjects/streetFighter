#include <allegro5/allegro5.h>
#include <allegro5/color.h>

#include "display.h"
#include "player.h"

#ifndef __MATCH_INTERFACE__
#define __MATCH_INTERFACE__

typedef struct{
  int lifebarY;
  int lifebarP1X;
  int lifebarP2X;
  int lifebarP1Width;
  int lifebarP2Width;
  int lifebarHeight;
  ALLEGRO_COLOR lifebarColor;

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
  Draw the match interface
*/
void drawMatchInterface(MATCH_INTERFACE* matchInterface);


/*
  Destroy a match interface
*/
void matchInterfaceDestroyer(MATCH_INTERFACE* matchInterface);

#endif // !__MATCH_INTERFACE__
