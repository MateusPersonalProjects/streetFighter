
#ifndef __KEYBOARD__
#define __KEYBOARD__
#include <allegro5/allegro5.h>
#include <allegro5/base.h>
#include <allegro5/events.h>
#include <string.h>

#define KEY_PRESSED 1
#define KEY_RELEASED 2

/*
  Inicitalize the keyboardKeys array with 0
*/
void keyboardInit(unsigned char* keyboardKeys, size_t size);

/*
  Updates the keyboardKeys array with the user input
*/
void keyboardUpdate(ALLEGRO_EVENT* event, unsigned char* keyboardKeys);
 
#endif // !__KEYBOARD__
#define __KEYBOARD__


