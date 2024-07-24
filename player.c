#include "player.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/bitmap_draw.h>
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
  newPlayer->roundsWon = 0;
  newPlayer->animationDone = true;

  return newPlayer;
}

/*
 Reset the player
*/
void resetPlayer(PLAYER *player, int xPosit, int yPosit, bool facingRight,
                 bool matchEnd) {
  player->xPosition = xPosit;
  player->yPosition = yPosit;
  player->facingRight = facingRight;
  player->crouching = false;
  player->blocking = false;
  player->yAcel = 0;
  player->life = 150;
  player->animationDone = true;
  if (matchEnd) player->roundsWon = 0;
}

/*
  Updates the width and height of the player
*/
void updateWidthHeight(PLAYER *player) {
  // Shortcuts
  SPRITE_LIST currentSpriteP1 = player->character->currentSprite;
  short currentSpriteFrameP1 =
      player->character->fighterGraphics->movesSprites[currentSpriteP1]
          .currentFrame;

  short currentW =
      player->character->fighterGraphics->movesSprites[currentSpriteP1]
          .drawBoxWidth;
  short currentH =
      player->character->fighterGraphics->movesSprites[currentSpriteP1]
          .drawBoxHeight;

  short currentHurtW =
      player->character->fighterGraphics->movesSprites[currentSpriteP1]
          .hurtBoxWidth;
  short currentHurtH =
      player->character->fighterGraphics->movesSprites[currentSpriteP1]
          .hurtBoxHeight;

  // Assignment
  player->character->width = currentW;
  player->character->height = currentH;
  player->character->hurtWidth = currentHurtW;
  player->character->hurtHeight = currentHurtH;
}

void updateAnimation(PLAYER *player, long timerCount) {
  SPRITE_LIST currentSprite = player->character->currentSprite;
  short currentSpriteFrame =
      player->character->fighterGraphics->movesSprites[currentSprite]
          .currentFrame;
  short maxSpriteFrame =
      player->character->fighterGraphics->movesSprites[currentSprite].numFrames;

  if (!(timerCount % 3))
    (player->character->fighterGraphics->movesSprites[currentSprite]
         .currentFrame)++;
  player->character->fighterGraphics->movesSprites[currentSprite]
      .currentFrame %= maxSpriteFrame;
  if (player->character->fighterGraphics->movesSprites[currentSprite]
          .currentFrame == 0) {
    player->animationDone = true;
  }
}

/*
  Verify if the player is trying to get out of the bounds of the screen
*/
void playerScreenBounds(PLAYER *player) {
  int playerXmax = player->xPosition + player->character->hurtWidth;
  if (player->xPosition < 0) player->xPosition = 0;
  if (playerXmax > BUFFER_W)
    player->xPosition = BUFFER_W - player->character->hurtWidth;
}

/*
  Dont let the players get inside each other :9
*/
bool playersCollision(PLAYER *player1, PLAYER *player2) {
  int p1Xmax = player1->xPosition + player1->character->hurtWidth;
  int p2Xmax = player2->xPosition + player2->character->hurtWidth;
  int p1Ymax = player1->yPosition + player1->character->hurtHeight;
  int p2Ymax = player2->yPosition + player2->character->hurtHeight;

  return boxCollision(player1->xPosition, player1->yPosition, p1Xmax, p1Ymax,
                      player2->xPosition, player2->yPosition, p2Xmax, p2Ymax);
}

/*
  Verify which player is looking to the right side of the screen, so in this way
  we can make them look to each other for the entire match and fall in love
*/
void playerSight(PLAYER *player1, PLAYER *player2) {
  int p1Mid = (player1->xPosition + player1->character->hurtWidth) / 2;
  int p2Mid = (player2->xPosition + player2->character->hurtWidth) / 2;

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
    player->yPosition = FLOOR - player->character->height;
  }
}

