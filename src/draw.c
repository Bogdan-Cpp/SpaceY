#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdlib.h>

void menuDraw(SDL_Renderer *renderer, TTF_Font *font, TTF_Font *font2, TTF_Font *font3, int *option_arrow_X,
    int *option_arrow_Y){

    SDL_Color title = {255, 255, 0};
    SDL_Color title2 = {255, 255, 255};
    SDL_Color title3 = {56, 255, 255};
    
    SDL_Surface *surface = TTF_RenderText_Solid(font, "SpaceY", title);
    SDL_Surface *surface2 = TTF_RenderText_Solid(font2, "Welcome", title2);
    SDL_Surface *surface3 = TTF_RenderText_Solid(font3, "to", title3);
    SDL_Surface *play = TTF_RenderText_Solid(font2, "Play", title2);
    SDL_Surface *info = TTF_RenderText_Solid(font2, "Info", title2);
    SDL_Surface *settings = TTF_RenderText_Solid(font2, "Settings", title2);
    SDL_Surface *arrow = TTF_RenderText_Solid(font2, "->", title2);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Texture *texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    SDL_Texture *texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
    SDL_Texture *texture4 = SDL_CreateTextureFromSurface(renderer, play);
    SDL_Texture *texture5 = SDL_CreateTextureFromSurface(renderer, info);
    SDL_Texture *texture6 = SDL_CreateTextureFromSurface(renderer, settings);
    SDL_Texture *texture7 = SDL_CreateTextureFromSurface(renderer, arrow);

    SDL_Rect rect = {100, 50, surface->w, surface->h};
    SDL_Rect rect2 = {160, 30, surface2->w, surface2->h};
    SDL_Rect rect3 = {70, 100, surface3->w, surface3->h};
    SDL_Rect rect4 = {540, 400, play->w, play->h};
    SDL_Rect rect5 = {540, 450, info->w, info->h};
    SDL_Rect rect6 = {500, 500, settings->w, settings->h};
    SDL_Rect rect7 = {*option_arrow_X, *option_arrow_Y, arrow->w, arrow->h};

    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderCopy(renderer, texture2, NULL, &rect2);
    SDL_RenderCopy(renderer, texture3, NULL, &rect3);
    SDL_RenderCopy(renderer, texture4, NULL, &rect4);
    SDL_RenderCopy(renderer, texture5, NULL, &rect5);
    SDL_RenderCopy(renderer, texture6, NULL, &rect6);
    SDL_RenderCopy(renderer, texture7, NULL, &rect7);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture2);
    SDL_FreeSurface(surface2);
    SDL_DestroyTexture(texture3);
    SDL_FreeSurface(surface3);
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

void infoDraw(SDL_Renderer *renderer){
    SDL_RenderPresent(renderer);
    SDL_Delay(16);
}

void gameWindowInit(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}