#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
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

void inMenu(SDL_Renderer *renderer, SDL_Event *e, int *runing, int *stage, TTF_Font *font, TTF_Font *font2,
    TTF_Font *font3, int *option, int *option_arrow_X, int *option_arrow_Y){
    
    menuInput(e, runing, stage, option, option_arrow_X, option_arrow_Y);

    gameWindowInit(renderer);
    menuDraw(renderer, font, font2, font3, option_arrow_X, option_arrow_Y);
}

void inSettings(SDL_Renderer *renderer, SDL_Event *e, int *runing, int *stage){
    settingsInput(e, runing, stage);

    gameWindowInit(renderer);
    settingsDraw(renderer);
}

void inInfo(SDL_Renderer *renderer, SDL_Event *e, int *runing, int *stage){
    infoInput(e, runing, stage);

    gameWindowInit(renderer);
    infoDraw(renderer);
}