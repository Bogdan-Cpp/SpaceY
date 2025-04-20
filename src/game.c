#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL_image.h>
#include <stdlib.h>
#include "../include/game.h"
#include "../include/input.h"
#include "../include/draw.h"

void inGame(SDL_Event *e, SDL_Renderer *renderer, SDL_Texture *rocket_img, SDL_Texture *mars_img,
    int *runing, float *poz_X, float *poz_Y, int *stage){
    
    gameInput(e, runing, poz_X, poz_Y, stage);

    gameWindowInit(renderer);
    gameDraw(renderer, rocket_img, mars_img, poz_X, poz_Y);
}

void inMenu(SDL_Renderer *renderer, SDL_Event *e, int *runing, int *stage){
    menuInput(e, runing, stage);

    gameWindowInit(renderer);
    menuDraw(renderer);
}

void inSettings(SDL_Renderer *renderer, SDL_Event *e, int *runing, int *stage){
    settingsInput(e, runing, stage);

    gameWindowInit(renderer);
    settingsDraw(renderer);
}