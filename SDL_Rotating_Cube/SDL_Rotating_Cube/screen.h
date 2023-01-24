//
//  screen.h
//  SDL_Rotating_Cube
//
//  Created by Joshua Patino on 1/20/23.
//
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>


class Screen {
public:
    //struct for a point(pixel) on the screen
    struct FPoint
    {
        float x;
        float y;

        FPoint(float a, float b)
            : x(a)
            , y(b)
        {}
    };
    //struct for a vec with 3 points
    struct vec3 {
        float x, y,z;
    };
    
    //structure for a connection between 2 points
    struct conn{
        int a;
        int b;
    };
    
    SDL_Event e;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<FPoint> points; //floating point numbers FPOINT
    
    //set up display and size
    Screen(){
        SDL_Init(SDL_INIT_VIDEO);
        SDL_CreateWindowAndRenderer(640, 640, 0, &window, &renderer);
        SDL_RenderSetScale(renderer, 2, 2);
    }
    
    void pixel(float x, float y){
        points.emplace_back(x,y); // creates a new point struct, adds to point vector
    }
    
    //renders the points(color) and displays them in the screen(blk background)
    void show(){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (auto& point : points){
            SDL_RenderDrawPointF(renderer, point.x, point.y);
        }
        
        SDL_RenderPresent(renderer);
    }
    
    void clear(){
        points.clear(); // empty the vector
    }
    //input to exit
    void input(){
        while(SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT) {
                exit(0);
            }
        }
    }
    //rotates the function in a 3d space
    void rotate(vec3& point, float x = 1, float y = 1, float z = 1) {
        float rad = 0;
        
        rad = x;
        point.y = std::cos(rad) * point.y - std::sin(rad) * point.z;
        point.z = std::sin(rad) * point.y + std::cos(rad) * point.z;

        rad = y;
        point.x = std::cos(rad) * point.x + std::sin(rad) * point.z;
        point.z = -std::sin(rad) * point.x + std::cos(rad) * point.z;
        
        rad = z;
        point.x = std::cos(rad) * point.x - std::sin(rad) * point.y;
        point.y = std::sin(rad) * point.x + std::cos(rad) * point.y;


        
    }

    //algo for drawing the line between 2 points
    void line(Screen& screen, float x1, float y1, float x2, float y2){
        
        float dx = x2 - x1;
        float dy = y2 - y1;
        
        float length = std::sqrt(dx*dx + dy*dy);
        float angle = std::atan2(dy, dx); //angle of the length line
        
        //draw the line
        for(int i = 0; i < length; i++){
            screen.pixel(x1 + std::cos(angle) * i, y1 + std::sin(angle) * i);
            
        }
    }
};
