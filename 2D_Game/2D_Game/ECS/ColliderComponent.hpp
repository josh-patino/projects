//
//  ColliderComponent.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/10/23.
//

#pragma once
#include <string>
#include <SDL2/SDL.h>
#include "Components.hpp"
#include "TextureManager.hpp"

class ColliderComponent : public Component {
public:
    SDL_Rect boxCollider;
    std::string entityTag;
    
    TransformComponent* transform;
    
    ColliderComponent(std::string t) {
        entityTag = t; 
    }
    
    void init() override {
        if(!entity->hasComponent<TransformComponent>()) { // component check, add to over components
            entity->addComponent<TransformComponent>();
            
        }
        transform = &entity->getComponent<TransformComponent>();
        Game::colliders.push_back(this); 
    }
    
    void update() override { //collider box == the player box 
        boxCollider.x = static_cast<int> (transform->position_vector.x);
        boxCollider.y = static_cast<int> (transform->position_vector.y);
        boxCollider.w = transform->width * transform->scale;
        boxCollider.h = transform-> height * transform->scale;
     }
};
