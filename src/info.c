#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/info.h"
#include "../include/input.h"

void inInfo(SDL_Renderer *renderer, SDL_Event *e, int *runing, int *stage){
    infoInput(e, runing, stage);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(16);
}