/*
  Update things for player movements
*/
void playerUpdateMovements(PLAYER *player, PLAYER *anotherPlayer,
                           unsigned char *keyboardKeys, unsigned char *whichKey,
                           long timerCount) {
  bool jumping;
  int difPlayerFloor;
  SPRITE_LIST currentSprite;
  short maxSpriteFrame;

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

  if (player->animationDone) {
    if (keyboardKeys[whichKey[MOVE_RIGHT]]) {
      // If player is a moonwalker, well the king of pop gives him the power to
      // block xD
      if (!player->facingRight) player->blocking = true;

      if (!jumping) player->character->currentSprite = WALKING;  // WALKING
      currentSprite = player->character->currentSprite;
      maxSpriteFrame =
          player->character->fighterGraphics->movesSprites[currentSprite]
              .numFrames;

      player->xPosition += PLAYER_VEL;
      if (!(timerCount % 4))
        (player->character->fighterGraphics->movesSprites[currentSprite]
             .currentFrame)++;
      player->character->fighterGraphics->movesSprites[currentSprite]
          .currentFrame %= maxSpriteFrame;
      if (playersCollision(player, anotherPlayer))
        player->xPosition -= PLAYER_VEL;
    }
    if (keyboardKeys[whichKey[MOVE_LEFT]]) {
      // If player is a moonwalker, well the king of pop gives him the power to
      // block xD
      if (player->facingRight) player->blocking = true;

      if (!jumping) player->character->currentSprite = WALKING;  // WALKING
      currentSprite = player->character->currentSprite;
      maxSpriteFrame =
          player->character->fighterGraphics->movesSprites[currentSprite]
              .numFrames;

      player->xPosition -= PLAYER_VEL;
      if (!(timerCount % 4))
        (player->character->fighterGraphics->movesSprites[currentSprite]
             .currentFrame)++;
      player->character->fighterGraphics->movesSprites[currentSprite]
          .currentFrame %= maxSpriteFrame;

      if (playersCollision(player, anotherPlayer))
        player->xPosition += PLAYER_VEL;
    }
    if (keyboardKeys[whichKey[JUMP]] && !jumping) {
      // Give me some boost to reach the skyies o/
      player->character->currentSprite = STEADY;  // JUMPING
      player->yAcel = PLAYER_VEL * 3;
    }
    if (keyboardKeys[whichKey[CROUCH]] && !jumping) {
      player->crouching = true;
      player->character->currentSprite = CROUCHING;  // CROUNCHING
    }
  } else
    updateAnimation(player, timerCount);
  updateWidthHeight(player);

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
  SPRITE_LIST currentSprite = player->character->currentSprite;

  // Define limits and localization of the hurt box for player 1
  float midX = (player->xPosition + (player->character->width / 2.0));
  float midY = (player->yPosition + (player->character->height / 2.0));
  float hurtBox_X1 = (midX - (player->character->hurtWidth / 2.0));
  float hurtBox_X2 = (midX + (player->character->hurtWidth / 2.0));
  float hurtBox_Y1 = (midY - (player->character->hurtHeight / 2.0));
  float hurtBox_Y2 = (midY + (player->character->hurtHeight / 2.0));

  // Define limits and localization of the hurt box for player 2
  float midX2 =
      (anotherPlayer->xPosition + (anotherPlayer->character->width / 2.0));
  float midY2 =
      (anotherPlayer->yPosition + (anotherPlayer->character->height / 2.0));
  float hurtBox2_X1 = (midX2 - (anotherPlayer->character->hurtWidth / 2.0));
  float hurtBox2_X2 = (midX2 + (anotherPlayer->character->hurtWidth / 2.0));
  float hurtBox2_Y1 = (midY2 - (anotherPlayer->character->hurtHeight / 2.0));
  float hurtBox2_Y2 = (midY2 + (anotherPlayer->character->hurtHeight / 2.0));

  if (player->animationDone) {
    if (keyboardKeys[whichKey[PUNCH]]) {
      player->animationDone = false;
      player->character->currentSprite = PUNCHING;  // PUNCHING
      if (punch(hurtBox_X1, hurtBox_X2, hurtBox_Y1, hurtBox_Y2,
                player->facingRight, hurtBox2_X1, hurtBox2_X2, hurtBox2_Y1,
                hurtBox2_Y2)) {
        if (!anotherPlayer->blocking) {
          anotherPlayer->life -= 1;
          anotherPlayer->character->currentSprite = STEADY;  // GOT_HIT
        } else
          anotherPlayer->character->currentSprite = STEADY;  // DEFENDING

        // knock back thing
        if (anotherPlayer->facingRight)
          anotherPlayer->xPosition -= 2;
        else
          anotherPlayer->xPosition += 2;
      }
    }
  }
}

