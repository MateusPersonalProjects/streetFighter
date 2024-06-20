#include "player.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <allegro5/events.h>
#include <allegro5/keycodes.h>
#include <stdlib.h>

#include "character.h"
#include "display.h"
#include "environment.h"
#include "misc.h"

#define PLAYER_VEL 5

/*
  Initialize a new player
*/
PLAYER *initPlayer(CHARACTER *character, int xPosit, int yPosit,
                   bool facingRight) {
  PLAYER *newPlayer = (PLAYER *)malloc(sizeof(PLAYER));
  if (newPlayer == NULL) exit(1);

  newPlayer->character = character;
  newPlayer->xPosition = xPosit;
  newPlayer->yPosition = yPosit;
  newPlayer->facingRight = facingRight;
  newPlayer->crouching = false;
  newPlayer->blocking = false;
  newPlayer->yAcel = 0;
  newPlayer->life = 150;

  return newPlayer;
}

/*
  Verify if the player is trying to get out of the bounds of the screen
*/
void playerScreenBounds(PLAYER *player) {
  int playerXmax = player->xPosition + player->character->width;
  if (player->xPosition < 0) player->xPosition = 0;
  if (playerXmax > BUFFER_W)
    player->xPosition = BUFFER_W - player->character->width;
}

/*
  Dont let the players get inside each other :9
*/
bool playersCollision(PLAYER *player1, PLAYER *player2) {
  int p1Xmax = player1->xPosition + player1->character->width;
  int p2Xmax = player2->xPosition + player2->character->width;
  int p1Ymax = player1->yPosition + player1->character->height;
  int p2Ymax = player2->yPosition + player2->character->height;

  return boxCollision(player1->xPosition, player1->yPosition, p1Xmax, p1Ymax,
                      player2->xPosition, player2->yPosition, p2Xmax, p2Ymax);
}

/*
  Verify which player is looking to the right side of the screen, so in this way
  we can make them look to each other for the entire match and fall in love
*/
void playerSight(PLAYER *player1, PLAYER *player2) {
  int p1Mid = (player1->xPosition + player1->character->width) / 2;
  int p2Mid = (player2->xPosition + player2->character->width) / 2;

  if (p2Mid < p1Mid) {
    player2->facingRight = true;
    player1->facingRight = false;
  } else {
    player1->facingRight = true;
    player2->facingRight = false;
  }
}

/*
 Works with the gravity and if the players collided on the air
*/
void playerJump(PLAYER *player, PLAYER *anotherPlayer, bool jumping) {
  // If the player is jumping gravity starts to desacelerate him
  player->yPosition -= player->yAcel;
  if (playersCollision(player, anotherPlayer)) {
    player->yPosition += player->yAcel;
    // if (jumping && ((anotherPlayer->yPosition +
    //                  anotherPlayer->character->height) < FLOOR)) {
    player->yAcel = 0;
    //  player->yAcel -= GRAVITY_COEF;
    //}
    //} else
    // We lose velocity because of gravity
    // player->yAcel -= GRAVITY_COEF;
  }
}

/*
 Changes the y position when the player is crouching, and dont let the another
 player stand on the player head when he is crouching
*/
void playerCrouch(PLAYER *player, PLAYER *anotherPlayer) {
  // if the player in crouching and the other player jumped on him, he cannot
  // stand and the other player is going to slip away
  if (playersCollision(player, anotherPlayer)) {
    anotherPlayer->xPosition += PLAYER_VEL;
    player->crouching = true;
  }
  // if the player is crouching his y position changes
  if (player->crouching) {
    player->yPosition = FLOOR - player->character->crouchHeight;
  }
}

