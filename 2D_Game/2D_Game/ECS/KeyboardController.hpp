//
//  KeyboardController.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/9/23.
//
#pragma once
#include "Game.hpp"
#include "Components.hpp"
#include "EntityComponentSystem.hpp"
#include "SpriteComponent.hpp"


class KeyboardController : public Component {
public:
    TransformComponent* transform;
    SpriteComponent* sprite;
    void init() override {
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }
    
    void update() override { // keyboard events
        if (Game::event.type == SDL_KEYDOWN) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity_vector.y = -1;
                    sprite->PlayAnimation("Walk");
                    break;
                case SDLK_a:
                    transform->velocity_vector.x = -1;
                    sprite->PlayAnimation("Walk");
                    break;
                case SDLK_d:
                    transform->velocity_vector.x = 1;
                    sprite->PlayAnimation("Walk");
                    break;
                case SDLK_s:
                    transform->velocity_vector.y = 1;
                    sprite->PlayAnimation("Walk");
                    break;
                default:
                    break;
            }
        }
        
        if (Game::event.type == SDL_KEYUP) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity_vector.y = 0;
                    sprite->PlayAnimation("Idle");
                    break;
                case SDLK_a:
                    transform->velocity_vector.x = 0;
                    sprite->PlayAnimation("Idle");
                    break;
                case SDLK_d:
                    transform->velocity_vector.x = 0;
                    sprite->PlayAnimation("Idle");
                    break;
                case SDLK_s:
                    transform->velocity_vector.y = 0;
                    sprite->PlayAnimation("Idle");
                    break;
                default:
                    break;
            }
        }
    }
    
};
