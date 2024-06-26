#include "matchInterface.h"

#include <allegro5/allegro_font.h>
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
  Update all the matchs flag that control our rounds
  It is going to return false when someone dies, to turn off the control of the
  players
*/
bool matchUpdate(MATCH_INTERFACE* matchInterface, PLAYER* player1,
                 PLAYER* player2) {
  bool control = true;
  if ((player1->life <= 0 || player2->life <= 0)) {
    matchInterface->rounds++;
    matchInterface->roundUP = false;
    if (player1->life <= 0) player2->roundsWon += 1;
    if (player2->life <= 0) player1->roundsWon += 1;
    if ((player1->roundsWon == 2) || (player2->roundsWon == 2))
      matchInterface->matchUP = false;
    control = false;
  }
  return control;
}

/*
  Draw the match interface
*/
void drawMatchInterface(MATCH_INTERFACE* matchInterface, PLAYER* player1,
                        PLAYER* player2) {
  // Draw the lifebars
  al_draw_filled_rectangle(
      matchInterface->lifebarP1X, matchInterface->lifebarY,
      (matchInterface->lifebarP1X + matchInterface->lifebarP1Width),
      (matchInterface->lifebarY + matchInterface->lifebarHeight),
      matchInterface->lifebarColor);
  al_draw_filled_rectangle(
      matchInterface->lifebarP2X, matchInterface->lifebarY, BUFFER_W - 10,
      (matchInterface->lifebarY + matchInterface->lifebarHeight),
      matchInterface->lifebarColor);

  // Draw the rounds won for p1
  if (player1->roundsWon >= 1) {
    al_draw_filled_circle(140, (matchInterface->lifebarY + 22), 2,
                          al_map_rgb(200, 0, 20));
    if (player1->roundsWon == 2)
      al_draw_filled_circle(155, (matchInterface->lifebarY + 22), 2,
                            al_map_rgb(200, 0, 20));
  }

  // Draw the rounds won for p2
  if (player2->roundsWon >= 1) {
    al_draw_filled_circle(BUFFER_W - 140, (matchInterface->lifebarY + 22), 2,
                          al_map_rgb(200, 0, 20));
    if (player2->roundsWon == 2)
      al_draw_filled_circle(BUFFER_W - 155, (matchInterface->lifebarY + 22), 2,
                            al_map_rgb(200, 0, 20));
  }
}

/*
  Draw the initial text of the fight
  It deactivate the players controls for a 3 seconds then turn it on back
  again so the fight can start

  return the flag that control the controls
*/
bool roundStartWriter(MATCH_INTERFACE* matchInterface, unsigned short* frames,
                      ALLEGRO_FONT* font) {
  bool control = false;
  (*frames)++;
  if (*frames <= 80) {
    if (*frames <= 45) {
      if (matchInterface->rounds == 0)
        al_draw_text(font, al_map_rgb_f(1, 1, 1), BUFFER_W / 2.0,
                     BUFFER_H / 2.0, ALLEGRO_ALIGN_CENTER, "R O U N D   O N E");
      else if (matchInterface->rounds == 1)
        al_draw_text(font, al_map_rgb_f(1, 1, 1), BUFFER_W / 2.0,
                     BUFFER_H / 2.0, ALLEGRO_ALIGN_CENTER, "R O U N D   T W O");
      else
        al_draw_text(font, al_map_rgb_f(1, 1, 1), BUFFER_W / 2.0,
                     BUFFER_H / 2.0, ALLEGRO_ALIGN_CENTER,
                     "F I N A L   R O U N D");

    } else
      al_draw_text(font, al_map_rgb_f(1, 1, 1), BUFFER_W / 2.0, BUFFER_H / 2.0,
                   ALLEGRO_ALIGN_CENTER, "F I G H T  !");
  }
  // DRAW THE ROUND START FIGHT THING 90 frames
  // 90 FRAMES PASSED then
  else {
    control = true;
    frames = 0;
  }
  return control;
}

/*
  Ends a round writting K.O, return true when the writting ends so the code
  can reset the players or end the match
*/
bool roundEndWriter(MATCH_INTERFACE* matchInterface, unsigned short* frames,
                    ALLEGRO_FONT* font) {
  // DRAW THE K.O THING THEN AFTER 90 FRAMES RESET PLAYER AND START NEW
  // ROUND
  bool done = false;
  (*frames)++;
  if (*frames <= 90) {
    al_draw_text(font, al_map_rgb_f(1, 1, 1), BUFFER_W / 2.0, BUFFER_H / 2.0,
                 ALLEGRO_ALIGN_CENTER, "K . O");

  } else if (*frames > 90 && matchInterface->matchUP) {
    done = true;
    (*frames) = 0;
    matchInterface->roundUP = true;
  } else {
    done = true;
    matchInterface->roundUP = false;
  }
  return done;
}

/*
  Show the winner on the screen for 3 seconds, then close the game
*/
bool drawWinnerGreater(MATCH_INTERFACE* matchInterface, unsigned short* frames,
                       ALLEGRO_FONT* font, bool playerOneWon) {
  bool turnOnMatchLoop = true;
  (*frames)++;
  if (*frames <= 180) {
    if (*frames > 90) {
      if (playerOneWon)
        al_draw_text(font, al_map_rgb_f(1, 1, 1), BUFFER_W / 2.0,
                     BUFFER_H / 2.0, ALLEGRO_ALIGN_CENTER,
                     "P L A Y E R   O N E   W I N S  !");
      else
        al_draw_text(font, al_map_rgb_f(1, 1, 1), BUFFER_W / 2.0,
                     BUFFER_H / 2.0, ALLEGRO_ALIGN_CENTER,
                     "P L A Y E R   T W O   W I N S  !");
    }
  } else
    turnOnMatchLoop = false;
  return turnOnMatchLoop;
}

/*
  Destroy a match interface
*/
void matchInterfaceDestroyer(MATCH_INTERFACE* matchInterface) {
  free(matchInterface);
}
