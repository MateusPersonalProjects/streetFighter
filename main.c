// gcc main.c -o teste display.c character.c keyboard.c misc.c player.c
// environment.c $(pkg-config allegro-5 allegro_primitives-5 allegro_image-5
// --libs --cflags)
#include <allegro5/alcompat.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <allegro5/display.h>
#include <allegro5/drawing.h>
#include <allegro5/events.h>
#include <allegro5/keyboard.h>
#include <allegro5/keycodes.h>
#include <allegro5/timer.h>

#include "character.h"
#include "display.h"
#include "environment.h"
#include "keyboard.h"
#include "misc.h"
#include "player.h"

// Defines where the players must start
#define PLAYER_1_INIT_POSIT_X (BUFFER_W * 0.15)
#define PLAYER_2_INIT_POSIT_X ((BUFFER_W - 25) * 0.75)

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
  unsigned char p1Keys[4] = {ALLEGRO_KEY_W, ALLEGRO_KEY_S, ALLEGRO_KEY_A,
                             ALLEGRO_KEY_D};
  player1 = initPlayer(bigBoxForTest, PLAYER_1_INIT_POSIT_X, FLOOR, true);
  PLAYER *player2;
  unsigned char p2Keys[4] = {ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN, ALLEGRO_KEY_LEFT,
                             ALLEGRO_KEY_RIGHT};
  player2 = initPlayer(bigBoxForTest, PLAYER_2_INIT_POSIT_X, FLOOR, false);

  // Register the events to our events queue
  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_display_event_source(disp));
  al_register_event_source(queue, al_get_timer_event_source(timer));

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
        playerUpdate(player1, player2, keyboardKeys, p1Keys);
        playerUpdate(player2, player1, keyboardKeys, p2Keys);

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

      drawPlayer(player1, al_map_rgb(176, 30, 100));
      drawPlayer(player2, al_map_rgb(0, 50, 200));

      dispPostDraw(disp, bufferBitmap);
      redraw = false;
    }
  }

  dispDestroyer(disp, bufferBitmap);
  playerDestroyer(player1);
  // playerDestroyer(player2);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);
  return 0;
}
