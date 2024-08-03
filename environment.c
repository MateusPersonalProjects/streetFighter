#include "environment.h"

/* ---------------------- GUILE STAGE ----------------------- */

/*
  Initialize a guile stage
*/
GUILE_STAGE* initGuileStage() {
  GUILE_STAGE* guileStage = (GUILE_STAGE*)malloc(sizeof(GUILE_STAGE));

  guileStage->sheet = al_load_bitmap("./images/stages/GuileStage.png");
  alCheckInit(guileStage->sheet, "guile stage sheet");
  al_convert_mask_to_alpha(guileStage->sheet, al_map_rgb(255, 0, 255));

  guileStage->planeFloor =
      grabSprite(guileStage->sheet, GUILE_STAGE_PLANE_X, GUILE_STAGE_PLANE_Y,
                 GUILE_STAGE_PLANE_W, GUILE_STAGE_PLANE_H);
  guileStage->hangar =
      grabSprite(guileStage->sheet, GUILE_STAGE_PLANE_X, GUILE_STAGE_HANGAR_Y,
                 GUILE_STAGE_PLANE_W, GUILE_STAGE_PLANE_H);
  guileStage->sky =
      grabSprite(guileStage->sheet, GUILE_STAGE_SKY_X, GUILE_STAGE_SKY_Y,
                 GUILE_STAGE_SKY_W, GUILE_STAGE_SKY_H);
  guileStage->wall =
      grabSprite(guileStage->sheet, GUILE_STAGE_WALL_X, GUILE_STAGE_WALL_Y,
                 GUILE_STAGE_WALL_W, GUILE_STAGE_WALL_H);
  guileStage->animatedPersOne[0] = grabSprite(
      guileStage->sheet, GUILE_STAGE_ANIM_ONE_X_F1, GUILE_STAGE_ANIM_Y,
      GUILE_STAGE_ANIM_ONE_W, GUILE_STAGE_ANIM_ONE_H);
  guileStage->animatedPersOne[1] = grabSprite(
      guileStage->sheet, GUILE_STAGE_ANIM_ONE_X_F2, GUILE_STAGE_ANIM_Y,
      GUILE_STAGE_ANIM_ONE_W, GUILE_STAGE_ANIM_ONE_H);
  guileStage->animatedPersTwo[0] = grabSprite(
      guileStage->sheet, GUILE_STAGE_ANIM_TWO_X_F1, GUILE_STAGE_ANIM_Y,
      GUILE_STAGE_ANIM_TWO_W, GUILE_STAGE_ANIM_ONE_H);
  guileStage->animatedPersTwo[1] = grabSprite(
      guileStage->sheet, GUILE_STAGE_ANIM_TWO_X_F2, GUILE_STAGE_ANIM_Y,
      GUILE_STAGE_ANIM_TWO_W, GUILE_STAGE_ANIM_ONE_H);
  guileStage->animatedPersThree[0] = grabSprite(
      guileStage->sheet, GUILE_STAGE_ANIM_THREE_X_F1, GUILE_STAGE_ANIM_Y,
      GUILE_STAGE_ANIM_THREE_W, GUILE_STAGE_ANIM_ONE_H);
  guileStage->animatedPersThree[1] = grabSprite(
      guileStage->sheet, GUILE_STAGE_ANIM_THREE_X_F2, GUILE_STAGE_ANIM_Y,
      GUILE_STAGE_ANIM_THREE_W, GUILE_STAGE_ANIM_ONE_H);

  guileStage->persOneFrames = guileStage->persTwoFrames =
      guileStage->persThreeFrames = 0;
  return guileStage;
}

