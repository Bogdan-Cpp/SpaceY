#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL_image.h>
#include <stdlib.h>

void menuDraw(SDL_Renderer *renderer){
    SDL_RenderPresent(renderer);
    SDL_Delay(16);
}

void gameDraw(SDL_Renderer *renderer, SDL_Texture *rocket_img, SDL_Texture *mars_img, float *poz_X, float *poz_Y){
    int win_X;
    int win_Y;

    SDL_Rect mars_rect = {100, 400, 200, 200};
    SDL_RenderCopy(renderer, mars_img, NULL, &mars_rect);

    SDL_Rect rocket_rect = {*poz_X, *poz_Y, 80, 100};
    SDL_RenderCopy(renderer, rocket_img, NULL, &rocket_rect);
        
    SDL_RenderPresent(renderer);

    SDL_Delay(16); 
}

void settingsDraw(SDL_Renderer *renderer){
    SDL_RenderPresent(renderer);
    SDL_Delay(16);
}

void gameWindowInit(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}