#include "character.h"

/*
  Initialize a new character
*/
CHARACTER* characterInit(FIGHTER_SPRITES* fighterSprite) {
  CHARACTER* newChar = (CHARACTER*)malloc(sizeof(CHARACTER));
  if (newChar == NULL) exit(1);

  newChar->width = fighterSprite->movesSprites[STEADY].drawBoxWidth;
  newChar->height = fighterSprite->movesSprites[STEADY].drawBoxHeight;
  newChar->hurtWidth = fighterSprite->movesSprites[STEADY].hurtBoxWidth;
  newChar->hurtHeight = fighterSprite->movesSprites[STEADY].hurtBoxHeight;
  // newChar->crouchHeight = 0;
  newChar->currentSprite = STEADY;
  newChar->fighterGraphics = fighterSprite;

  // Initialize character sounds
  newChar->sounds.attack = al_load_sample("./sounds/3CH.wav");
  newChar->sounds.gotHit = al_load_sample("./sounds/2AH.wav");
  newChar->sounds.blockHit = al_load_sample("./sounds/2BH.wav");
  return newChar;
}

/*
  Load moviment sprites
*/
void movimentSpritesInit(FIGHTER_SPRITES* fighter, SPRITE_LIST sprite,
                         short numFrames, short currentFrame, short draw_h,
                         short draw_w, short hurt_h, short hurt_w,
                         const short* idle_x, const short* idle_y) {
  // Gets information for animations
  fighter->movesSprites[sprite].numFrames = numFrames;
  fighter->movesSprites[sprite].currentFrame = currentFrame;

  // Gets information for the draw box
  fighter->movesSprites[sprite].drawBoxHeight = draw_h;
  fighter->movesSprites[sprite].drawBoxWidth = draw_w;

  // Gets information for the hurt box
  fighter->movesSprites[sprite].hurtBoxHeight = hurt_h;
  fighter->movesSprites[sprite].hurtBoxWidth = hurt_w;

  // Loop to grab the sprites
  for (int i = 0; i < numFrames; i++)
    fighter->movesSprites[sprite].sprites[i] =
        grabSprite(fighter->sheet, idle_x[i], idle_y[i], draw_w, draw_h);
}

/*
  Load sprites with arrays for draw w and draw h
*/
void attackSpritesInit(FIGHTER_SPRITES* fighter, SPRITE_LIST sprite,
                       short numFrames, short currentFrame, short draw_h,
                       short draw_w, short hurt_h, short hurt_w,
                       const short* idle_x, const short* idle_y, short hit_w,
                       short hit_h, short hit_y, const short* draw_w_array,
                       const short* draw_h_array) {
  // Gets information for animations
  fighter->movesSprites[sprite].numFrames = numFrames;
  fighter->movesSprites[sprite].currentFrame = currentFrame;

  // Gets information for the draw box
  fighter->movesSprites[sprite].drawBoxHeight = draw_h;
  fighter->movesSprites[sprite].drawBoxWidth = draw_w;

  // Gets information for the hurt box
  fighter->movesSprites[sprite].hurtBoxHeight = hurt_h;
  fighter->movesSprites[sprite].hurtBoxWidth = hurt_w;

  // Gets information for the hit box
  fighter->movesSprites[sprite].hitBoxWidth = hit_w;
  fighter->movesSprites[sprite].hitBoxHeight = hit_h;
  fighter->movesSprites[sprite].hitBox_Y = hit_y;

  // Loop to grab the sprites
  for (int i = 0; i < numFrames; i++)
    fighter->movesSprites[sprite].sprites[i] = grabSprite(
        fighter->sheet, idle_x[i], idle_y[i], draw_w_array[i], draw_h_array[i]);
}

/*
  Free the memory that a character was being utilized by a character
*/
void characterDestroyer(CHARACTER* character) {
  for (int i = 0; i < SPRITE_LIST_NUM; i++) {
    int numSprites = character->fighterGraphics->movesSprites[i].numFrames;
    for (int j = 0; j < numSprites; j++) {
      al_destroy_bitmap(character->fighterGraphics->movesSprites[i].sprites[j]);
    }

    free(character->fighterGraphics->movesSprites[i].sprites);
  }
  al_destroy_bitmap(character->fighterGraphics->sheet);
  al_destroy_sample(character->sounds.attack);
  al_destroy_sample(character->sounds.gotHit);
  al_destroy_sample(character->sounds.blockHit);
  free(character->fighterGraphics);
  free(character);
}
