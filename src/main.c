#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../include/input.h"
#include "../include/main.h"

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
    int stage = 1;
    int option = 1;
    int option_arrow_X = 500;
    int option_arrow_Y = 400;
    bool isAlgo = true;
    int randY;
    float move2 = 0;
    float move = -100;
    int frameCounter = 0;
    int countTexture = 0;
    float backpoz1 = 0;
    float backpoz2 = -800;
    int temp[4000];

    srand(time(NULL));
    int rand_obj;
    int pozx;
    int pozy;
    int size;

    SDL_Texture *rocket_img = IMG_LoadTexture(renderer, "../assets/rocket1.png");
    SDL_Texture *rocket_img2 = IMG_LoadTexture(renderer, "../assets/rocket2.png");
    SDL_Texture *rocket_img3 = IMG_LoadTexture(renderer, "../assets/rocket3.png");
    
    SDL_Texture *nederplanet = IMG_LoadTexture(renderer, "../assets/nederplanet.png");
    SDL_Texture *strangemoon = IMG_LoadTexture(renderer, "../assets/strangemoon.png");
    SDL_Texture *mars = IMG_LoadTexture(renderer, "../assets/mars.png");
    SDL_Texture *iceplanet = IMG_LoadTexture(renderer, "../assets/iceplanet.png");
    SDL_Texture *endplanet = IMG_LoadTexture(renderer, "../assets/endplanet.png");
    SDL_Texture *desertplanet = IMG_LoadTexture(renderer, "../assets/desertplanet.png");
    
    SDL_Texture *background = IMG_LoadTexture(renderer, "../assets/background.png");
    SDL_Texture *menu_back = IMG_LoadTexture(renderer, "../assets/menu.png");
    SDL_Texture *info_back = IMG_LoadTexture(renderer, "../assets/info.png");
    SDL_Texture *settings_back = IMG_LoadTexture(renderer, "../assets/settings.png");
    TTF_Font *font = TTF_OpenFont("../assets/font1.ttf", 100);
    TTF_Font *font2 = TTF_OpenFont("../assets/font2.ttf", 30);
    TTF_Font *font3 = TTF_OpenFont("../assets/font2.ttf", 20);
    
    if(!nederplanet){return -1;}
    if(!strangemoon){return -1;}
    if(!mars){return -1;}
    if(!iceplanet){return -1;}
    if(!endplanet){return -1;}
    if(!desertplanet){return -1;}
    if(!background){return -1;}
    if (!font) {return -1;}
    if (!font2) {return -1;}
    if (!font3) {return -1;}
    if(!rocket_img){return -1;}
    if(!rocket_img2){return -1;}
    if(!rocket_img3){return -1;}
    if(!menu_back){return -1;}

    while (runing) {
        switch(stage){
            case 1:
                menuInput(&e, &runing, &stage, &option, &option_arrow_X, &option_arrow_Y);

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);
        
                SDL_Color title2 = {255, 255, 255};
        
                if(option == 1){
                    SDL_Rect menu_rect = {0, 0, 1200, 800};
                    SDL_RenderCopy(renderer, menu_back, NULL, &menu_rect);
                }
                else if(option == 2){
                    SDL_Rect info_rect = {0, 0, 1200, 800};
                    SDL_RenderCopy(renderer, info_back, NULL, &info_rect);
                }
                else if(option == 3){
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
                SDL_Rect rect7 = {option_arrow_X, option_arrow_Y, arrow->w, arrow->h};
        
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
                break;

            case 2:
                int count = 0;
                gameInput(&e, &runing, &poz_X, 450, &stage);
    
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);
                SDL_Rect background_rect = {0, backpoz1, 1200, 800};
                SDL_Rect background_rect2 = {0, backpoz2, 1200, 800};
                backpoz1 += 0.7;
                backpoz2 += 0.7f;
                if(backpoz1 >= 800){backpoz1 = -800;}
                if(backpoz2 >= 800){backpoz2 = -800;}
                SDL_Rect rocket_rect = {poz_X, 450, 80, 100};
                SDL_RenderCopy(renderer, background, NULL, &background_rect);
                SDL_RenderCopy(renderer, background, NULL, &background_rect2);

                move += 3;

                Obstacole obs[1000];
                
                for(int i = 0; i < 1000; i++){
                    if(isAlgo){
                        rand_obj = rand() % 7;
                        temp[count] = rand_obj;
                        count++;

                        pozx = rand() % 1000;
                        temp[count] = pozx;
                        count++;
                    
                        pozy -= 100;
                        temp[count] = pozy;
                        count++;

                        size = rand() % 300;
                        temp[count] = size;
                        count++;
                    }else{
                        rand_obj = temp[count];
                        count++;
                        pozx = temp[count];
                        count++;
                        pozy = temp[count];
                        count++;
                        size = temp[count];
                        count++;
                    }
                    
                    switch(rand_obj){
                        case 0: obs[i] = obstacle(nederplanet, pozx, pozy + move, size, size, checkCollision); break;
                        case 1: obs[i] = obstacle(nederplanet, pozx, pozy + move, size, size, checkCollision); break;
                        case 2: obs[i] = obstacle(mars, pozx, pozy + move, size, size, checkCollision); break;
                        case 3: obs[i] = obstacle(iceplanet, pozx, pozy + move, size, size, checkCollision); break;
                        case 4: obs[i] = obstacle(endplanet, pozx, pozy + move, size, size, checkCollision); break;
                        case 5: obs[i] = obstacle(desertplanet, pozx, pozy + move, size, size, checkCollision); break;
                        case 6: obs[i] = obstacle(strangemoon, pozx, pozy + move, size, size, checkCollision); break;
                    }
                }
                isAlgo = false;
                
                for(int x = 0; x < 1000; x++){
                    
                    if(checkCollision(rocket_rect, obs[x].about)){
                        isAlgo = true;
                        break;
                    }
                    if(obs[x].texture != NULL){
                        SDL_RenderCopy(renderer, obs[x].texture, NULL, &obs[x].about);
                    }
                    else{printf("Texture is NULL\n");}
                }

                frameCounter++;
                if (frameCounter >= 10) {
                    countTexture = (countTexture + 1) % 3;
                    frameCounter = 0;
                }
                switch(countTexture){
                    case 0: SDL_RenderCopy(renderer, rocket_img, NULL, &rocket_rect); break;
                    case 1: SDL_RenderCopy(renderer, rocket_img2, NULL, &rocket_rect); break;
                    case 2: SDL_RenderCopy(renderer, rocket_img3, NULL, &rocket_rect); break;
                }
                
                SDL_RenderPresent(renderer);
                SDL_Delay(16); 
                break;

            case 3:
                settingsInput(&e, &runing, &stage);
    
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);
                SDL_RenderPresent(renderer);
                SDL_Delay(16);
                break;
            
            case 4:
                infoInput(&e, &runing, &stage);
    
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);
                SDL_RenderPresent(renderer);
                SDL_Delay(16);
                break;
        }                
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

int checkCollision(SDL_Rect a, SDL_Rect b) {
    return SDL_HasIntersection(&a, &b);
}