/*
  Draw the player on the screen
*/
void drawPlayer(PLAYER *player, ALLEGRO_COLOR playerColor, long timerIdle) {
  ALLEGRO_COLOR color = playerColor;

  // al_draw_filled_rectangle(player->xPosition, player->yPosition,
  //                          (player->character->width + player->xPosition),
  //                          (player->yPosition + player->character->height),
  //                          color);

  // SHORTCUTS TO ACCESS SOME VARIABLES
  SPRITE_LIST currentSprite = player->character->currentSprite;

  short maxSpriteFrame =
      player->character->fighterGraphics->movesSprites[currentSprite].numFrames;

  short currentSpriteFrame =
      player->character->fighterGraphics->movesSprites[currentSprite]
          .currentFrame;

  /* ------------------ FOR TESTS ONLY ---------------- */
  float midX = (player->xPosition + (player->character->width / 2.0));
  float midY = (player->yPosition + (player->character->height / 2.0));

  float hurtBox_X1 = (midX - (player->character->hurtWidth / 2.0));
  float hurtBox_X2 = (midX + (player->character->hurtWidth / 2.0));
  float hurtBox_Y1 = (midY - (player->character->hurtHeight / 2.0));
  float hurtBox_Y2 = (midY + (player->character->hurtHeight / 2.0));

  al_draw_rectangle(hurtBox_X1, hurtBox_Y1, hurtBox_X2, hurtBox_Y2, color, 2.0);

  al_draw_rectangle(hurtBox_X2, hurtBox_Y1 + 15, hurtBox_X2 + 10,
                    hurtBox_Y1 + 15 + 6, al_map_rgb(255, 255, 255), 2);

  /* ------------------------------------------------------- */

  int playerMaxX = (player->xPosition + player->character->width);
  // ANIMATIONS AND CONFIGURATIONS FOR DRAW SPRITES
  switch (player->character->currentSprite) {
    // STEADY ANIMATION
    case (STEADY):
      if (!(timerIdle % 10)) {
        (player->character->fighterGraphics->movesSprites[currentSprite]
             .currentFrame)++;
        player->character->fighterGraphics->movesSprites[currentSprite]
            .currentFrame %= maxSpriteFrame;
      }
      break;

    case (WALKING):
      break;

    case (JUMPING):
      break;

    case (CROUCHING):
      break;

    case (DEFENDING):
      color = al_map_rgb(10, 180, 10);
      break;

    case (GOT_HIT):
      color = al_map_rgb(255, 255, 255);
      break;

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

  // DRAW THE PLAYERS
  if (player->facingRight)
    al_draw_bitmap(
        player->character->fighterGraphics->movesSprites[currentSprite]
            .sprites[currentSpriteFrame],
        player->xPosition, player->yPosition, 0);
  else
    al_draw_bitmap(
        player->character->fighterGraphics->movesSprites[currentSprite]
            .sprites[currentSpriteFrame],
        player->xPosition, player->yPosition, ALLEGRO_FLIP_HORIZONTAL);

  al_draw_filled_circle(midX, midY, 2.0, color);
  // ONDE VOU COLOCAR ESSES RESETS????
  // SÓ CHAMO ESSES RESETS QUANDO A ANIMAÇÃO DE UMA SPRITE TERMINAR
  if (player->animationDone) {
    player->character->currentSprite = STEADY;
    player->blocking = false;
    player->crouching = false;
    updateWidthHeight(player);
  }
}

/*
  Free up the space that were being utilized by a Player instance
*/
void playerDestroyer(PLAYER *player) {
  characterDestroyer(player->character);
  free(player);
}
