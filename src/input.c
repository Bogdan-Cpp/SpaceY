#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/input.h"

void gameInput(SDL_Event *e, int *runing, float *poz_X, float *poz_Y, int *stage){
    while (SDL_PollEvent(e)) {
        if (e->type == SDL_QUIT) {
            *runing = 0;
        }
        
        if(e->key.keysym.sym){
            switch(e->key.keysym.sym){
                case SDLK_d:
                    if(!rightCollision(poz_X)){
                        *poz_X += 18;
                    }
                    break;
                
                case SDLK_a:
                    if(!leftCollision(poz_X)){
                        *poz_X -= 18;
                    }
                    break;
                
                //menus navigation
                case SDLK_ESCAPE:
                    SDL_Quit();
                    break;
                
                case SDLK_1:
                    *stage = 1;
                    break;
                
                case SDLK_3:
                    *stage = 3;
                    break;
            }
        }
    }
}

void menuInput(SDL_Event *e, int *runing, int *stage){
    while (SDL_PollEvent(e)) {
        if (e->type == SDL_QUIT) {
            *runing = 0;
        }
        
        if(e->key.keysym.sym){
            switch(e->key.keysym.sym){
                case SDLK_2:
                    *stage = 2;
                    break;
                
                case SDLK_3:
                    *stage = 3;
                    break;
            }
        }
    }
}

void settingsInput(SDL_Event *e, int *runing, int *stage){
    while (SDL_PollEvent(e)) {
        if (e->type == SDL_QUIT) {
            *runing = 0;
        }
        
        if(e->key.keysym.sym){
            switch(e->key.keysym.sym){
                case SDLK_1:
                    *stage = 1;
                    break;
                
                case SDLK_2:
                    *stage = 2;
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