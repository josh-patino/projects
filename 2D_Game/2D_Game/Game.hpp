//
//  Game.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/3/23.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <SDL2_image/SDL_image.h>
#include "TextureManager.hpp"
#include <vector>

class ColliderComponent;


class Game {
public:
    Game();
    ~Game();
    void init(const std::string& title, int xposition, int yposition, int width, int height, bool fullscreen);
    void pollEvents();
    void updateGame();
    void render();
    void memoryManagement();
    inline bool running() {return _isRunning; }
    
    static void addTile(int id, int x, int y); 
    static SDL_Renderer* renderer;
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;
    
private:
    int _gameCounter; 
    bool _isRunning;
    SDL_Window* _window;
};


#endif /* Game_hpp */
