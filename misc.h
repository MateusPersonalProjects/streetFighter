#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef __MISC__
#define __MISC__

// Checks if an allegro module was initialized correctly
void alCheckInit(bool test, char* description);

/*
  Returns true if two box collided
*/
bool boxCollision(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2); 
#endif // !__MISC__
