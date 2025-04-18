#ifndef INCLUDE_H
#define INCLUDE_H

void Input(SDL_Event *e, int *runing, float *poz_X, float *poz_Y);
bool leftCollision(float *poz_X);
bool rightCollision(float *poz_X);

#endif