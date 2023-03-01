//
//  Collision.cpp
//  2D_Game
//
//  Created by Joshua Patino on 2/10/23.
//

#include "Collision.hpp"
#include "ColliderComponent.hpp"

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB)
{
    if (
        recA.x + recA.w >= recB.x &&
        recB.x + recB.w >= recA.x &&
        recA.y + recA.h >= recB.y &&
        recB.y + recB.h >= recA.y
        )
    {
        return true;
    }

    return false;
}

bool Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB)
{
    if (AABB(colA.collider, colB.collider))
    {
        //std::cout << colA.tag << " hit: " << colB.tag << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}
