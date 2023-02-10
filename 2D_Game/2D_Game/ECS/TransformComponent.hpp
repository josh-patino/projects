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
    
    int height = 32;
    int width = 32;
    int scale = 1;
    int speed = 3;
    
    TransformComponent(int sc) {
        position_vector.Zero();
        scale = sc; 
    }
    
    TransformComponent(){
        position_vector.Zero();
    }
    
    TransformComponent(float x, float y) {
        position_vector.Zero();
    }
    
    TransformComponent(float x, float y, int h, int w, int sc) {
        position_vector.x = x;
        position_vector.y = y;
        height = h;
        width = w;
        scale = sc; 
    }
    
    void init() override {
        velocity_vector.Zero(); 
    }
    
    void update() override {
        position_vector.x += velocity_vector.x * speed;
        position_vector.y += velocity_vector.y * speed;
    }
   
};
