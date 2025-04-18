#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/input.h"

void Input(SDL_Event *e, int *runing, float *poz_X, float *poz_Y){
    while (SDL_PollEvent(e)) {
        if (e->type == SDL_QUIT) {
            *runing = 0;
        }
        if(e->key.keysym.sym){
            switch(e->key.keysym.sym){
                case SDLK_d:
                    if(!rightCollision(poz_X)){
                        *poz_X += 100 * 0.5 * 0.4;
                    }
                    break;
                
                case SDLK_a:
                    if(!leftCollision(poz_X)){
                        *poz_X -= 100 * 0.5 * 0.4;
                    }
                    break;
                
                case SDLK_p:
                    SDL_Quit();
                    break;
            }
        }
    }
}

bool leftCollision(float *poz_X){
    if(*poz_X <= 10){
        return true;
    }
    else{return false;}
}

bool rightCollision(float *poz_X){
    if(*poz_X >= 1110){
        return true;
    }
    else{return false;}
}