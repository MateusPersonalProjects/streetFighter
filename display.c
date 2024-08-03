#include "display.h"

/*
  Initialize the display and the bitmap buffer that is going to be draw and
  scaleted to the game display
*/
void dispInit(ALLEGRO_DISPLAY **disp, ALLEGRO_BITMAP **buffer) {
  // Ant-aliasing
  al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);

  // Initialize display
  *disp = al_create_display(DISP_W, DISP_H);
  alCheckInit(*disp, "display");

  // Initialize buffer
  *buffer = al_create_bitmap(BUFFER_W, BUFFER_H);
  alCheckInit(*buffer, "bitmap buffer");
}

/*
  Destroy the game display and the bitmap buffer
*/
void dispDestroyer(ALLEGRO_DISPLAY *disp, ALLEGRO_BITMAP *buffer) {
  al_destroy_bitmap(buffer);
  al_destroy_display(disp);
}

/*
  Sets where the program must draw the things (must be used before draw
  everything)
*/
void dispPreDraw(ALLEGRO_BITMAP *buffer) { al_set_target_bitmap(buffer); }

/*
  Draw the things that were on the buffer display into the display but in
  another scale
*/
void dispPostDraw(ALLEGRO_DISPLAY *disp, ALLEGRO_BITMAP *buffer) {
  al_set_target_backbuffer(disp);
  al_draw_scaled_bitmap(buffer, 0, 0, BUFFER_W, BUFFER_H, 0, 0, DISP_W, DISP_H,
                        0);
  al_flip_display();
}
