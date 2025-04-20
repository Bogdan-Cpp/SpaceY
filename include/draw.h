#ifndef DRAW_H
#define DRAW_H

void menuDraw(SDL_Renderer *renderer);
void gameDraw(SDL_Renderer *renderer, SDL_Texture *rocket_img, SDL_Texture *mars_img, float *poz_X, float *poz_Y);
void settingsDraw(SDL_Renderer *renderer);
void gameWindowInit(SDL_Renderer *renderer);

#endif