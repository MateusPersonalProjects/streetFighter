#include "player.h"

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
  newPlayer->life = PLAYER_LIFE;
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
  player->life = PLAYER_LIFE;
  player->character->fighterGraphics->movesSprites[DEAD].currentFrame = 0;
  player->character->fighterGraphics->movesSprites[VICTORY].currentFrame = 0;
  player->animationDone = true;
}

/*
  Updates the width and height of the player
  This function must be called every time a fighter changes sprites
*/
void updateWidthHeight(PLAYER *player) {
  // Shortcuts
  SPRITE_LIST currentSpriteP1 = player->character->currentSprite;

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

/*
  This function updates the state of an attack animation going to the next
  frame,and if the frames return to 0 the animation is turned off
*/
void updateAnimation(PLAYER *player, long timerCount) {
  // Get the current sprite
  SPRITE_LIST currentSprite = player->character->currentSprite;

  // Get the current frame the sprite is at
  short currentSpriteFrame =
      player->character->fighterGraphics->movesSprites[currentSprite]
          .currentFrame;

  // Get the max frame the animation can reach out
  short maxSpriteFrame =
      player->character->fighterGraphics->movesSprites[currentSprite].numFrames;

  int modAnimation =
      player->character->fighterGraphics->movesSprites[currentSprite]
          .modAnimation;

  // JUMP must be treated in another way
  if (currentSprite == JUMPING) {
    if (!((player->yAcel) % modAnimation))
      (player->character->fighterGraphics->movesSprites[currentSprite]
           .currentFrame)++;
    // If the animation reaches zero again it is done and turned off
    player->character->fighterGraphics->movesSprites[currentSprite]
        .currentFrame %= maxSpriteFrame;

    player->animationDone = true;
  }

  // Stay in the last frame
  else if (currentSprite == DEAD) {
    bool done = (currentSpriteFrame == maxSpriteFrame - 1);
    if (!(done) && !(timerCount % modAnimation)) {
      (player->character->fighterGraphics->movesSprites[currentSprite]
           .currentFrame)++;
      if (player->facingRight)
        player->xPosition -= 10;
      else
        player->yPosition += 10;
    }

    // If the animation finished the dead body goes directly to the ground
    else if (done) {
      player->yPosition =
          FLOOR -
          player->character->fighterGraphics->movesSprites[DEAD].drawBoxHeight;
    }
  }
  // Stay in the last frame
  else if (currentSprite == VICTORY) {
    bool done = (currentSpriteFrame == maxSpriteFrame - 1);
    if (!(done) && !(timerCount % modAnimation)) {
      (player->character->fighterGraphics->movesSprites[currentSprite]
           .currentFrame)++;
    }
    player->yPosition =
        FLOOR -
        player->character->fighterGraphics->movesSprites[VICTORY].drawBoxHeight;
  }

  // Another animations
  else {
    if (maxSpriteFrame != 1) {
      // Updates the frame for the animation
      if (!(timerCount % modAnimation))
        (player->character->fighterGraphics->movesSprites[currentSprite]
             .currentFrame)++;
      // If the animation reaches zero again it is done and turned off
      player->character->fighterGraphics->movesSprites[currentSprite]
          .currentFrame %= maxSpriteFrame;
      if (player->character->fighterGraphics->movesSprites[currentSprite]
              .currentFrame == 0) {
        player->animationDone = true;
      }
    }
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
 Works with the gravity and treats collision in the air
*/
void playerJump(PLAYER *player, PLAYER *anotherPlayer, bool jumping) {
  // If the player is jumping gravity starts to desacelerate him
  if (jumping) {
    if (player->animationDone) player->character->currentSprite = JUMPING;
  }
  player->yPosition -= player->yAcel;
  if (playersCollision(player, anotherPlayer)) {
    player->yPosition += player->yAcel;
    player->yAcel = 0;
    player->character->currentSprite = STEADY;

    // Sliperry head
    if (player->xPosition <= 75)
      player->xPosition += PLAYER_VEL * 4;
    else if (player->xPosition >= (BUFFER_W - 75))
      player->xPosition -= PLAYER_VEL * 4;
    else
      player->xPosition -= PLAYER_VEL * 4;
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
    player->crouching = true;
    if (anotherPlayer->xPosition <= 75)
      anotherPlayer->xPosition += PLAYER_VEL * 4;
    else if (anotherPlayer->xPosition >= (BUFFER_W - 75))
      anotherPlayer->xPosition -= PLAYER_VEL * 4;
    else
      anotherPlayer->xPosition += PLAYER_VEL * 4;
  }
  // if the player is crouching his y position changes
  if (player->crouching) {
    player->yPosition = FLOOR - player->character->height;
  }
}

/*
 * If the hurt box for some reason got inside the another player hurt box, this
 * funcion fix it
 */
void getOutCrazy(PLAYER *player, PLAYER *anotherPlayer) {
  int boundP1 = player->xPosition + player->character->width - 10;
  int bound2P1 = player->xPosition + 10;

  int centerP2 =
      anotherPlayer->xPosition + (anotherPlayer->character->width / 2);

  /* If the center of the Player 2 in in the middle of the Player 1 bounds they
  got inside each other */
  if (centerP2 >= boundP1 && centerP2 <= bound2P1) {
    if (anotherPlayer->xPosition <= 75)
      anotherPlayer->xPosition += anotherPlayer->character->width;
    else if (anotherPlayer->xPosition >= (BUFFER_W - 75))
      anotherPlayer->xPosition -= anotherPlayer->character->width;
    else
      anotherPlayer->xPosition += anotherPlayer->character->width;
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

  // If the player is not on the ground, well he is jumping xD
  jumping = ((player->yPosition + player->character->height) <
             (FLOOR - PLAYER_VEL - 2));

  if (!jumping) {
    player->yAcel = 0;
    difPlayerFloor = (player->yPosition + player->character->height) - FLOOR;
    // Wether the player got into the ground we get him back
    player->yPosition -= difPlayerFloor;
    // player->character->currentSprite = STEADY;
  }

  // IF THERE IS AN ATTACK ANIMATION ROLLING HE CANNOT CHANGE POSITION
  if (player->animationDone) {
    if (!player->crouching && !jumping && keyboardKeys[whichKey[JUMP]]) {
      // Give me some boost to reach the skyies o/
      player->character->currentSprite = JUMPING;  // JUMPING
      player->yAcel = PLAYER_VEL * 3;
      player->character->fighterGraphics->movesSprites[JUMPING].currentFrame =
          0;
    }

    if (!jumping && keyboardKeys[whichKey[CROUCH]]) {
      player->crouching = true;
      player->character->currentSprite = CROUCHING;  // CROUNCHING
    }

    if (keyboardKeys[whichKey[MOVE_RIGHT]]) {
      /* If player is a moonwalker, well the king of pop gives him the power to
       block xD */
      if (!player->facingRight) player->blocking = true;
      if (!player->crouching) {
        if (!jumping) player->character->currentSprite = WALKING;  // WALKING
        player->xPosition += PLAYER_VEL;
        if (playersCollision(player, anotherPlayer))
          player->xPosition -= PLAYER_VEL;
      }
    }

    if (keyboardKeys[whichKey[MOVE_LEFT]]) {
      /* If player is a moonwalker, well the king of pop gives him the power to
       block xD */
      if (player->facingRight) player->blocking = true;
      if (!player->crouching) {
        if (!jumping) player->character->currentSprite = WALKING;  // WALKING
        player->xPosition -= PLAYER_VEL;
        if (playersCollision(player, anotherPlayer))
          player->xPosition += PLAYER_VEL;
      }
    }
  }

  // Every time we change a animation the Width and Height must be att
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

  // Not going to the get inside each other come on
  getOutCrazy(player, anotherPlayer);
}

/*
 * Update things for the player attacks
 */
void playerUpdateAttacks(PLAYER *player, PLAYER *anotherPlayer,
                         unsigned char *keyboardKeys, unsigned char *whichKey) {
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

  /* IF THERE IS AN ATTACK ANIMATION ROLLING HE CANNOT CHANGE ATTACK UNTIL IT
   FINISHES OFF */
  if (player->animationDone) {
    /* -------------------- PUNCH --------------------- */
    if (keyboardKeys[whichKey[PUNCH]]) {
      if (!(player->character->currentSprite == JUMPING) &&
          !(player->character->currentSprite == CROUCHING)) {
        // Sets the animation
        player->animationDone = false;
        player->character->currentSprite = PUNCHING;

        // CHECK IF THE ANOTHER PLAYER GOT HIT
        if (hitCheck(hurtBox_X1, hurtBox_X2, hurtBox_Y1, hurtBox_Y2,
                     player->character->fighterGraphics->movesSprites[PUNCHING]
                         .hitBoxWidth,
                     player->character->fighterGraphics->movesSprites[PUNCHING]
                         .hitBox_Y,
                     player->character->fighterGraphics->movesSprites[PUNCHING]
                         .hitBoxHeight,
                     player->facingRight, hurtBox2_X1, hurtBox2_X2, hurtBox2_Y1,
                     hurtBox2_Y2)) {
          // IF GOT HIT AND WAS NOT DEFENDING
          if (!anotherPlayer->blocking) {
            al_play_sample(anotherPlayer->character->sounds.gotHit, 1.0, 0.0,
                           1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            anotherPlayer->life -= 3;
            anotherPlayer->animationDone = false;

            if (!anotherPlayer->crouching)
              anotherPlayer->character->currentSprite = GOT_HIT;
            else
              anotherPlayer->character->currentSprite = GOT_CROUCH_HIT;
          }
          // IF WAS DEFENDING
          else {
            al_play_sample(anotherPlayer->character->sounds.blockHit, 1.0, 0.0,
                           1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            anotherPlayer->animationDone = false;
            if (!anotherPlayer->crouching)
              anotherPlayer->character->currentSprite = DEFENDING;
            else
              anotherPlayer->character->currentSprite = CROUCH_BLOCK;
          }
          // knock back thing
          if (anotherPlayer->facingRight)
            anotherPlayer->xPosition -= 2;
          else
            anotherPlayer->xPosition += 2;
        }
        // If the another player did not got hit
        else
          al_play_sample(player->character->sounds.attack, 1.0, 0.0, 1.0,
                         ALLEGRO_PLAYMODE_ONCE, NULL);
      }

      // CROUCH PUNCH
      if (player->character->currentSprite == CROUCHING) {
        // Sets the animation
        player->animationDone = false;
        player->character->currentSprite = CROUCH_PUNCH;
        // CHECK IF THE ANOTHER PLAYER GOT HIT
        if (hitCheck(
                hurtBox_X1, hurtBox_X2, hurtBox_Y1, hurtBox_Y2,
                player->character->fighterGraphics->movesSprites[CROUCH_PUNCH]
                    .hitBoxWidth,
                player->character->fighterGraphics->movesSprites[CROUCH_PUNCH]
                    .hitBox_Y,
                player->character->fighterGraphics->movesSprites[CROUCH_PUNCH]
                    .hitBoxHeight,
                player->facingRight, hurtBox2_X1, hurtBox2_X2, hurtBox2_Y1,
                hurtBox2_Y2)) {
          // IF GOT HIT AND WAS NOT DEFENDING
          if (!anotherPlayer->blocking) {
            al_play_sample(anotherPlayer->character->sounds.gotHit, 1.0, 0.0,
                           1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            anotherPlayer->life -= 3;
            anotherPlayer->animationDone = false;

            if (!anotherPlayer->crouching)
              anotherPlayer->character->currentSprite = GOT_HIT;
            else
              anotherPlayer->character->currentSprite = GOT_CROUCH_HIT;
          }

          // IF WAS DEFENDING
          else {
            al_play_sample(anotherPlayer->character->sounds.blockHit, 1.0, 0,
                           1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            anotherPlayer->animationDone = false;

            if (!anotherPlayer->crouching)
              anotherPlayer->character->currentSprite = DEFENDING;
            else
              anotherPlayer->character->currentSprite = CROUCH_BLOCK;
          }

          // knock back thing
          if (anotherPlayer->facingRight)
            anotherPlayer->xPosition -= 2;
          else
            anotherPlayer->xPosition += 2;
        }
        // If didnt got hit
        else
          al_play_sample(player->character->sounds.attack, 1.0, 0.0, 1.0,
                         ALLEGRO_PLAYMODE_ONCE, NULL);
      }
    }

    /* ---------------------- KICK ---------------------- */
    if (!(player->character->currentSprite == CROUCHING) &&
        keyboardKeys[whichKey[KICK]]) {
      if (!(player->character->currentSprite == JUMPING)) {
        // Sets the animation
        player->animationDone = false;
        player->character->currentSprite = KICKING;

        if (hitCheck(hurtBox_X1, hurtBox_X2, hurtBox_Y1, hurtBox_Y2,
                     player->character->fighterGraphics->movesSprites[KICKING]
                         .hitBoxWidth,
                     player->character->fighterGraphics->movesSprites[KICKING]
                         .hitBox_Y,
                     player->character->fighterGraphics->movesSprites[KICKING]
                         .hitBoxHeight,
                     player->facingRight, hurtBox2_X1, hurtBox2_X2, hurtBox2_Y1,
                     hurtBox2_Y2)) {
          // IF GOT HIT AND WAS NOT DEFENDING
          if (!anotherPlayer->blocking) {
            al_play_sample(anotherPlayer->character->sounds.gotHit, 1.0, 0.0,
                           1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            anotherPlayer->life -= 5;
            anotherPlayer->animationDone = false;

            if (!anotherPlayer->crouching)
              anotherPlayer->character->currentSprite = GOT_FACE_HIT;
            else
              anotherPlayer->character->currentSprite = GOT_CROUCH_HIT;
          }
          // IF GOT HIT AND WAS DEFENDING
          else {
            al_play_sample(anotherPlayer->character->sounds.blockHit, 1.0, 0.0,
                           1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            anotherPlayer->animationDone = false;
            if (!anotherPlayer->crouching)
              anotherPlayer->character->currentSprite = DEFENDING;  // DEFENDING
            else
              anotherPlayer->character->currentSprite = CROUCH_BLOCK;
          }
          // knock back thing
          if (anotherPlayer->facingRight)
            anotherPlayer->xPosition -= 2;
          else
            anotherPlayer->xPosition += 2;
        }
        // If it did not got hit
        else
          al_play_sample(player->character->sounds.attack, 1.0, 0.0, 1.0,
                         ALLEGRO_PLAYMODE_ONCE, NULL);

      }
      // ----------------- JUMP KICK ------------------
      else {
        // Sets up the animation
        player->animationDone = false;
        player->character->currentSprite = JUMP_KICK;

        if (hitCheck(hurtBox_X1, hurtBox_X2, hurtBox_Y1, hurtBox_Y2,
                     player->character->fighterGraphics->movesSprites[JUMP_KICK]
                         .hitBoxWidth,
                     player->character->fighterGraphics->movesSprites[JUMP_KICK]
                         .hitBox_Y,
                     player->character->fighterGraphics->movesSprites[JUMP_KICK]
                         .hitBoxHeight,
                     player->facingRight, hurtBox2_X1, hurtBox2_X2, hurtBox2_Y1,
                     hurtBox2_Y2)) {
          // IF GOT HIT AND WAS NOT DEFENDING
          if (!anotherPlayer->blocking) {
            al_play_sample(anotherPlayer->character->sounds.gotHit, 1.0, 0.0,
                           1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            anotherPlayer->life -= 5;
            anotherPlayer->animationDone = false;
            if (!anotherPlayer->crouching)
              anotherPlayer->character->currentSprite = GOT_FACE_HIT;
            else
              anotherPlayer->character->currentSprite = GOT_CROUCH_HIT;
          }
          // IF GOT HIT AND WAS DEFENDING
          else {
            al_play_sample(player->character->sounds.blockHit, 1.0, 0.0, 1.0,
                           ALLEGRO_PLAYMODE_ONCE, NULL);
            anotherPlayer->animationDone = false;
            if (!anotherPlayer->crouching)
              anotherPlayer->character->currentSprite = DEFENDING;  // DEFENDING
            else
              anotherPlayer->character->currentSprite = CROUCH_BLOCK;
          }
          // knock back thing
          if (anotherPlayer->facingRight)
            anotherPlayer->xPosition -= 2;
          else
            anotherPlayer->xPosition += 2;
        }
        // If did not got hit
        else
          al_play_sample(player->character->sounds.attack, 1.0, 0.0, 1.0,
                         ALLEGRO_PLAYMODE_ONCE, NULL);
      }
    }
  }

  // Verify if someone died
  if (anotherPlayer->life <= 0) {
    anotherPlayer->animationDone = false;
    anotherPlayer->character->currentSprite = DEAD;
  }
}

/*
  Draw the player on the screen
*/
void drawPlayer(PLAYER *player, long timerIdle) {
  // Get the current sprite
  SPRITE_LIST currentSprite = player->character->currentSprite;
  // Get the current frame the sprite is at
  short currentSpriteFrame =
      player->character->fighterGraphics->movesSprites[currentSprite]
          .currentFrame;

  // DRAW THE PLAYERS
  int offset = 0;
  if (player->facingRight)
    al_draw_bitmap(
        player->character->fighterGraphics->movesSprites[currentSprite]
            .sprites[currentSpriteFrame],
        player->xPosition, player->yPosition, 0);
  else {
    if (currentSprite == PUNCHING || currentSprite == KICKING ||
        currentSprite == CROUCH_PUNCH)
      offset = -15;
    al_draw_bitmap(
        player->character->fighterGraphics->movesSprites[currentSprite]
            .sprites[currentSpriteFrame],
        player->xPosition + offset, player->yPosition, ALLEGRO_FLIP_HORIZONTAL);
  }

  // Resets to steady when an animation finishes off
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
void playerDestroyer(PLAYER *player) { free(player); }
