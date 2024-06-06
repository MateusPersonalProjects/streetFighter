#include <allegro5/alcompat.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <allegro5/display.h>
#include <allegro5/drawing.h>
#include <allegro5/events.h>
#include <allegro5/keyboard.h>
#include <allegro5/keycodes.h>
#include <allegro5/timer.h>
#include <time.h>

#include "character.h"
#include "display.h"
#include "keyboard.h"
#include "misc.h"
#include "player.h"

int main(void) {
  // Initialize allegro and keyboard
  alCheckInit(al_init(), "allegro");
  alCheckInit(al_install_keyboard(), "keyboard");

  unsigned char keyboardKeys[ALLEGRO_KEY_MAX];
  keyboardInit(keyboardKeys, sizeof(keyboardKeys));

  // Initialize the display and the display bitmap buffer
  ALLEGRO_DISPLAY *disp;
  ALLEGRO_BITMAP *bufferBitmap;
  dispInit(&disp, &bufferBitmap);

  // Create event queue
  ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30.0);
  alCheckInit(timer, "timer");

  // Create event queue
  ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
  alCheckInit(queue, "queue");

  // Initialize primites for tests
  alCheckInit(al_init_primitives_addon(), "primitives");

  // Test things
  CHARACTER *bigBoxForTest;
  bigBoxForTest = characterInit(25, 50);

  PLAYER *player1;
  player1 = initPlayer(bigBoxForTest, 50, 250, true);

  // -------------- MAIN GAME THINGS --------------
  bool done = false;
  bool redraw = true;

  ALLEGRO_EVENT event;

  al_start_timer(timer);

  while (1) {
    al_wait_for_event(queue, &event);

    // -------------- UPDATE PHASE --------------

    switch (event.type) {
      case ALLEGRO_EVENT_TIMER:
        player1Update(player1, keyboardKeys);

        if (keyboardKeys[ALLEGRO_KEY_ESCAPE]) done = true;
        redraw = true;
        break;

      case ALLEGRO_EVENT_DISPLAY_CLOSE:
        done = true;
        break;
    }

    // If the user wants to close the game break the loop
    if (done) break;

    keyboardUpdate(&event, keyboardKeys);

    // ------------ REDRAW PHASE ------------
    if (redraw && al_event_queue_is_empty(queue)) {
      dispPreDraw(bufferBitmap);
      al_clear_to_color(al_map_rgb(0, 0, 0));

      drawPlayer(player1);

      dispPostDraw(disp, bufferBitmap);
      redraw = false;
    }
  }

  dispDestroyer(disp, bufferBitmap);

  return 0;
}
