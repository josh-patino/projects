//
//  Game.cpp
//  2D_Game
//
//  Created by Joshua Patino on 2/3/23.
//

#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"

//current possible game objects

Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Manager manager;
auto& player(manager.addEntity());

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
    
    map = new Map();
    //ecs
    player.addComponent<TransformComponent>();
    std::cout<<"Player is at 100,100" << std::endl;
    player.addComponent<SpriteComponent>("/Users/joshuapatino/Desktop/projects/projects/Resources/mario.png");
    player.addComponent<KeyboardController>();
    
}
void Game::pollEvents(){
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            _isRunning = false;
            break;
            
        default:
            break;
    }
}

void Game::updateGame(){
    manager.refresh();//7
    manager.update(); //7
    
    
    // if player coord greater than 100, .setTex \
    //for dying animation?
    //player.getComponent<TransformComponent>().position_vector.Add(Vector2D(5,0));
//    if (player.getComponent<TransformComponent>().position_vector.x > 100 ) {
//        std::cout << "Player is greater than 100";
//    }
    
}

void Game::render(){
    SDL_RenderClear(renderer);
    //render stuff
    //painters algorithm, render/paint the back most element first, until getting to the player
    map->DrawMap();
    manager.draw(); 
    SDL_RenderPresent(renderer);
}

void Game::memoryManagement(){
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "scuesfully shut down, thanks for playing!"<<std::endl;
}


