//
//  text.hpp
//  SDL2_Basics
//
//  Created by Joshua Patino on 1/30/23.
//
#pragma once

#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <string>


class Text {
public:
    Text(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text,const SDL_Color &color);
    
    static SDL_Texture *loadFont(SDL_Renderer *renderer,const std::string &font_path, int font_size,const std::string &message_text,const SDL_Color &color);
    
    void display(int x, int y, SDL_Renderer *renderer) const;
private:
    SDL_Texture *_text_texture = nullptr;
    mutable SDL_Rect _text_rect;
    
    
};
