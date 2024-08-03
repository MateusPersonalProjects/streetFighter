#include "attacks_SpecialMoves.h"

/*
  Checks if someone got hit. P1 is who gave gave the hit and P2 is who is
  supossed to get hitted
*/
bool hitCheck(int p1x1, int p1x2, int p1y1, int hitBoxWidth, int hitBox_Y,
              int hitBoxHeight, bool facingRight, int p2x1, int p2x2, int p2y1,
              int p2y2) {
  bool hit = false;

  // The next variables are relationed with the hitbox position
  int hitBoxStartX_FR = p1x2;
  int hitBoxStartX_FL = p1x1 - hitBoxWidth;
  int hitBoxEndX_FR = p1x2 + hitBoxWidth;
  int hitBoxEndX_FL = p1x1;

  int hitBoxStartY = p1y1 + hitBox_Y;
  int hitBoxEndY = hitBoxStartY + hitBoxHeight;

  // Facing right tells us where the punch hitbox should appers
  if (facingRight) {
    hit = boxCollision(hitBoxStartX_FR, hitBoxStartY, hitBoxEndX_FR, hitBoxEndY,
                       p2x1, p2y1, p2x2, p2y2);
  } else {
    hit = boxCollision(hitBoxStartX_FL, hitBoxStartY, hitBoxEndX_FL, hitBoxEndY,
                       p2x1, p2y1, p2x2, p2y2);
  }
  return hit;
}
