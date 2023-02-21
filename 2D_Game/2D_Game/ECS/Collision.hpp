//
//  Collision.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/10/23.
//

#pragma once
#include <SDL2/SDL.h>

class ColliderComponent;

class Collision
{
public:
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);  //Axis Aligned Bounding Box, true collision or false
    static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
};
    //To check for collisions:
    
//    if
//    (rectA.x + rectA.w) ≥ rectB.x &&
//    (rectB.x + rectB.w) ≥ rectA.x &&
//    (rectA.y+rectA.h) ≥ rectB.y &&
//    (rectB.y + rectB.h) ≥ rectA.y
//    If all are true, we have a collision
