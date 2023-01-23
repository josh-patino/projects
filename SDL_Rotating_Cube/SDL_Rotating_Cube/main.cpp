//
//  main.cpp
//  SDL_Rotating_Cube
//
//  Created by Joshua Patino on 1/20/23.
//

//#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <numeric>
#include "screen.h"


int main(int argc, const char * argv[]) {
    
    Screen screen;
    
    
    std::vector<Screen::vec3> points {
        {100,100,100},
        {200,100,100},
        {200,200,100},
        {100,200,100},
        
        {100,100,200},
        {200,100,200},
        {200,200,200},
        {100,200,200}
    };
    
    //vector of lines connecting the front and back squares
    std::vector<Screen::conn> conns {
        {0,4}, // back  to front connections
        {1,5},
        {2,6},
        {3,7},
        
        {0,1}, // same side connections
        {1,2},
        {2,3},
        {3,0},
        
        {4,5},
        {5,6},
        {6,7},
        {7,4}
    };
    
    //calculate the center
    Screen::vec3 centeroid{0,0,0};
    for(auto& p : points) {
        centeroid.x += p.x;
        centeroid.y += p.y;
        centeroid.z += p.z;
    }
    
    centeroid.x /= points.size();
    centeroid.y /= points.size();
    centeroid.z /= points.size();

    while(true){
        
        for(auto& p : points){
            //point(s) minus center, then rotate and add back
            p.x -= centeroid.x;
            p.y -= centeroid.y;
            p.z -= centeroid.z;
            screen.rotate(p, 0.002, 0.001, 0.004);
            p.x += centeroid.x;
            p.y += centeroid.y;
            p.z += centeroid.z;
            screen.pixel(p.x, p.y);
        }
        
        for(auto& conn : conns) { // connect points vector themselves
            screen.line(screen, points[conn.a].x,
                                points[conn.a].y,
                                points[conn.b].x,
                                points[conn.b].y);
                 
        }
        
        screen.show();
        screen.clear();
        screen.input();
        SDL_Delay(30);
    }
}
