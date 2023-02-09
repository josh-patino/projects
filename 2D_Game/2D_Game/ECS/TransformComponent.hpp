//
//  PositionComponent.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/9/23.
//

#pragma once
#include "EntityComponentSystem.hpp"
#include "Vector2D.hpp"

class TransformComponent : public Component {
public:
    
    Vector2D position_vector;
    Vector2D velocity_vector;
    
    int speed = 3;
    
    TransformComponent(){
        position_vector.x = 0.0f;
        position_vector.y = 0.0f;
    }
    
    TransformComponent(float x, float y) {
        position_vector.x = x;
        position_vector.y = y;
    }
    
    void init() override {
        velocity_vector.x = 0;
        velocity_vector.y = 0;
    }
    
    void update() override {
        position_vector.x += velocity_vector.x * speed;
        position_vector.y += velocity_vector.y * speed; 
    }
   
};
