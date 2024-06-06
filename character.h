#ifndef __CHARACTER__
#define __CHARACTER__

typedef struct{
  int width;
  int height;
  // MOVE LIST (array de ponteiro para funções)
  // SPRITES :)
} CHARACTER;

/*
  Initialize a new character
*/
CHARACTER* characterInit(int width, int height);

/*
  Free the memory that a character was being utilized by a character
*/
void characterDestroyer(CHARACTER* character);

#endif // !__CHARACTER__

