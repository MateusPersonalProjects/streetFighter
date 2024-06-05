#include "misc.h"

// Checks if an allegro module was initialized correctly
void alCheckInit(bool test, char* description) {
  if (test) return;

  printf("Couldn't initialize %s\n", description);
  exit(1);
}
