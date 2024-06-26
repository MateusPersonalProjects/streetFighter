#include "characSelecMenu.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>

/*
  Initialize all the four selection boxes
*/
void initSelectionBoxes(SELECTION_BOX* allSelectionBoxes) {
  int midScreenY = BUFFER_H / 2;
  int midScreenX = BUFFER_W / 2;
  ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

  allSelectionBoxes[0].xPosit = midScreenX - (SELECT_BOX_WIDTH / 2) - 10;
  allSelectionBoxes[0].yPosit = midScreenY - (SELECT_BOX_HEIGHT / 2) - 10;

  allSelectionBoxes[1].xPosit = midScreenX + (SELECT_BOX_WIDTH / 2) + 10;
  allSelectionBoxes[1].yPosit = midScreenY - (SELECT_BOX_HEIGHT / 2) - 10;

  allSelectionBoxes[2].xPosit = midScreenX - (SELECT_BOX_WIDTH / 2) - 10;
  allSelectionBoxes[2].yPosit = midScreenY + (SELECT_BOX_HEIGHT / 2) + 10;

  allSelectionBoxes[3].xPosit = midScreenX + (SELECT_BOX_WIDTH / 2) + 10;
  allSelectionBoxes[3].yPosit = midScreenY + (SELECT_BOX_HEIGHT / 2) + 10;

  for (int i = 0; i < 4; i++) {
    allSelectionBoxes[i].color = color;
    allSelectionBoxes[i].selected = false;
  }
}

/*
  Draw all the four selection boxes
*/
void drawSelectionBoxes(SELECTION_BOX* allSelectionBoxes) {
  float x1, y1, x2, y2;
  for (int i = 0; i < 4; i++) {
    x1 = allSelectionBoxes[i].xPosit - (SELECT_BOX_WIDTH / 2.0);
    y1 = allSelectionBoxes[i].yPosit - (SELECT_BOX_HEIGHT / 2.0);
    x2 = allSelectionBoxes[i].xPosit + (SELECT_BOX_WIDTH / 2.0);
    y2 = allSelectionBoxes[i].yPosit + (SELECT_BOX_HEIGHT / 2.0);

    al_draw_rectangle(x1, y1, x2, y2, allSelectionBoxes[i].color,
                      SELECT_BOX_THICKNESS);
  }
}
