#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <stdbool.h>
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

    SDL_Texture* rocket_img = IMG_LoadTexture(renderer, "../assets/rocket.png");
    if(!rocket_img){
        return -1;
    }

    while (runing) {
        Input(&e, &runing, &poz_X, &poz_Y);
        gameWindowInit(renderer);

        gameDraw(renderer, rocket_img, &poz_X, &poz_Y);        
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}