/*
  Update things for player movements
*/
void playerUpdateMovements(PLAYER *player, PLAYER *anotherPlayer,
                           unsigned char *keyboardKeys,
                           unsigned char *whichKey) {
  bool jumping;
  int difPlayerFloor;

  // If the player is not on the ground, well he is jumping xD
  jumping = ((player->yPosition + player->character->height) < FLOOR);
  // player->crouching = false;
  // player->blocking = false;

  if (!jumping) {
    player->yAcel = 0;
    difPlayerFloor = (player->yPosition + player->character->height) - FLOOR;
    // Wether the player got into the ground we get him back
    player->yPosition -= difPlayerFloor;
    // player->character->currentSprite = STEADY;
  }

  if (keyboardKeys[whichKey[MOVE_RIGHT]]) {
    // If player is a moonwalker, well the king of pop gives him the power to
    // block xD
    if (!player->facingRight) player->blocking = true;

    if (!jumping) player->character->currentSprite = WALKING;
    player->xPosition += PLAYER_VEL;
    if (playersCollision(player, anotherPlayer))
      player->xPosition -= PLAYER_VEL;
  }
  if (keyboardKeys[whichKey[MOVE_LEFT]]) {
    // If player is a moonwalker, well the king of pop gives him the power to
    // block xD
    if (player->facingRight) player->blocking = true;

    if (!jumping) player->character->currentSprite = WALKING;
    player->xPosition -= PLAYER_VEL;
    if (playersCollision(player, anotherPlayer))
      player->xPosition += PLAYER_VEL;
  }
  if (keyboardKeys[whichKey[JUMP]] && !jumping) {
    // Give me some boost to reach the skyies o/
    player->character->currentSprite = JUMPING;
    player->yAcel = PLAYER_VEL * 3;
  }
  if (keyboardKeys[whichKey[CROUCH]] && !jumping) {
    player->crouching = true;
    player->character->currentSprite = CROUCHING;
  }
  // Changes y position (the head position, because he is croucing right)
  playerCrouch(player, anotherPlayer);

  // Gravity effect and collision on the sky
  playerJump(player, anotherPlayer, jumping);
  player->yAcel -= GRAVITY_COEF;

  // Dont let the player get out of the bounds of the screen
  playerScreenBounds(player);

  // Who is looking to the right side
  playerSight(player, anotherPlayer);
}

/*
 * Update things for the player attacks
 */
void playerUpdateAttacks(PLAYER *player, PLAYER *anotherPlayer,
                         unsigned char *keyboardKeys, unsigned char *whichKey) {
  int p1MaxX = player->xPosition + player->character->width;
  int p1MaxY = player->xPosition + player->character->height;
  int p2MaxX = anotherPlayer->xPosition + anotherPlayer->character->width;
  int p2MaxY = anotherPlayer->yPosition + anotherPlayer->character->height;

  if (keyboardKeys[whichKey[PUNCH]]) {
    player->character->currentSprite = PUNCHING;
    if (punch(player->xPosition, p1MaxX, player->yPosition, p1MaxY,
              player->facingRight, anotherPlayer->xPosition, p2MaxX,
              anotherPlayer->yPosition, p2MaxY)) {
      if (!anotherPlayer->blocking) {
        anotherPlayer->life -= 1;
        anotherPlayer->character->currentSprite = GOT_HIT;
      } else
        anotherPlayer->character->currentSprite = DEFENDING;

      if (anotherPlayer->facingRight)
        anotherPlayer->xPosition -= 2;
      else
        anotherPlayer->xPosition += 2;
    }
  }
}

/*
  Draw the player on the screen
*/
void drawPlayer(PLAYER *player, ALLEGRO_COLOR playerColor) {
  int height = player->character->height;
  ALLEGRO_COLOR color;

  if (player->crouching) height = player->character->crouchHeight;

  if (player->character->currentSprite == GOT_HIT)
    color = al_map_rgb(255, 255, 255);
  else if (player->character->currentSprite == DEFENDING)
    color = al_map_rgb(10, 180, 10);
  else
    color = playerColor;

  al_draw_filled_rectangle(player->xPosition, player->yPosition,
                           (player->character->width + player->xPosition),
                           (player->yPosition + height), color);

  // Bette davis eyes
  int playerMaxX = (player->xPosition + player->character->width);
  if (player->facingRight) {
    al_draw_filled_rectangle((playerMaxX - 10), player->yPosition + 5,
                             (playerMaxX + 1), (player->yPosition + 10),
                             al_map_rgb(255, 255, 255));
  } else {
    al_draw_filled_rectangle((player->xPosition - 1), (player->yPosition + 5),
                             (player->xPosition + 10), (player->yPosition + 10),
                             al_map_rgb(255, 255, 255));
  }

  switch (player->character->currentSprite) {
    case (PUNCHING):
      if (player->facingRight)
        al_draw_filled_rectangle(playerMaxX, player->yPosition + 15,
                                 playerMaxX + 10, player->yPosition + 21,
                                 al_map_rgb(255, 255, 255));
      else
        al_draw_filled_rectangle(player->xPosition - 10, player->yPosition + 15,
                                 player->xPosition + 1, player->yPosition + 21,
                                 al_map_rgb(255, 255, 255));
      break;
  }

  // ONDE VOU COLOCAR ESSES RESETS????
  player->character->currentSprite = STEADY;
  player->blocking = false;
  player->crouching = false;
}

/*
  Free up the space that were being utilized by a Player instance
*/
void playerDestroyer(PLAYER *player) {
  characterDestroyer(player->character);
  free(player);
}
