//
//  window.cpp
//  SDL2_Basics
//
//  Created by Joshua Patino on 1/27/23.
//

#include "window.h"
#include <iostream>
#include <SDL2_ttf/SDL_ttf.h>

SDL_Renderer*  Window::renderer = nullptr;

// scope resolution operator, class window constructor
Window::Window(const std::string &title, int width, int height):
_title(title), _width(width), _height(height){
    if (!init()) {
        _close = !init();
    }
}

Window::~Window(){ //destructor
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
    TTF_Quit();
}

bool Window::init(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr<<"Failed to initlize SDL" <<std::endl;
        return false;
    }
    //SDL_image init
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        std::cerr << "SDL IMG failed to initilize" <<std::endl;
        return false;
    }
    
    //SDL TTF init
    if (TTF_Init() == -1) {
        std::cerr << "Failed to initilize SDL TTF" << std::endl;
    }
    
    //window init
    _window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);
    if(_window == nullptr){
        std::cerr<<"Failed to create window" << std::endl; // cerr: cout for errors
        return false;
    }
    //renderer init acc vsync cap at 60 FPS
    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr<< "failed to render" << std::endl;
        return false;
    }
    
    return true; 
}

void Window::pollEvents(SDL_Event &event){
    switch (event.type) {
        case SDL_QUIT: // x button on window
            _close = true;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    _close = true;
                    break;
            }
//            case SDL_MOUSEMOTION:
//                std::cout << event.motion.x << " " << event.motion.y << std::endl;
//                break;
        case SDL_MOUSEBUTTONDOWN:
            std::cout << "you clicked ur mouse";
    }
}

void Window::clear() const{
    SDL_RenderPresent(renderer); // colored render on screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //sets color of render
    SDL_RenderClear(renderer); // gets color on render
    //SDL_RenderPresent(_renderer); // colored render on screen
}


