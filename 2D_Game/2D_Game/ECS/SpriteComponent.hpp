//
//  SpriteComponent.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/9/23.
//

#pragma once
#include "Components.hpp"
#include <SDL2/SDL.h>
#include "TextureManager.hpp"


class SpriteComponent : public Component {
private:
    TransformComponent* _transform;
    SDL_Texture* _texture;
    SDL_Rect _sourceRect, _destinationRect;
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path){
        setTexture(path);
    }
    
    void setTexture(const char* path) {
        SDL_DestroyTexture(_texture);
        _texture = TextureManager::LoadTexture(path);
    }
    
    void init() override {
        
        _transform = &entity->getComponent<TransformComponent>();
        
        _sourceRect.x  = _sourceRect.y = 0;
        _sourceRect.w = _sourceRect.h = 32;
        
        _destinationRect.w = _destinationRect.h = 64;
        
    }
    
    void update() override {
        _destinationRect.x = (int)_transform->position_vector.x;//returns x from positioncomponent
        _destinationRect.y = (int)_transform->position_vector.y; // returns y from vector2d
    }
    void draw() override {
        TextureManager::Draw(_texture, _sourceRect, _destinationRect);
    }
};
