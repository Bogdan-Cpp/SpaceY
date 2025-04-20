#ifndef DRAW_H
#define DRAW_H

void menuDraw(SDL_Renderer *renderer, TTF_Font *font, TTF_Font *font2, TTF_Font *font3,
    int *option_arrow_X, int *option_arrow_Y, SDL_Texture *menu_back, SDL_Texture *info_back,
    SDL_Texture *settings_back, int *option);

void gameDraw(SDL_Renderer *renderer, SDL_Texture *rocket_img, SDL_Texture *mars_img,
    float *poz_X, float *poz_Y);

void settingsDraw(SDL_Renderer *renderer);

void infoDraw(SDL_Renderer *renderer);

void gameWindowInit(SDL_Renderer *renderer);

#endif