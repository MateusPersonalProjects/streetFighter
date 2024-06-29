#include "characSelecMenu.h"

#include <allegro5/allegro_font.h>
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
  Reset all the boxes to the white color
*/
void resetSelectionBoxes(SELECTION_BOX* allSelectionBoxes) {
  ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

  for (int i = 0; i < 4; i++) {
    allSelectionBoxes[i].selected = false;
  }
}

/*
  Reset all the boxes to the white color
*/
void resetSelectionBoxesColor(SELECTION_BOX* allSelectionBoxes) {
  ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

  for (int i = 0; i < 4; i++) {
    if (!allSelectionBoxes[i].selected) allSelectionBoxes[i].color = color;
  }
}

/*
  Update the selection boxes
*/
bool updateSelectionBoxes(SELECTION_BOX* allSelectionBoxes, short* idSelcP,
                          unsigned char* keyboardKeys,
                          unsigned char* playerKeys, ALLEGRO_COLOR color) {
  bool playerSelected = false;
  if (keyboardKeys[playerKeys[0]]) {
    (*idSelcP) -= 2;
    if ((*idSelcP) < 0) (*idSelcP) += 2;
  }

  if (keyboardKeys[playerKeys[1]]) {
    (*idSelcP) += 2;
    if ((*idSelcP) > 3) (*idSelcP) -= 2;
  }

  if (keyboardKeys[playerKeys[2]]) {
    (*idSelcP) -= 1;
    if ((*idSelcP) < 0) (*idSelcP) += 1;
  }

  if (keyboardKeys[playerKeys[3]]) {
    (*idSelcP) += 1;
    if ((*idSelcP) > 3) (*idSelcP) -= 1;
  }

  /*
    if the box was not selected yet select it and turn it green
  */
  if (keyboardKeys[playerKeys[4]]) {
    if (!allSelectionBoxes[(*idSelcP)].selected) {
      playerSelected = true;
      allSelectionBoxes[(*idSelcP)].color = al_map_rgb(0, 255, 0);
      allSelectionBoxes[(*idSelcP)].selected = true;
    }
  }

  /*
    if the box was not selected turn it into the color of the player
  */
  if (!allSelectionBoxes[(*idSelcP)].selected)
    allSelectionBoxes[(*idSelcP)].color = color;

  return playerSelected;
}
/*
  Draw all the four selection boxes
*/
void drawSelectionBoxes(SELECTION_BOX* allSelectionBoxes,
                        ALLEGRO_COLOR* boxOfColors) {
  float x1, y1, x2, y2;
  for (int i = 0; i < 4; i++) {
    x1 = allSelectionBoxes[i].xPosit - (SELECT_BOX_WIDTH / 2.0);
    y1 = allSelectionBoxes[i].yPosit - (SELECT_BOX_HEIGHT / 2.0);
    x2 = allSelectionBoxes[i].xPosit + (SELECT_BOX_WIDTH / 2.0);
    y2 = allSelectionBoxes[i].yPosit + (SELECT_BOX_HEIGHT / 2.0);

    // Draw the crazy dude

    al_draw_filled_rectangle(x1 + 15, y1 + 35, x2 - 15,
                             y2 - SELECT_BOX_THICKNESS, boxOfColors[i]);
    al_draw_filled_rectangle(x2 - 55, y1 + 55, x2 - 10, y1 + 75,
                             al_map_rgb(255, 255, 255));

    al_draw_rectangle(x1, y1, x2, y2, allSelectionBoxes[i].color,
                      SELECT_BOX_THICKNESS);
  }
}

/*
  Draw the versus screen
*/
void drawVersusScreen(ALLEGRO_COLOR p1, ALLEGRO_COLOR p2, ALLEGRO_FONT* font) {
  al_draw_filled_rectangle(20, 100, (BUFFER_W / 2.0) - 50, BUFFER_H - 5, p1);
  al_draw_filled_rectangle((BUFFER_W / 2.0) - 130, 140, (BUFFER_W / 2.0) - 40,
                           180, al_map_rgb(255, 255, 255));
  al_draw_filled_rectangle((BUFFER_W - 20), 100, (BUFFER_W / 2.0) + 50,
                           BUFFER_H - 5, p2);
  al_draw_filled_rectangle((BUFFER_W / 2.0) + 130, 140, (BUFFER_W / 2.0) + 40,
                           180, al_map_rgb(255, 255, 255));
  al_draw_text(font, al_map_rgb_f(1, 1, 1), BUFFER_W / 2.0, BUFFER_H / 2.0,
               ALLEGRO_ALIGN_CENTER, "V . S");
}
