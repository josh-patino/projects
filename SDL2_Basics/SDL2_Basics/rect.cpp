//
//  rect.cpp
//  SDL2_Basics
//
//  Created by Joshua Patino on 1/27/23.
//

#include "rect.hpp"
#include <SDL2_image/SDL_image.h>
#include <iostream>

Rect::Rect(int w, int h, int x, int y, int r, int g, int b, int a):
_w(w),_h(h),_x(x), _y(y),_r(r),_g(g), _b(b),_a(a){
    
}
Rect::Rect(int w, int h, int x, int y, const std::string &image_path) :
_w(w), _h(h), _x(x),_y(y){
    auto surface = IMG_Load(image_path.c_str());
    if (!surface) {
        std::cerr << "failed to create surface!" << std::endl;
    }
    _texture_world = SDL_CreateTextureFromSurface(Window::renderer, surface);
    SDL_FreeSurface(surface); 
}
Rect::~Rect(){
    SDL_DestroyTexture(_texture_world);
}

void Rect::draw() const {
    SDL_Rect rect = {_x, _y, _w, _h};
    if (_texture_world) { //is loaded
        SDL_RenderCopy(Window::renderer, _texture_world, nullptr, &rect);
    } else{
        SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
        SDL_RenderFillRect(Window::renderer, &rect);
    }
    
}

void Rect::pollEvents(SDL_Event &event){
    
    if (event.type == SDL_KEYDOWN) {
        switch(event.key.keysym.sym){
            case SDLK_LEFT:
                _x -= 10;
                break;
            case SDLK_RIGHT:
                _x += 10;
                break;
            case SDLK_UP:
                _y -= 10;
                break;
            case SDLK_DOWN:
                _y += 10;
                break;
                
        }
    }
}

