#ifndef INCLUDE_H
#define INCLUDE_H

void gameInput(SDL_Event *e, int *runing, float *poz_X, float *poz_Y, int *stage);
void menuInput(SDL_Event *e, int *runing, int *stage);
void settingsInput(SDL_Event *e, int *runing, int *stage);
bool leftCollision(float *poz_X);
bool rightCollision(float *poz_X);

#endif