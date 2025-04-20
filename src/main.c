#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/input.h"
#include "../include/game.h"

float width = 1200.f;
float heith = 800.f;

bool leftCollision(float *poz_X);
bool rightCollision(float *poz_X);

int main(int argc, char* argv[]) {
    bool isCollision = false;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Eroare la inițializarea SDL: %s\n", SDL_GetError());
        return 1;
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("ERROR to SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    if(TTF_Init() == -1){
        printf("Eroare TTF: %s\n", TTF_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "SpaceY",           
        SDL_WINDOWPOS_CENTERED,           
        SDL_WINDOWPOS_CENTERED,           
        width, heith,                         
        SDL_WINDOW_SHOWN                 
    );

    if (!window) {
        printf("Eroare la crearea ferestrei: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        printf("Eroare la crearea rendererului: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
    SDL_Event e;
    int runing = 1;
    float poz_X = width / 2;
    float poz_Y = heith / 2;
    int stage = 1;
    int option = 1;
    int count = 1;
    int option_arrow_X = 500;
    int option_arrow_Y = 400;

    SDL_Texture *rocket_img = IMG_LoadTexture(renderer, "../assets/rocket.png");
    SDL_Texture *mars_img = IMG_LoadTexture(renderer, "../assets/mars.png");
    TTF_Font *font = TTF_OpenFont("../assets/font1.ttf", 100);
    TTF_Font *font2 = TTF_OpenFont("../assets/font2.ttf", 30);
    TTF_Font *font3 = TTF_OpenFont("../assets/font2.ttf", 20);
    
    if (!font) {return -1;}
    if (!font2) {return -1;}
    if (!font3) {return -1;}
    if(!rocket_img){return -1;}
    if(!mars_img){return -1;}

    while (runing) {
        switch(stage){
            case 1:
                inMenu(renderer, &e, &runing, &stage, font, font2, font3, &option, &option_arrow_X, &option_arrow_Y);
                break;

            case 2:
                inGame(&e, renderer, rocket_img, mars_img, &runing, &poz_X, &poz_Y, &stage);
                break;

            case 3:
                inSettings(renderer, &e, &runing, &stage);
                break;
            
            case 4:
                inInfo(renderer, &e, &runing, &stage);
                break;
        }                
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}