#include "matchInterface.h"

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/bitmap_io.h>
#include <allegro5/color.h>
#include <time.h>

/*
  Initialize a new match interface
*/
MATCH_INTERFACE* initMatchInterface(PLAYER* player1, PLAYER* player2) {
  MATCH_INTERFACE* newMatchInterface =
      (MATCH_INTERFACE*)malloc(sizeof(MATCH_INTERFACE));
  if (newMatchInterface == NULL) exit(1);

  newMatchInterface->lifebarP1X = 40;
  newMatchInterface->lifebarP2Width = BUFFER_W;
  newMatchInterface->lifebarY = 9;
  newMatchInterface->lifebarHeight = 9;

  newMatchInterface->lifebarColor = al_map_rgb(243, 243, 0);

  // Load the sprite sheet
  newMatchInterface->sheet =
      al_load_bitmap("./images/matchInterface/matchInterfaceSpriteSheet.png");
  alCheckInit(newMatchInterface->sheet, "match interface sheet");

  // Loading round sprites
  newMatchInterface->roundSprite = grabSprite(
      newMatchInterface->sheet, ROUND_S_X, ROUND_S_Y, ROUND_S_W, ROUND_S_H);
  newMatchInterface->fRoundSprite = grabSprite(
      newMatchInterface->sheet, FROUND_S_X, ROUND_S_Y, FROUND_S_W, ROUND_S_H);

  // Loading number sprites
  newMatchInterface->numOneSprite = grabSprite(
      newMatchInterface->sheet, N_ONE_S_X, NUMBER_S_Y, N_ONE_S_W, NUMBER_S_H);
  newMatchInterface->numTwoSprite = grabSprite(
      newMatchInterface->sheet, N_TWO_S_X, NUMBER_S_Y, N_TWO_S_W, NUMBER_S_H);

  // Loading fight sprites
  newMatchInterface->fightSprite = grabSprite(
      newMatchInterface->sheet, FIGHT_S_X, FIGHT_S_Y, FIGHT_S_W, FIGHT_S_H);

  // Loading counting rounds
  newMatchInterface->countWonSprite =
      grabSprite(newMatchInterface->sheet, RC_S_X, RC_S_Y, RC_S_W, RC_S_H);

  // Loading player wins
  newMatchInterface->p1Wins = grabSprite(newMatchInterface->sheet, P1_WINS_X,
                                         P1_WINS_Y, P1_WINS_W, P1_WINS_H);
  newMatchInterface->p2Wins = grabSprite(newMatchInterface->sheet, P2_WINS_X,
                                         P2_WINS_Y, P2_WINS_W, P2_WINS_H);

  // Loading K.O
  newMatchInterface->ko =
      grabSprite(newMatchInterface->sheet, KO_X, KO_Y, KO_W, KO_H);

  // Loading life bar things
  newMatchInterface->lifeBarBackground =
      grabSprite(newMatchInterface->sheet, LB_X, LB_Y, LB_W, LB_H);
  newMatchInterface->lifeBarAnimation =
      grabSprite(newMatchInterface->sheet, LB_A_X, LB_A_Y, LB_A_W, LB_A_H);
  return newMatchInterface;
}

