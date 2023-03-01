//
//  AssetManager.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/28/23.
//

#pragma once

#include <map>
#include <string>
#include "TextureManager.hpp"
#include "Vector2D.hpp"
#include "EntityComponentSystem.hpp"
#include <SDL2_ttf/SDL_ttf.h>

class AssetManager
{
public:
    AssetManager(Manager* man);
    ~AssetManager();

    //gameobjects

    void CreateProjectile(Vector2D pos, Vector2D vel, int range, int speed, std::string id);

    //texture management
    void AddTexture(std::string id, const char* path);
    SDL_Texture* GetTexture(std::string id);

    void AddFont(std::string id, std::string path, int fontSize);
    TTF_Font* GetFont(std::string id);

private:

    Manager* manager;
    std::map<std::string, SDL_Texture*> textures;
    std::map<std::string, TTF_Font*> fonts;
};
