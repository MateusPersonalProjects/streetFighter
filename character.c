#include "character.h"

#include <stdlib.h>

/*
  Initialize a new character
*/
CHARACTER* characterInit(int width, int height, int crouchHeight) {
  CHARACTER* newChar = (CHARACTER*)malloc(sizeof(CHARACTER));
  if (newChar == NULL) exit(1);

  newChar->width = width;
  newChar->height = height;
  newChar->crouchHeight = crouchHeight;
  return newChar;
}

/*
  Free the memory that a character was being utilized by a character
*/
void characterDestroyer(CHARACTER* character) { free(character); }
