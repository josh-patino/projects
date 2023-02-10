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
    ~SpriteComponent() {
        SDL_DestroyTexture(_texture);
    }
    
    void setTexture(const char* path) {
        //SDL_DestroyTexture(_texture);
        _texture = TextureManager::LoadTexture(path);
    }
    
    void init() override {
        
        _transform = &entity->getComponent<TransformComponent>();
        
        _sourceRect.x  = _sourceRect.y = 0;
        _sourceRect.w = _transform->width;
        _sourceRect.h = _transform->height;
        
    }
    
    void update() override {
        _destinationRect.x = static_cast<int>(_transform->position_vector.x);//returns x from positioncomponent
        _destinationRect.y = static_cast<int>(_transform->position_vector.y); // returns y from vector2d
        _destinationRect.w = _transform->width * _transform->scale;
        _destinationRect.h = _transform->height * _transform->scale;
    }
    void draw() override {
        TextureManager::Draw(_texture, _sourceRect, _destinationRect);
    }
};
