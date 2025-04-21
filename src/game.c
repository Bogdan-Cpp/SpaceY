#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/game.h"
#include "../include/input.h"

void inGame(SDL_Event *e, SDL_Renderer *renderer, SDL_Texture *rocket_img, SDL_Texture *mars_img,
    int *runing, float *poz_X, float *poz_Y, int *stage){
    
    gameInput(e, runing, poz_X, poz_Y, stage);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    int win_X;
    int win_Y;
    
    SDL_Rect mars_rect = {100, 400, 200, 200};
    SDL_RenderCopy(renderer, mars_img, NULL, &mars_rect);
    
    SDL_Rect rocket_rect = {*poz_X, *poz_Y, 80, 100};
    SDL_RenderCopy(renderer, rocket_img, NULL, &rocket_rect);
        
    if (checkCollision(rocket_rect, mars_rect)){
        printf("coliziune\n");
    }else{
        printf("not coliding\n");
    }
    
    SDL_RenderPresent(renderer);
    
    SDL_Delay(16); 
}

int checkCollision(SDL_Rect a, SDL_Rect b) {
    return SDL_HasIntersection(&a, &b);
}