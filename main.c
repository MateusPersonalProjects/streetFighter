#include <allegro5/alcompat.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/color.h>
#include <allegro5/display.h>
#include <allegro5/drawing.h>
#include <allegro5/events.h>
#include <allegro5/keyboard.h>
#include <allegro5/keycodes.h>
#include <allegro5/timer.h>
#include <time.h>

#include "./fightersDefines/chunli.h"
#include "./fightersDefines/guile.h"
#include "./fightersDefines/ken.h"
#include "./fightersDefines/ryu.h"
#include "characSelecMenu.h"
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

  // Initialize audio
  alCheckInit(al_install_audio(), "audio");
  alCheckInit(al_init_acodec_addon(), "audio codecs");
  alCheckInit(al_reserve_samples(16), "reserve samples");

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

  // Initialize the image addon
  alCheckInit(al_init_image_addon(), "images");

  // Initialize all characters sprites
  FIGHTER_SPRITES *ryuSprites = initRyu();
  FIGHTER_SPRITES *kenSprites = initKen();
  FIGHTER_SPRITES *chunliSprites = initChunli();
  FIGHTER_SPRITES *guileSprites = initGuile();

  // Initialize all 4 characters
  CHARACTER *allCharacters[4];
  allCharacters[0] = characterInit(ryuSprites);
  allCharacters[1] = characterInit(kenSprites);
  allCharacters[2] = characterInit(chunliSprites);
  allCharacters[3] = characterInit(guileSprites);

  ALLEGRO_COLOR boxColors[4] = {al_map_rgb(255, 0, 0), al_map_rgb(0, 255, 0),
                                al_map_rgb(0, 0, 255),
                                al_map_rgb(255, 200, 50)};

  // Initialize character selection sprites and boxes
  CHARAC_SELECT_SPRITES *characSelectSprites;
  characSelectSprites = initCharacSelectSprites();

  SELECTION_BOX characSelectBoxes[4];
  initSelectionBoxes(characSelectBoxes, characSelectSprites);

  // Initialize players and set theirs keys
  PLAYER *player1;
  unsigned char p1Keys[6] = {ALLEGRO_KEY_W, ALLEGRO_KEY_S, ALLEGRO_KEY_A,
                             ALLEGRO_KEY_D, ALLEGRO_KEY_G, ALLEGRO_KEY_H};
  player1 = initPlayer(NULL, PLAYER_1_INIT_POSIT_X, 0, true);
  PLAYER *player2;
  unsigned char p2Keys[6] = {ALLEGRO_KEY_UP,   ALLEGRO_KEY_DOWN,
                             ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT,
                             ALLEGRO_KEY_U,    ALLEGRO_KEY_I};
  player2 = initPlayer(NULL, PLAYER_2_INIT_POSIT_X, 0, false);

  // Initialize stages
  short stageChoice = 0;

  GUILE_STAGE *guileStage;
  guileStage = initGuileStage();

  VEGAS_STAGE *vegasStage;
  vegasStage = initVegasStage();

  // Initialize the match interface
  MATCH_INTERFACE *matchInterface;
  matchInterface = initMatchInterface(player1, player2);

  ALLEGRO_SAMPLE *startSound = al_load_sample("./sounds/20H.wav");
  alCheckInit(startSound, "start sound");
  ALLEGRO_SAMPLE *selectFighterSound = al_load_sample("./sounds/22H.wav");
  alCheckInit(selectFighterSound, "select fighter sound");
  ALLEGRO_SAMPLE *versusSound = al_load_sample("./sounds/9BH.wav");
  alCheckInit(versusSound, "versus sound");

  // Register the events to our events queue
  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_display_event_source(disp));
  al_register_event_source(queue, al_get_timer_event_source(timer));

  // -------------- MAIN GAME THINGS --------------
  bool done = false;
  bool redraw = true;

  ALLEGRO_EVENT event;

  al_start_timer(timer);
  unsigned short frames = 0;
  bool mainMenuLoop = true;
  bool startCount = false;
  while (1) {
    // Main menu

    short twinkle = 0;
    while (mainMenuLoop) {
      switch (event.type) {
        case ALLEGRO_EVENT_TIMER:
          if (startCount) frames++;
          redraw = true;
          break;

        case ALLEGRO_EVENT_KEY_DOWN:
          if (event.keyboard.keycode == ALLEGRO_KEY_G) {
            startCount = true;
            al_play_sample(startSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE,
                           NULL);
          }
          break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
          done = true;
          break;
      }

      if (frames >= 24) mainMenuLoop = false;

      // If the user wants to close the game break the loop
      if (done) break;

      // keyboardUpdate(&event, keyboardKeys);

      // ------------ REDRAW PHASE ------------
      if (redraw && al_event_queue_is_empty(queue)) {
        dispPreDraw(bufferBitmap);
        al_clear_to_color(al_map_rgb(0, 0, 0));

        drawMainMenu(characSelectSprites->logo, font, al_get_timer_count(timer),
                     &twinkle);
        dispPostDraw(disp, bufferBitmap);
        redraw = false;
      }

      al_wait_for_event(queue, &event);
    }
    if (done) break;
    resetSelectionBoxes(characSelectBoxes);
    // CHARACTER SELECTION MENU VARIABLES
    short selectP1 = 0;
    short selectP2 = 1;
    player1->roundsWon = 0;
    player2->roundsWon = 0;
    bool p1Selected = false;
    bool p2Selected = false;
    bool chacSelecLoop = true;
    startCount = false;
    frames = 0;
    // ------------- CHARACTER SELECTION MENU -----------------
    while (chacSelecLoop) {
      switch (event.type) {
        case ALLEGRO_EVENT_TIMER:
          resetSelectionBoxesColor(characSelectBoxes);

          updateSelectionBoxesColor(characSelectBoxes, &selectP1,
                                    al_map_rgb(0, 0, 255));
          updateSelectionBoxesColor(characSelectBoxes, &selectP2,
                                    al_map_rgb(255, 0, 0));

          if (startCount) frames++;
          redraw = true;
          break;

        case ALLEGRO_EVENT_KEY_DOWN:
          if (!p1Selected)
            p1Selected =
                updateSelectionBoxes(characSelectBoxes, &selectP1, keyboardKeys,
                                     p1Keys, event, selectFighterSound);
          if (!p2Selected)
            p2Selected =
                updateSelectionBoxes(characSelectBoxes, &selectP2, keyboardKeys,
                                     p2Keys, event, selectFighterSound);

          startCount = (p1Selected && p2Selected);

          if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) done = true;

          break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
          done = true;
          break;
      }

      if (frames >= 30) chacSelecLoop = false;
      // If the user wants to close the game break the loop
      if (done) break;

      // keyboardUpdate(&event, keyboardKeys);

      // ------------ REDRAW PHASE ------------
      if (redraw && al_event_queue_is_empty(queue)) {
        dispPreDraw(bufferBitmap);
        al_clear_to_color(al_map_rgb(15, 30, 86));

        drawSelectionBoxes(characSelectBoxes, characSelectSprites->logo);
        drawCharacterCursorOver(characSelectBoxes, selectP1, selectP2, font,
                                p1Selected, p2Selected,
                                al_get_timer_count(timer), &twinkle);
        dispPostDraw(disp, bufferBitmap);
        redraw = false;
      }

      al_wait_for_event(queue, &event);
    }

    if (done) break;

    // After the fighters have been selected, we assigne them for the player and
    // set the y position
    player1->character = allCharacters[selectP1];
    player1->yPosition = FLOOR - player1->character->height;
    player2->character = allCharacters[selectP2];
    player2->yPosition = FLOOR - player2->character->height;
    // And get the stage, if even guile stage if its odd las vegas stage
    stageChoice = al_get_timer_count(timer) % 2;

    bool versusLoop = true;
    unsigned short frames = 0;

    al_play_sample(versusSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    while (versusLoop) {
      if (event.type == ALLEGRO_EVENT_TIMER) {
        dispPreDraw(bufferBitmap);
        al_clear_to_color(al_map_rgb(15, 30, 86));

        drawVersusScreen(characSelectBoxes[selectP1].portraitImage,
                         characSelectBoxes[selectP2].portraitImage,
                         characSelectSprites->vs_sprite);
        dispPostDraw(disp, bufferBitmap);
        frames++;
        if (frames > 120) versusLoop = false;
      }
      al_wait_for_event(queue, &event);
    }

    // MATCH CONTROL VARIABLES
    bool matchLoop = true;
    bool controlON = false;
    matchInterface->rounds = 0;

    matchInterface->matchUP = true;
    matchInterface->roundUP = true;

    frames = 0;
    resetPlayer(player1, PLAYER_1_INIT_POSIT_X,
                FLOOR - player1->character->height, true,
                !matchInterface->matchUP);
    resetPlayer(player2, PLAYER_2_INIT_POSIT_X,
                FLOOR - player2->character->height, false,
                !matchInterface->matchUP);

    bool narratorFight = false;
    bool narratorRound = false;
    bool narratorNumber = false;

    // ---------------- MATCH LOGIC ---------------
    while (matchLoop) {
      // -------------- UPDATE PHASE --------------

      switch (event.type) {
        case ALLEGRO_EVENT_TIMER:

          // If the control is on the player can move around and start the fight
          if (controlON) {
            playerUpdateMovements(player1, player2, keyboardKeys, p1Keys,
                                  al_get_timer_count(timer));
            playerUpdateMovements(player2, player1, keyboardKeys, p2Keys,
                                  al_get_timer_count(timer));

            playerUpdateAttacks(player1, player2, keyboardKeys, p1Keys);
            playerUpdateAttacks(player2, player1, keyboardKeys, p2Keys);
            controlON = matchUpdate(matchInterface, player1, player2);
          }

          updateAnimation(player1, al_get_timer_count(timer));
          updateAnimation(player2, al_get_timer_count(timer));
          matchInterfaceUpdate(matchInterface, player1, player2);
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
        al_clear_to_color(al_map_rgb(80, 136, 200));

        drawStage(guileStage, vegasStage, al_get_timer_count(timer),
                  stageChoice);
        drawPlayer(player1, boxColors[selectP1], al_get_timer_count(timer));
        drawPlayer(player2, boxColors[selectP2], al_get_timer_count(timer));
        drawMatchInterface(matchInterface, player1, player2,
                           al_get_timer_count(timer), &twinkle);

        // If the players are not able to control and the round is up, well it
        // just started so lets draw the things
        if (!controlON && matchInterface->roundUP)
          controlON =
              roundStartWriter(matchInterface, &frames, font, &narratorRound,
                               &narratorFight, &narratorNumber);

        // If the match ended, we have a winner so lets show him
        if (!matchInterface->matchUP) {
          matchLoop = drawWinnerGreater(matchInterface, &frames, font,
                                        player2->roundsWon != 2);
          if (player1->roundsWon == 2) {
            player1->animationDone = false;
            player1->character->currentSprite = VICTORY;
          } else {
            player2->animationDone = false;
            player2->character->currentSprite = VICTORY;
          }
        }
        // If the round is not up, well someone died, so lets check this and
        // start a new round
        else if (!matchInterface->roundUP) {
          if (roundEndWriter(matchInterface, &frames, font)) {
            narratorRound = false;
            narratorFight = false;
            narratorNumber = false;
            resetPlayer(player1, PLAYER_1_INIT_POSIT_X,
                        FLOOR - player1->character->height, true,
                        !matchInterface->matchUP);
            resetPlayer(player2, PLAYER_2_INIT_POSIT_X,
                        FLOOR - player2->character->height, false,
                        !matchInterface->matchUP);
          }
        }

        dispPostDraw(disp, bufferBitmap);
        redraw = false;
      }

      al_wait_for_event(queue, &event);
    }
  }
  dispDestroyer(disp, bufferBitmap);
  playerDestroyer(player1);
  playerDestroyer(player2);
  for (int i = 0; i < 4; i++) characterDestroyer(allCharacters[i]);
  matchInterfaceDestroyer(matchInterface);
  destroyCharacSelectSprites(characSelectSprites);
  destroyStage(guileStage, vegasStage);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);
  al_destroy_sample(startSound);
  al_destroy_sample(selectFighterSound);
  al_destroy_sample(versusSound);
  return 0;
}
