// gcc main.c -o teste display.c character.c keyboard.c misc.c player.c
// environment.c matchInterface.c attacks_SpecialMoves.c $(pkg-config allegro-5
// allegro_primitives-5 allegro_font-5 allegro_image-5 --libs --cflags)
#include <allegro5/alcompat.h>
#include <allegro5/allegro_font.h>
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
#include "matchInterface.h"
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

  // Init Font
  ALLEGRO_FONT *font = al_create_builtin_font();
  alCheckInit(font, "font");

  // Initialize primites for tests
  alCheckInit(al_init_primitives_addon(), "primitives");

  // Test things
  CHARACTER *bigBoxForTest1, *bigBoxForTest2;
  bigBoxForTest1 = characterInit(25, 50, 50 * 0.3);
  bigBoxForTest2 = characterInit(25, 50, 50 * 0.3);

  PLAYER *player1;
  unsigned char p1Keys[5] = {ALLEGRO_KEY_W, ALLEGRO_KEY_S, ALLEGRO_KEY_A,
                             ALLEGRO_KEY_D, ALLEGRO_KEY_G};
  player1 = initPlayer(bigBoxForTest1, PLAYER_1_INIT_POSIT_X,
                       FLOOR - bigBoxForTest1->height, true);
  PLAYER *player2;
  unsigned char p2Keys[5] = {ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN, ALLEGRO_KEY_LEFT,
                             ALLEGRO_KEY_RIGHT, ALLEGRO_KEY_U};
  player2 = initPlayer(bigBoxForTest2, PLAYER_2_INIT_POSIT_X,
                       FLOOR - bigBoxForTest2->height, false);

  MATCH_INTERFACE *matchInterface;
  matchInterface = initMatchInterface(player1, player2);

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

    bool chacSelecLoop = true;
    // ------------- CHARACTER SELECTION MENU -----------------
    while (chacSelecLoop) {
      /*
        4 personagens, 4 quadrados só a borda

        Vai funcionar da forma que
          se -> ++
          se <- --
          se DOWN +2
          se UP -2

      */
    }
    bool matchLoop = true;
    bool controlON = false;
    bool reset = false;
    matchInterface->rounds = 0;

    matchInterface->matchUP = true;
    matchInterface->roundUP = true;

    unsigned short frames = 0;

    // ---------------- MATCH LOGIC ---------------
    while (matchLoop) {
      // -------------- UPDATE PHASE --------------

      switch (event.type) {
        case ALLEGRO_EVENT_TIMER:

          // If the control is on the player can move around and start the fight
          if (controlON) {
            playerUpdateMovements(player1, player2, keyboardKeys, p1Keys);
            playerUpdateMovements(player2, player1, keyboardKeys, p2Keys);

            playerUpdateAttacks(player1, player2, keyboardKeys, p1Keys);
            playerUpdateAttacks(player2, player1, keyboardKeys, p2Keys);
            matchInterfaceUpdate(matchInterface, player1, player2);
            controlON = matchUpdate(matchInterface, player1, player2);
          }

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
        drawMatchInterface(matchInterface, player1, player2);

        // If the players are not able to control and the round is up, well it
        // just started so lets draw the things
        if (!controlON && matchInterface->roundUP)
          controlON = roundStartWriter(matchInterface, &frames, font);

        // If the round is not up, well someone died, so lets check this and
        // start a new round
        if (!matchInterface->roundUP) {
          if (roundEndWriter(matchInterface, &frames, font)) {
            resetPlayer(player1, PLAYER_1_INIT_POSIT_X,
                        FLOOR - bigBoxForTest1->height, true);
            resetPlayer(player2, PLAYER_2_INIT_POSIT_X,
                        FLOOR - bigBoxForTest2->height, false);
          }
        }

        // If the match ended, we have a winner so lets show him
        if (!matchInterface->matchUP)
          matchLoop = drawWinnerGreater(matchInterface, &frames, font,
                                        (player1->roundsWon == 2));

        dispPostDraw(disp, bufferBitmap);
        redraw = false;
      }

      al_wait_for_event(queue, &event);
    }

    dispDestroyer(disp, bufferBitmap);
    playerDestroyer(player1);
    playerDestroyer(player2);
    matchInterfaceDestroyer(matchInterface);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
  }
}
