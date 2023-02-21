//
//  TileComponent.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/14/23.
//
#pragma once

#include "EntityComponentSystem.hpp"
#include "Vector2D.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"


class TileComponent : public Component
{
public:

    TransformComponent* transform;
    SpriteComponent* sprite;
    
    const char* path;
    SDL_Rect tileRect;
    int tileID;
    
    TileComponent() = default;
    
    TileComponent(int xpos, int ypos, int width, int height, int id) {
        tileRect.x = xpos;
        tileRect.y = ypos;
        tileRect.w = width;
        tileRect.h = height;
        tileID = id;
        
        switch (tileID) {
            case 0:
                path = "/Users/joshuapatino/Desktop/projects/projects/Resources/water.png";
                break;
            case 1:
                path = "/Users/joshuapatino/Desktop/projects/projects/Resources/dirt.png";
                break;
            case 2:
                path = "/Users/joshuapatino/Desktop/projects/projects/Resources/grass.png";
            default:
                break;
        }
    }
    void init() override {
        entity->addComponent<TransformComponent>((float)tileRect.x,(float)tileRect.y,tileRect.w,tileRect.h,1);
        transform = &entity->getComponent<TransformComponent>();
        
        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
        
        
    }
};






//_dirt = TextureManager::LoadTexture("/Users/joshuapatino/Desktop/projects/projects/Resources/dirt.png"); //2
//_grass = TextureManager::LoadTexture("/Users/joshuapatino/Desktop/projects/projects/Resources/grass.png"); //1
//_water = TextureManager::LoadTexture("/Users/joshuapatino/Desktop/projects/projects/Resources/water.png"); //0
