#ifndef GAME_H
#define GAME_H

void gameWindowInit(SDL_Renderer *renderer);
void gameDraw(SDL_Renderer *renderer, SDL_Texture *rocket_img, float *poz_X, float *poz_Y);

#endif