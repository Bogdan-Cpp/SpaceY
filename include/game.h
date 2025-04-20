#ifndef GAME_H
#define GAME_H

void inGame(SDL_Event *e, SDL_Renderer *renderer, SDL_Texture *rocket_img, SDL_Texture *mars_img, int *runing, float *poz_X, float *poz_Y, int *stage);
void inSettings(SDL_Renderer *renderer, SDL_Event *e, int *runing, int *stage);
void inMenu(SDL_Renderer *renderer, SDL_Event *e, int *runing, int *stage);
void menuDraw(SDL_Renderer *renderer);
void gameDraw(SDL_Renderer *renderer, SDL_Texture *rocket_img, SDL_Texture *mars_img, float *poz_X, float *poz_Y);
void gameWindowInit(SDL_Renderer *renderer);

#endif