/*
  Draw guile stage on the screen
*/
void drawGuileStage(GUILE_STAGE* stage, long int timer) {
  float floorNextToPlane = BUFFER_H - 138;
  // Increase frames
  if (!(timer % 10)) stage->persOneFrames++;
  if (!(timer % 15)) stage->persTwoFrames++;
  if (!(timer % 20)) stage->persThreeFrames++;
  // Mods for animation
  stage->persOneFrames %= 2;
  stage->persTwoFrames %= 2;
  stage->persThreeFrames %= 2;

  al_draw_bitmap(stage->sky, 0, 0, 0);
  al_draw_bitmap(stage->hangar, -30, BUFFER_H - 120, 0);
  al_draw_bitmap(stage->planeFloor, -20, BUFFER_H - GUILE_STAGE_PLANE_H, 0);

  al_draw_bitmap(stage->animatedPersOne[stage->persOneFrames], 98,
                 floorNextToPlane, 0);
  al_draw_bitmap(stage->animatedPersTwo[stage->persTwoFrames], 175,
                 floorNextToPlane, 0);
  al_draw_bitmap(stage->animatedPersThree[stage->persThreeFrames], 279,
                 floorNextToPlane, 0);
  al_draw_bitmap(stage->wall, 0, floorNextToPlane, 0);
}

/* ------------------ VEGAS STAGE ---------------- */

const short carsAndDudes_x[2] = {112, 112};
const short carsAndDudes_y[2] = {848, 936};
const short carsAndDudes_w[2] = {296, 296};
const short carsAndDudes_h[2] = {80, 80};

const short redWoman_x[4] = {152, 200, 248, 368};
const short redWoman_y[4] = {760, 760, 760, 760};
const short redWoman_w[4] = {40, 40, 40, 64};
const short redWoman_h[4] = {80, 80, 80, 80};

const short blueWoman_x[4] = {8, 56, 104, 296};
const short blueWoman_y[4] = {760, 760, 760, 760};
const short blueWoman_w[4] = {40, 40, 40, 64};
const short blueWoman_h[4] = {80, 80, 80, 80};

/*
  Initialize the vegas stage
*/
VEGAS_STAGE* initVegasStage() {
  VEGAS_STAGE* vegasStage = (VEGAS_STAGE*)malloc(sizeof(VEGAS_STAGE));
  if (vegasStage == NULL) exit(1);

  vegasStage->sheet = al_load_bitmap("./images/stages/vegasStage.png");
  alCheckInit(vegasStage->sheet, "Vegas Stage Sheet");
  al_convert_mask_to_alpha(vegasStage->sheet, al_map_rgb(255, 0, 255));

  vegasStage->mainFloor = grabSprite(vegasStage->sheet, MAIN_FLOOR_X,
                                     MAIN_FLOOR_Y, MAIN_FLOOR_W, MAIN_FLOOR_H);
  vegasStage->littleBals =
      grabSprite(vegasStage->sheet, LITTLE_BALLS_X, LITTLE_BALLS_Y,
                 LITTLE_BALLS_W, LITTLE_BALLS_H);

  vegasStage->backSparkles =
      grabSprite(vegasStage->sheet, BACK_SPARKLES_X, BACK_SPARKLES_Y,
                 BACK_SPARKLES_W, BACK_SPARKLES_H);

  vegasStage->carsAndDudesFrames = 0;
  for (int i = 0; i < 2; i++)
    vegasStage->carsAndDudes[i] =
        grabSprite(vegasStage->sheet, carsAndDudes_x[i], carsAndDudes_y[i],
                   carsAndDudes_w[i], carsAndDudes_h[i]);

  vegasStage->redWomanFrames = 0;
  vegasStage->redWomanPosition = 245;
  vegasStage->redGoing = true;

  vegasStage->blueWomanFrames = 0;
  vegasStage->blueWomanPosition = 55;
  vegasStage->blueGoing = true;

  for (int i = 0; i < 4; i++) {
    vegasStage->redWoman[i] =
        grabSprite(vegasStage->sheet, redWoman_x[i], redWoman_y[i],
                   redWoman_w[i], redWoman_h[i]);
    vegasStage->blueWoman[i] =
        grabSprite(vegasStage->sheet, blueWoman_x[i], blueWoman_y[i],
                   blueWoman_w[i], blueWoman_h[i]);
  }

  return vegasStage;
}

