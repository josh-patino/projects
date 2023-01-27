//
//  main.cpp
//  Generating Walk
//
//  Created by Joshua Patino on 1/26/23.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <random>
SDL_Event e;
void input(){
    while(SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT) {
            exit(0);
        }
    }
}

int main(int argc, const char * argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    
    //origin of walk
    int x = 25;
    int y = 25;
    
    //set up the screen
    SDL_CreateWindowAndRenderer(50*20, 50*20, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 20, 20);
   
    
    //random num generator
    std::random_device rd;
    std::uniform_int_distribution<uint8_t> nd(0,4);
    
    while(true) {
        uint8_t direction = nd(rd);
        
        switch (direction) { //land on num 0-4,
            case 0:
                x -= 1;
                y -= 1;
            case 1:
                x += 1;
                y -= 1;
            case 2:
                x += 1;
                y += 1;
            case 3:
                x -= 1;
                y += 1;
                break;
        }
        input();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, x, y);
        SDL_RenderPresent(renderer);
        
        if(x > 50 || x < 0|| y > 50 || y < 0){
            x = 25;
            y = 25;
            
        }
        SDL_Delay(1);
    }
    
    return 0;
}