/*
  Updates the match interface
*/
void matchInterfaceUpdate(MATCH_INTERFACE* matchInterface, PLAYER* player1,
                          PLAYER* player2) {
  matchInterface->lifebarP1Width = player1->life;
  matchInterface->lifebarP2X = BUFFER_W - player2->life - 40;
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
                        PLAYER* player2, long timerCount, short* twinkle) {
  al_draw_bitmap(matchInterface->lifeBarBackground,
                 (BUFFER_W / 2.0) - (LB_W / 2.0), 5, 0);
  int timerDelay;
  if (*twinkle)
    timerDelay = 30;
  else
    timerDelay = 50;
  if (!(timerCount % timerDelay)) (*twinkle) ^= 1;
  if (!(*twinkle))
    al_draw_bitmap(matchInterface->lifeBarAnimation,
                   (BUFFER_W / 2.0) - (LB_A_W / 2.0), 5, 0);

  // Draw the lifebars
  al_draw_filled_rectangle(
      matchInterface->lifebarP1X, matchInterface->lifebarY,
      (matchInterface->lifebarP1X + matchInterface->lifebarP1Width),
      (matchInterface->lifebarY + matchInterface->lifebarHeight),
      matchInterface->lifebarColor);
  al_draw_filled_rectangle(
      matchInterface->lifebarP2X, matchInterface->lifebarY, BUFFER_W - 40,
      (matchInterface->lifebarY + matchInterface->lifebarHeight),
      matchInterface->lifebarColor);
  // Draw the rounds won for p1
  if (player1->roundsWon >= 1) {
    al_draw_bitmap(matchInterface->countWonSprite, 140,
                   matchInterface->lifebarY + 10, 0);
    if (player1->roundsWon == 2)
      al_draw_bitmap(matchInterface->countWonSprite, 120,
                     matchInterface->lifebarY + 10, 0);
  }

  // Draw the rounds won for p2
  if (player2->roundsWon >= 1) {
    al_draw_bitmap(matchInterface->countWonSprite, BUFFER_W - 160,
                   matchInterface->lifebarY + 10, 0);

    if (player2->roundsWon == 2)
      al_draw_bitmap(matchInterface->countWonSprite, BUFFER_W - 140,
                     matchInterface->lifebarY + 10, 0);
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
      if (matchInterface->rounds == 0) {
        al_draw_bitmap(matchInterface->roundSprite,
                       (BUFFER_W / 2.0) - (ROUND_S_W / 2.0),
                       (BUFFER_H / 2.0) - (ROUND_S_H / 2.0), 0);
        al_draw_bitmap(matchInterface->numOneSprite,
                       (BUFFER_W / 2.0) + (ROUND_S_W / 2.0) + (N_ONE_S_W),
                       (BUFFER_H / 2.0) - (ROUND_S_H / 2.0), 0);
      } else if (matchInterface->rounds == 1) {
        al_draw_bitmap(matchInterface->roundSprite,
                       (BUFFER_W / 2.0) - (ROUND_S_W / 2.0),
                       (BUFFER_H / 2.0) - (ROUND_S_H / 2.0), 0);
        al_draw_bitmap(matchInterface->numTwoSprite,
                       (BUFFER_W / 2.0) + (ROUND_S_W / 2.0) + (N_TWO_S_W),
                       (BUFFER_H / 2.0) - (ROUND_S_H / 2.0), 0);

      } else
        al_draw_bitmap(matchInterface->fRoundSprite,
                       (BUFFER_W / 2.0) - (FROUND_S_W / 2.0),
                       (BUFFER_H / 2.0) - (ROUND_S_H / 2.0), 0);

    } else
      al_draw_bitmap(matchInterface->fightSprite,
                     (BUFFER_W / 2.0) - (FIGHT_S_W / 2.0),
                     (BUFFER_H / 2.0) - (FIGHT_S_H / 2.0), 0);
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
    al_draw_bitmap(matchInterface->ko, (BUFFER_W / 2.0) - (KO_W / 2.0),
                   (BUFFER_H / 2.0) - (KO_H / 2.0), 0);

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
        al_draw_bitmap(matchInterface->p1Wins,
                       (BUFFER_W / 2.0) - (P1_WINS_W / 2.0),
                       (BUFFER_H / 2.0) - (P1_WINS_H / 2.0), 0);
      else
        al_draw_bitmap(matchInterface->p2Wins,
                       (BUFFER_W / 2.0) - (P2_WINS_W / 2.0),
                       (BUFFER_H / 2.0) - (P2_WINS_H / 2.0), 0);
    }
  } else
    turnOnMatchLoop = false;
  return turnOnMatchLoop;
}

/*
  Destroy a match interface
*/
void matchInterfaceDestroyer(MATCH_INTERFACE* matchInterface) {
  al_destroy_bitmap(matchInterface->numOneSprite);
  al_destroy_bitmap(matchInterface->numTwoSprite);
  al_destroy_bitmap(matchInterface->roundSprite);
  al_destroy_bitmap(matchInterface->fRoundSprite);
  al_destroy_bitmap(matchInterface->fightSprite);
  al_destroy_bitmap(matchInterface->countWonSprite);
  al_destroy_bitmap(matchInterface->p1Wins);
  al_destroy_bitmap(matchInterface->p2Wins);
  al_destroy_bitmap(matchInterface->ko);
  al_destroy_bitmap(matchInterface->sheet);
  free(matchInterface);
}
