//
//  Animation.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/17/23.
//

#pragma once

struct Animation {
    int index;
    int speed;
    int frames;
    
    Animation() {}
    Animation(int i, int s, int f) {
        index = i;
        frames = f;
        speed = s;
    }
};
