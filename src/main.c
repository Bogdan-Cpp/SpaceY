#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../include/input.h"

typedef struct{
    int x;
    int y;
    int sx;
    int sy;
}Pozitions;

typedef struct{
    SDL_Texture *texture;
    SDL_Rect about;
    int poz_X;
    int poz_Y;
    int Scale_X;
    int Scale_Y;
    int (*checkCollision)(SDL_Rect, SDL_Rect);
}Obstacole;

Obstacole obstacle(SDL_Texture *texture, int poz_X, int poz_Y, int Scale_X, int Scale_Y,
    int (*checkCollision)(SDL_Rect, SDL_Rect)){
    
    Obstacole ob;

    ob.texture = texture;

    ob.poz_X = poz_X;
    ob.poz_Y = poz_Y;
    ob.Scale_X = Scale_X;
    ob.Scale_Y = Scale_Y;

    ob.about.x = poz_X;
    ob.about.y = poz_Y;
    ob.about.w = Scale_X;
    ob.about.h = Scale_Y;

    ob.checkCollision = checkCollision;

    return ob;
}

float width = 1200.f;
float heith = 800.f;

int checkCollision(SDL_Rect a, SDL_Rect b);

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
    int option_arrow_X = 500;
    int option_arrow_Y = 400;
    bool isAlgo = true;
    srand(time(NULL));

    SDL_Texture *rocket_img = IMG_LoadTexture(renderer, "../assets/rocket.png");
    SDL_Texture *test = IMG_LoadTexture(renderer, "../assets/nederplanet.png");
    
    SDL_Texture *menu_back = IMG_LoadTexture(renderer, "../assets/menu.png");
    SDL_Texture *info_back = IMG_LoadTexture(renderer, "../assets/info.png");
    SDL_Texture *settings_back = IMG_LoadTexture(renderer, "../assets/settings.png");
    TTF_Font *font = TTF_OpenFont("../assets/font1.ttf", 100);
    TTF_Font *font2 = TTF_OpenFont("../assets/font2.ttf", 30);
    TTF_Font *font3 = TTF_OpenFont("../assets/font2.ttf", 20);
    
    if(!test){return -1;}
    if (!font) {return -1;}
    if (!font2) {return -1;}
    if (!font3) {return -1;}
    if(!rocket_img){return -1;}
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
                gameInput(&e, &runing, &poz_X, &poz_Y, &stage);
    
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);
                SDL_Rect rocket_rect = {poz_X, poz_Y, 80, 100};
                Pozitions p;
                Obstacole obs[4];
                p.x = 0;
                p.y = 200;
                p.sx = 200;
                p.sy = p.sx;

                obs[0] = obstacle(test, p.x, p.y, p.sx, p.sy, checkCollision);
                obs[1] = obstacle(test, p.x + 400, p.y, p.sx, p.sy, checkCollision);
                obs[2] = obstacle(test, p.x + 700, p.y, p.sx, p.sy, checkCollision);
                obs[3] = obstacle(test, p.x + 1000, p.y, p.sx, p.sy, checkCollision);
                
                for(int i = 0; i < 4; i++){
                    if(checkCollision(rocket_rect, obs[i].about)){
                        printf("Coliziune\n");
                    }
                    SDL_RenderCopy(renderer, obs[i].texture, NULL, &obs[i].about);
                    
                }
                SDL_RenderCopy(renderer, rocket_img, NULL, &rocket_rect);
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