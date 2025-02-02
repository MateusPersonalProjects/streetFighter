
#ifndef __GAME_ENVIRONMENT__
#define __GAME_ENVIRONMENT__
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/bitmap_io.h>
#include <allegro5/color.h>
#include <allegro5/timer.h>
#include <time.h>

#include "misc.h"
#include "display.h"

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

/* VEGAS STAGE */

#define MAIN_FLOOR_X 0
#define MAIN_FLOOR_Y 127
#define MAIN_FLOOR_W 512
#define MAIN_FLOOR_H 330

#define LITTLE_BALLS_X 96
#define LITTLE_BALLS_Y 672
#define LITTLE_BALLS_W 328
#define LITTLE_BALLS_H 8

#define BACK_SPARKLES_X 96
#define BACK_SPARKLES_Y 496
#define BACK_SPARKLES_W 289
#define BACK_SPARKLES_H 80

extern const short carsAndDudes_x[2];
extern const short carsAndDudes_y[2];
extern const short carsAndDudes_w[2];
extern const short carsAndDudes_h[2];

extern const short redWoman_x[4];
extern const short redWoman_y[4];
extern const short redWoman_w[4];
extern const short redWoman_h[4];

extern const short blueWoman_x[4];
extern const short blueWoman_y[4];
extern const short blueWoman_w[4];
extern const short blueWoman_h[4];

typedef struct{
  ALLEGRO_BITMAP* sheet;

  ALLEGRO_BITMAP* mainFloor;
  ALLEGRO_BITMAP* littleBals;
  ALLEGRO_BITMAP* backSparkles;
  
  ALLEGRO_BITMAP* carsAndDudes[2];
  short carsAndDudesFrames;
  
  ALLEGRO_BITMAP* redWoman[4];
  short redWomanFrames;
  int redWomanPosition;
  bool redGoing;
  
  ALLEGRO_BITMAP* blueWoman[4];
  short blueWomanFrames;
  int blueWomanPosition;
  bool blueGoing;
} VEGAS_STAGE;

/*
  Initialize guile stage
*/
GUILE_STAGE* initGuileStage();

/*
  Initialize vegas stage
*/
VEGAS_STAGE* initVegasStage();

/*
  Draw the stage on the screen
*/
void drawStage(GUILE_STAGE* guileStage, VEGAS_STAGE* vegasStage, long int timer, short choice);

/*
  Destroy a stage
*/
void destroyStage(GUILE_STAGE* stage, VEGAS_STAGE* vegasStage);
#endif // !__GAME_ENVIRONMENT__
