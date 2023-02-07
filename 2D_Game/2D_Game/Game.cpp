//
//  Game.cpp
//  2D_Game
//
//  Created by Joshua Patino on 2/3/23.
//

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

GameObject* player;
GameObject* enemy;
SDL_Renderer* Game::renderer = nullptr; 

Game::Game(){
    
}

Game::~Game(){
    
}
void Game::init(const std::string& title, int xposition, int yposition, int width, int height, bool fullscreen){
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL library initilized" <<std::endl;
        _window = SDL_CreateWindow(title.c_str(), xposition, yposition, width, height, flags);
        if (_window) {
            std::cout<< "window loaded" <<std::endl;
        } else{
            std::cerr << "window was not created" <<std::endl;
        }
        renderer = SDL_CreateRenderer(_window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //white background
            std::cout <<"renderer loaded" << std::endl;
        }
        _isRunning = true;
    } else {
        _isRunning = false; 
        std::cerr << "SDL Library did NOT initilize!!" << std::endl;
    }
    
    player = new GameObject("/Users/joshuapatino/Downloads/mario.png",50,50);
    enemy = new GameObject("/Users/joshuapatino/Downloads/goomba.png",0,0);
    
    
}
void Game::pollEvents(){
    SDL_PollEvent(&_event);
    switch (_event.type) {
        case SDL_QUIT:
            _isRunning = false;
            break;
            
        default:
            break;
    }
}

void Game::updateGame(){
    player->Update();
    enemy->Update();
}

void Game::render(){
    SDL_RenderClear(renderer);
    //render stuff
    //painters algorithm, render/paint the back most element first, until getting to the player
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::memoryManagement(){
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "scuesfully shut down, thanks for playing!"<<std::endl;
}


