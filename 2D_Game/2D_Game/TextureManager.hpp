//
//  TextureManager.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/6/23.
//

#include <stdio.h>
#pragma once
#include "Game.hpp"

class TextureManager{
public:
    static SDL_Texture* LoadTexture(const char* fileName); 
};