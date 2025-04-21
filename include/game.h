#ifndef GAME_H
#define GAME_H

void inGame(SDL_Event *e, SDL_Renderer *renderer, SDL_Texture *rocket_img, SDL_Texture *mars_img,
    int *runing, float *poz_X, float *poz_Y, int *stage);

int checkCollision(SDL_Rect a, SDL_Rect b);

#endif