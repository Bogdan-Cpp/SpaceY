#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdlib.h>
#include "../include/game.h"
#include "../include/input.h"

void inMenu(SDL_Renderer *renderer, SDL_Event *e, int *runing, int *stage, TTF_Font *font, TTF_Font *font2,
    TTF_Font *font3, int *option, int *option_arrow_X, int *option_arrow_Y, SDL_Texture *menu_back, 
    SDL_Texture *info_back, SDL_Texture *settings_back){
    
    menuInput(e, runing, stage, option, option_arrow_X, option_arrow_Y);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Color title2 = {255, 255, 255};

    if(*option == 1){
        SDL_Rect menu_rect = {0, 0, 1200, 800};
        SDL_RenderCopy(renderer, menu_back, NULL, &menu_rect);
    }
    else if(*option == 2){
        SDL_Rect info_rect = {0, 0, 1200, 800};
        SDL_RenderCopy(renderer, info_back, NULL, &info_rect);
    }
    else if(*option == 3){
        SDL_Rect settings_rect = {0, 0, 1200, 800};
        SDL_RenderCopy(renderer, settings_back, NULL, &settings_rect);
    }

    SDL_Surface *play = TTF_RenderText_Solid(font2, "Play", title2);
    SDL_Surface *info = TTF_RenderText_Solid(font2, "Info", title2);
    SDL_Surface *settings = TTF_RenderText_Solid(font2, "Settings", title2);
    SDL_Surface *arrow = TTF_RenderText_Solid(font2, "->", title2);

    SDL_Texture *texture4 = SDL_CreateTextureFromSurface(renderer, play);
    SDL_Texture *texture5 = SDL_CreateTextureFromSurface(renderer, info);
    SDL_Texture *texture6 = SDL_CreateTextureFromSurface(renderer, settings);
    SDL_Texture *texture7 = SDL_CreateTextureFromSurface(renderer, arrow);

    SDL_Rect rect4 = {540, 400, play->w, play->h};
    SDL_Rect rect5 = {540, 450, info->w, info->h};
    SDL_Rect rect6 = {500, 500, settings->w, settings->h};
    SDL_Rect rect7 = {*option_arrow_X, *option_arrow_Y, arrow->w, arrow->h};

    SDL_RenderCopy(renderer, texture4, NULL, &rect4);
    SDL_RenderCopy(renderer, texture5, NULL, &rect5);
    SDL_RenderCopy(renderer, texture6, NULL, &rect6);
    SDL_RenderCopy(renderer, texture7, NULL, &rect7);

    SDL_DestroyTexture(texture4);
    SDL_FreeSurface(play);
    SDL_DestroyTexture(texture5);
    SDL_FreeSurface(info);
    SDL_DestroyTexture(texture6);
    SDL_FreeSurface(settings);
    SDL_DestroyTexture(texture7);
    SDL_FreeSurface(arrow);

    SDL_RenderPresent(renderer);
    SDL_Delay(16);
}