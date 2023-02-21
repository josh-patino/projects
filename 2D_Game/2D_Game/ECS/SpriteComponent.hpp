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
#include "Animation.hpp"
#include <map>


class SpriteComponent : public Component {
private:
    TransformComponent* _transform;
    SDL_Texture* _texture;
    SDL_Rect _sourceRect, _destinationRect;
    
    bool _animated = false;
    int _frames = 0;
    int _speed = 100; //delay between frames in ms
public:
    int animationIndex = 0; // if sprite isnt animated, int y has to be 0
    std::map<const char*, Animation> animations_map;
    
    SpriteComponent() = default;
    SpriteComponent(const char* path){
        setTexture(path);
    }
    
    SpriteComponent(const char* path, bool isAnimated){
        _animated = isAnimated;
        Animation idle = Animation(0,3,100);
        Animation walk = Animation(1,8,100);
        
        animations_map.emplace("Idle", idle);
        animations_map.emplace("Walk", walk);
        
        PlayAnimation("Idle");
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
        
        if (_animated) {
            _sourceRect.x = _sourceRect.w * static_cast<int>((SDL_GetTicks() / _speed) % _frames); // (ms / ms we want to display) % frame[i]
        }
        _sourceRect.y = animationIndex * _transform->height;
        
        _destinationRect.x = static_cast<int>(_transform->position_vector.x);//returns x from positioncomponent
        _destinationRect.y = static_cast<int>(_transform->position_vector.y); // returns y from vector2d
        _destinationRect.w = _transform->width * _transform->scale;
        _destinationRect.h = _transform->height * _transform->scale;
    }
    void draw() override {
        TextureManager::Draw(_texture, _sourceRect, _destinationRect);
    }
    
    void PlayAnimation(const char* animName) {
        _frames = animations_map[animName].frames;
        animationIndex=animations_map[animName].index;
        _speed = animations_map[animName].speed;
    }
};
