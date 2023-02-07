//
//  main.cpp
//  2D_Game
//
//  Created by Joshua Patino on 2/3/23.
//

#include <iostream>
#include "Game.hpp"
#include <vector>

Game *game = nullptr; // instance object

int main(int argc, const char * argv[]) {
    // frame rate init
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
    
    game = new Game(); // new game
    game->init("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false); 
    while (game->running() ) {
        frameStart = SDL_GetTicks(); // tick at start of frame
        
        game->pollEvents();
        game->updateGame();
        game -> render();
        
        frameTime = SDL_GetTicks() - frameStart; // tick TTL to process events, updates, render
        
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay-frameTime);
        }
        
    }
    game->memoryManagement(); 
    return 0;
}
