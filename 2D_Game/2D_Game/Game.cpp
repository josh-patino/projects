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
#include "Collision.hpp"
#include "AudioComponent.hpp"
#include "TileComponent.hpp"
#include "KeyboardController.hpp"

//current possible game objects

Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Manager manager;

std::vector<ColliderComponent*> Game::colliders; 

auto& wall(manager.addEntity());
auto& powerup(manager.addEntity());
auto& player(manager.addEntity());
auto& mix_player(manager.addEntity());

enum groupLabels : std::size_t {
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders,
    groupPowerUps
};

//sounds
AudioComponent audio;
//music
//int music_1 =
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
    //Entity Componenet System Implemnation
    Map::LoadMap("/Users/joshuapatino/Desktop/projects/projects/Resources/p16x16.txt", 16, 16);
    //tile component

    //player entity
    player.addComponent<TransformComponent>(2);
    std::cout<<"Player is at 100,100" << std::endl;
    player.addComponent<SpriteComponent>("/Users/joshuapatino/Downloads/jSIxQuW_.png", true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);

    //walls entitty
    wall.addComponent<TransformComponent>(320.0f,320.0f, 32, 32, 1);
    wall.addComponent<SpriteComponent>("/Users/joshuapatino/Desktop/projects/projects/Resources/dirt.png");
    wall.addComponent<ColliderComponent>("wall");
    wall.addGroup(groupMap);
    
    //power up entity
//    powerup.addComponent<TransformComponent>(600.0f,600.0f, 32,32,1);
//    powerup.addComponent<SpriteComponent>("/Users/joshuapatino/Desktop/projects/projects/Resources/dirt.png");
//    powerup.addComponent<ColliderComponent>("power_up");
    
    //audio
    audio.LoadMusic("music", "/Users/joshuapatino/Desktop/projects/projects/Sounds_Songs/Level1.mp3");
    audio.LoadEffect("wall_collision", "/Users/joshuapatino/Desktop/projects/projects/Sounds_Songs/smw_pipe.wav");
    audio.LoadEffect("power_up", "/Users/joshuapatino/Desktop/projects/projects/Sounds_Songs/smw_power-up.wav");
    audio.PlayMusic("music");
    
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
    
    //power up
//    if (Collision::AABB(player.getComponent<ColliderComponent>().boxCollider, powerup.getComponent<ColliderComponent>().boxCollider)) {
//        audio.PlayEffect("power_up");
//        //ssSDL_Delay(300);
//    }
    
    
    //wall
    for (auto cc: colliders) {
        Collision::AABB(player.getComponent<ColliderComponent>(),*cc);
        }
}

//    audio.PlayEffect("wall_collision");
//    SDL_Delay(300);
//    player.getComponent<TransformComponent>().velocity_vector * -1;
//    std::cout << "player hit the wall" << std::endl;
//    //player.destroy();
//    //SDL_Quit();
    
    // if player coord greater than 100, .setTex \
    //for dying animation?
    //player.getComponent<TransformComponent>().position_vector.Add(Vector2D(5,0));
//    if (player.getComponent<TransformComponent>().position_vector.x > 100 ) {
//        std::cout << "Player is greater than 100";
//    }
    

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));



void Game::render(){
    SDL_RenderClear(renderer);
    //render stuff
    //painters algorithm, render/paint the back most element first, until getting to the player
    //map->DrawMap();
    for ( auto& t : tiles) {
        t->draw();
    }
    for ( auto& p : players) {
        p->draw();
    }
    for ( auto& e : enemies) {
        e->draw();
    }
    //manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::memoryManagement(){
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    //audio.Clean();
    std::cout << "scuesfully shut down, thanks for playing!"<<std::endl;
}

void Game::addTile(int id, int x, int y){
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(x,y, 32,32,id);
    tile.addGroup(groupMap);
    
}
