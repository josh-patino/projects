//
//  main.cpp
//  SDL2_Basics
//
//  Created by Joshua Patino on 1/27/23.
//

#include <iostream>
#include "window.h"
#include "rect.hpp"
#include "text.hpp"
#include <string> 

void pollEvents(Window &window, Rect &rect){
    SDL_Event event;
    
    if (SDL_PollEvent(&event)) {
        rect.pollEvents(event);
        window.pollEvents(event); 
    }
}

int main(int argc, const char * argv[]) {
    Window window("SDL_Tutorial", 800,600);
    Rect rect(120,120,100,100, "/Users/joshuapatino/Downloads/tennis_ball.png");
    Text text(Window::renderer,"/System/Library/Fonts/Supplemental/Georgia.ttf",50,"Rendering_Text", {255,0,0,255}); 
    //Text(Window::renderer, "", 30, "Rendering", {255,0,0,255});
    while (!window.isClosed()) {
        pollEvents(window, rect); 
        rect.draw();
        window.clear();
        text.display(20, 20, Window::renderer);
    }
    return 0;
}
