#include "environment.h"

#include <allegro5/bitmap.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/bitmap_io.h>
#include <allegro5/color.h>
#include <allegro5/timer.h>

/*
  Initialize a stage
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
  Draw the stage on the screen
*/
void drawStage(GUILE_STAGE* stage, long int timer) {
  float floorNextToPlane = BUFFER_H - 138;
  if (!(timer % 10)) stage->persOneFrames++;
  if (!(timer % 15)) stage->persTwoFrames++;
  if (!(timer % 20)) stage->persThreeFrames++;
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

/*
  Destroy a stage
*/
void destroyStage(GUILE_STAGE* stage) {
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
}
