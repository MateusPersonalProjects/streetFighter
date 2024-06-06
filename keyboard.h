#include <allegro5/allegro5.h>

#ifndef __KEYBOARD__
#define __KEYBOARD__

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


