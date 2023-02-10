//
//  Collision.cpp
//  2D_Game
//
//  Created by Joshua Patino on 2/10/23.
//

#include "Collision.hpp"

bool Collision::AABB(const SDL_Rect &rectA, SDL_Rect &rectB){
    if (
        rectA.x + rectA.w >= rectB.x &&
        rectB.x + rectB.w >= rectA.x &&
        rectA.y + rectA.h >= rectB.y &&
        rectB.y + rectB.h >= rectA.y
        ) {
            return true; //collision
    }
    return false; //no collision
}
