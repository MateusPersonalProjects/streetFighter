#include "matchInterface.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <time.h>

/*
  Initialize a new match interface
*/
MATCH_INTERFACE* initMatchInterface(PLAYER* player1, PLAYER* player2) {
  MATCH_INTERFACE* newMatchInterface =
      (MATCH_INTERFACE*)malloc(sizeof(MATCH_INTERFACE));
  if (newMatchInterface == NULL) exit(1);

  newMatchInterface->lifebarP1X = 10;
  newMatchInterface->lifebarP2Width = BUFFER_W - 10;
  newMatchInterface->lifebarY = 5;
  newMatchInterface->lifebarHeight = 15;

  newMatchInterface->lifebarColor = al_map_rgb(255, 255, 255);

  return newMatchInterface;
}

/*
  Updates the match interface
*/
void matchInterfaceUpdate(MATCH_INTERFACE* matchInterface, PLAYER* player1,
                          PLAYER* player2) {
  matchInterface->lifebarP1Width = player1->life;
  matchInterface->lifebarP2X = BUFFER_W - player2->life - 10;
}

/*
  Draw the match interface
*/
void drawMatchInterface(MATCH_INTERFACE* matchInterface) {
  al_draw_filled_rectangle(
      matchInterface->lifebarP1X, matchInterface->lifebarY,
      (matchInterface->lifebarP1X + matchInterface->lifebarP1Width),
      (matchInterface->lifebarY + matchInterface->lifebarHeight),
      matchInterface->lifebarColor);
  al_draw_filled_rectangle(
      matchInterface->lifebarP2X, matchInterface->lifebarY, BUFFER_W - 10,
      (matchInterface->lifebarY + matchInterface->lifebarHeight),
      matchInterface->lifebarColor);
}

/*
  Destroy a match interface
*/
void matchInterfaceDestroyer(MATCH_INTERFACE* matchInterface) {
  free(matchInterface);
}
