#ifndef __ATTACKS_SPECIALMOVES__
#define __ATTACKS_SPECIALMOVES__
#include <stdbool.h>
#include <stdio.h>
#include "misc.h"


/*
  Checks if someone got hit. P1 is who gave gave the hit and P2 is who is supossed to get hitted
*/
bool hitCheck(int p1x1, int p1x2, int p1y1, int p1y2, int hitBoxWidth,
              int hitBox_Y, int hitBoxHeight, bool facingRight, int p2x1,
              int p2x2, int p2y1, int p2y2); 


#endif // !__ATTACKS_SPECIALMOVES__
