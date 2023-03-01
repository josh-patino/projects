//
//  Game.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/3/23.
//

#pragma once

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <vector>

class AssetManager;
class ColliderComponent;

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    bool running() { return isRunning; }
    void render();
    void clean();

    static SDL_Renderer *renderer;
    static SDL_Event event;
    static bool isRunning;
    static SDL_Rect camera;
    static AssetManager* assets;
    enum groupLabels : std::size_t
    {
        groupMap,
        groupPlayers,
        groupColliders,
        groupProjectiles
    };

private:

    int cnt = 0;
    SDL_Window *window;
};
