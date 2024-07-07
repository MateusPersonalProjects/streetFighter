#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/bitmap.h>
#include "misc.h"
#include "display.h"

#ifndef __GAME_ENVIRONMENT__
#define __GAME_ENVIRONMENT__

#define FLOOR 285
#define GRAVITY_COEF 1

#define GUILE_STAGE_PLANE_W 512
#define GUILE_STAGE_PLANE_H 224
#define GUILE_STAGE_PLANE_X 0
#define GUILE_STAGE_PLANE_Y 0

#define GUILE_STAGE_HANGAR_Y 686

#define GUILE_STAGE_SKY_W 416
#define GUILE_STAGE_SKY_H 64
#define GUILE_STAGE_SKY_X 5
#define GUILE_STAGE_SKY_Y 271

#define GUILE_STAGE_WALL_W 94
#define GUILE_STAGE_WALL_H 100
#define GUILE_STAGE_WALL_X 0
#define GUILE_STAGE_WALL_Y 472

#define GUILE_STAGE_ANIM_ONE_W 47
#define GUILE_STAGE_ANIM_ONE_H 97
#define GUILE_STAGE_ANIM_ONE_X_F1 18
#define GUILE_STAGE_ANIM_ONE_X_F2 84
#define GUILE_STAGE_ANIM_Y 366

#define GUILE_STAGE_ANIM_TWO_W 97
#define GUILE_STAGE_ANIM_TWO_X_F1 140
#define GUILE_STAGE_ANIM_TWO_X_F2 243

#define GUILE_STAGE_ANIM_THREE_W 80
#define GUILE_STAGE_ANIM_THREE_X_F1 347
#define GUILE_STAGE_ANIM_THREE_X_F2 432
typedef struct {
  ALLEGRO_BITMAP* sheet;

  ALLEGRO_BITMAP* planeFloor;
  ALLEGRO_BITMAP* hangar;
  ALLEGRO_BITMAP* sky;
  ALLEGRO_BITMAP* wall;
  ALLEGRO_BITMAP* animatedPersOne[2];
  short persOneFrames;
  ALLEGRO_BITMAP* animatedPersTwo[2];
  short persTwoFrames;
  ALLEGRO_BITMAP* animatedPersThree[2];
  short persThreeFrames;

} GUILE_STAGE ;

/*
  Initialize a stage
*/
GUILE_STAGE* initGuileStage();

/*
  Draw the stage on the screen
*/
void drawStage(GUILE_STAGE* stage, long int timer);

/*
  Destroy a stage
*/
void destroyStage(GUILE_STAGE* stage);
#endif // !__GAME_ENVIRONMENT__