/*
  Draw the vegas stage
*/
void drawVegasStage(VEGAS_STAGE* vegasStage, long int timer) {
  // Increase frames
  if (!(timer % 10)) vegasStage->carsAndDudesFrames++;
  if (!(timer % 10)) vegasStage->redWomanFrames++;
  if (!(timer % 10)) vegasStage->blueWomanFrames++;
  // Mods for animation
  vegasStage->carsAndDudesFrames %= 2;
  vegasStage->redWomanFrames %= 3;
  vegasStage->blueWomanFrames %= 3;

  al_draw_bitmap(vegasStage->littleBals, 35, 255, 0);
  al_draw_bitmap(vegasStage->mainFloor, -55, -26, 0);
  al_draw_bitmap(vegasStage->backSparkles, 57, 15, 0);
  al_draw_bitmap(vegasStage->carsAndDudes[vegasStage->carsAndDudesFrames], 55,
                 175, 0);

  int redIni = 245;
  int redEnd = 305;
  int blueIni = 55;
  int blueEnd = 130;

  // Animation for the red woman
  if (vegasStage->redGoing) {
    al_draw_bitmap(vegasStage->redWoman[vegasStage->redWomanFrames],
                   vegasStage->redWomanPosition, 180, 0);
    vegasStage->redWomanPosition += 1;
    if (vegasStage->redWomanPosition >= redEnd) vegasStage->redGoing = false;
  } else {
    al_draw_bitmap(vegasStage->redWoman[vegasStage->redWomanFrames],
                   vegasStage->redWomanPosition, 180, ALLEGRO_FLIP_HORIZONTAL);
    vegasStage->redWomanPosition -= 1;
    if (vegasStage->redWomanPosition <= redIni) vegasStage->redGoing = true;
  }

  // Animation for the blue woman
  if (vegasStage->blueGoing) {
    al_draw_bitmap(vegasStage->blueWoman[vegasStage->blueWomanFrames],
                   vegasStage->blueWomanPosition, 180, ALLEGRO_FLIP_HORIZONTAL);
    vegasStage->blueWomanPosition += 1;
    if (vegasStage->blueWomanPosition >= blueEnd) vegasStage->blueGoing = false;
  } else {
    al_draw_bitmap(vegasStage->blueWoman[vegasStage->blueWomanFrames],
                   vegasStage->blueWomanPosition, 180, 0);
    vegasStage->blueWomanPosition -= 1;
    if (vegasStage->blueWomanPosition <= blueIni) vegasStage->blueGoing = true;
  }
}

/*
  Draw a stage on the screen
*/
void drawStage(GUILE_STAGE* guileStage, VEGAS_STAGE* vegasStage, long int timer,
               short choice) {
  if (choice == 0)
    drawGuileStage(guileStage, timer);
  else
    drawVegasStage(vegasStage, timer);
}

/*
  Destroy a stage
*/
void destroyStage(GUILE_STAGE* stage, VEGAS_STAGE* vegasStage) {
  al_destroy_bitmap(stage->planeFloor);
  al_destroy_bitmap(stage->hangar);
  al_destroy_bitmap(stage->wall);
  al_destroy_bitmap(stage->sheet);
  for (int i = 0; i < 2; i++) {
    al_destroy_bitmap(stage->animatedPersOne[i]);
    al_destroy_bitmap(stage->animatedPersTwo[i]);
    al_destroy_bitmap(stage->animatedPersThree[i]);
  }
  free(stage);

  al_destroy_bitmap(vegasStage->mainFloor);
  al_destroy_bitmap(vegasStage->littleBals);
  al_destroy_bitmap(vegasStage->sheet);
  for (int i = 0; i < 2; i++) {
    al_destroy_bitmap(vegasStage->carsAndDudes[i]);
  }
}
