#ifndef GAME_H
#define GAME_H

void inGame(SDL_Event *e, SDL_Renderer *renderer, SDL_Texture *rocket_img, SDL_Texture *mars_img,
    int *runing, float *poz_X, float *poz_Y, int *stage);

void inSettings(SDL_Renderer *renderer, SDL_Event *e, int *runing, int *stage);

void inMenu(SDL_Renderer *renderer, SDL_Event *e, int *runing, int *stage, TTF_Font *font,
    TTF_Font *font2, TTF_Font *font3, int *option, int *option_arrow_X, int *option_arrow_Y);

void inInfo(SDL_Renderer *renderer, SDL_Event *e, int *runing, int *stage);

#endif