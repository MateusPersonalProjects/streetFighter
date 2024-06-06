#include "keyboard.h"

#include <allegro5/base.h>
#include <allegro5/events.h>
#include <string.h>

/*
  Inicitalize the keyboardKeys array with 0
*/
void keyboardInit(unsigned char* keyboardKeys, size_t size) {
  memset(keyboardKeys, 0, size);
}

/*
  Updates the keyboardKeys array with the user input
*/
void keyboardUpdate(ALLEGRO_EVENT* event, unsigned char* keyboardKeys) {
  switch (event->type) {
    // Reset all keys that were released
    case ALLEGRO_EVENT_TIMER:
      for (int i = 0; i < ALLEGRO_KEY_MAX; i++) keyboardKeys[i] &= KEY_PRESSED;
      break;
    // Set key as pressed
    case ALLEGRO_EVENT_KEY_DOWN:
      keyboardKeys[event->keyboard.keycode] = KEY_PRESSED | KEY_RELEASED;
      break;
    // Prepare key to be reseted when the timer ticks
    case ALLEGRO_EVENT_KEY_UP:
      keyboardKeys[event->keyboard.keycode] &= KEY_RELEASED;
      break;
  }
}
