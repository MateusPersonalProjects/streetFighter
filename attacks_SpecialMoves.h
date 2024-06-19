#include <stdbool.h>
#include <stdio.h>
#include "misc.h"

#ifndef __ATTACKS_SPECIALMOVES__
#define __ATTACKS_SPECIALMOVES__

/*
  Checks if someone got hit by a punch
  P1 is who gave gave the hit and P2 is who is supossed to get hitted by the
  punch
*/
bool punch(int p1x1, int p1x2, int p1y1, int p1y2, bool facingRight, int p2x1,
           int p2x2, int p2y1, int p2y2);
 

#endif // !__ATTACKS_SPECIALMOVES__
