#include <SDL.h>
#include <stdio.h>
#include "../include/game.h"

void gameWindowInit(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void gameDraw(SDL_Renderer *renderer, SDL_Texture *rocket_img, float *poz_X, float *poz_Y){
    int win_X;
    int win_Y;

    SDL_Rect rocket_rect = {*poz_X, *poz_Y, 80, 100};
    SDL_RenderCopy(renderer, rocket_img, NULL, &rocket_rect);
        
    SDL_RenderPresent(renderer);

    SDL_Delay(16); 
}