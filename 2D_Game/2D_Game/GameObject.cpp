//
//  GameObject.cpp
//  2D_Game
//
//  Created by Joshua Patino on 2/6/23.
//

#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet, int x, int y) {
    _objectTexture = TextureManager::LoadTexture(textureSheet);
    _gameObjXposition = x;
    _gameObjYposition = y;
    
}

void GameObject::Update(){//movement and behavior
    _gameObjXposition++;
    _gameObjYposition++; 
    
    _sourceRect.h = 32;
    _sourceRect.w = 32;
    _sourceRect.x = 0;
    _sourceRect.y = 0;
    
    _destinationRect.x = _gameObjXposition;
    _destinationRect.y = _gameObjYposition;
    _destinationRect.w = _sourceRect.w * 2;
    _destinationRect.h = _sourceRect.h * 2;
}

void GameObject::Render() { // render for game objects
    SDL_RenderCopy(Game::renderer, _objectTexture, &_sourceRect, &_destinationRect);
}
