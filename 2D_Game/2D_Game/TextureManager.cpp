//
//  TextureManager.cpp
//  2D_Game
//
//  Created by Joshua Patino on 2/6/23.
//

#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* fileName){
    SDL_Surface* tempSurface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    
    return texture; 
}
