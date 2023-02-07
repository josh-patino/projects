//
//  window.h
//  SDL2_Basics
//
//  Created by Joshua Patino on 1/27/23.
//
#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class Window{
public: //anything can use these
    Window(const std::string &title, int width, int height);
    ~Window();
    void pollEvents(SDL_Event &event);
    inline bool isClosed() const {return _close;} // inline cheap lambda
    void clear() const;
    
private: // only the class can use these
    bool init();
private:
    SDL_Event event;
    std::string _title;
    int _width = 800;
    int _height = 600;
    bool _close = false;
    SDL_Window* _window = nullptr;
protected: // class, and any that inherit the class can use this
public:
    static SDL_Renderer* renderer;
    
};

