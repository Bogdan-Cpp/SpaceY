#include <SDL.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Eroare la inițializarea SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "SpaceY",           
        SDL_WINDOWPOS_CENTERED,           
        SDL_WINDOWPOS_CENTERED,           
        800, 600,                         
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
    int ruleaza = 1;
    float poz_X = 200;
    float poz_Y = 300;

    while (ruleaza) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                ruleaza = 0;
            }
            if(e.key.keysym.sym){
                switch(e.key.keysym.sym){
                    case SDLK_d:
                      poz_X += 100 * 0.5;
                      break;
                    
                    case SDLK_a:
                      poz_X -= 100 * 0.5;
                      break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        //cub
        SDL_Rect cube = {poz_X, poz_Y, 100, 100};
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &cube);
        
        SDL_RenderPresent(renderer);

        SDL_Delay(16); 
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}