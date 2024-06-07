#include "player.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <allegro5/keycodes.h>
#include <stdlib.h>

#include "character.h"

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

  return newPlayer;
}

/*
  Update things for player 1
*/
void player1Update(PLAYER *player, unsigned char *keyboardKeys) {
  if (keyboardKeys[ALLEGRO_KEY_D]) player->xPosition += 10;
  if (keyboardKeys[ALLEGRO_KEY_A]) player->xPosition -= 10;
}

/*
  Draw the player on the screen
*/
void drawPlayer(PLAYER *player, ALLEGRO_COLOR playerColor) {
  al_draw_filled_rectangle(player->xPosition,
                           (player->yPosition - player->character->height),
                           (player->character->width + player->xPosition),
                           player->yPosition, playerColor);
}

/*
  Free up the space that were being utilized by a Player instance
*/
void playerDestroyer(PLAYER *player) {
  characterDestroyer(player->character);
  free(player);
}
