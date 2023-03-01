//
//  Animation.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/17/23.
//
#pragma once

struct Animation
{

    int index;
    int frames;
    int speed;

    Animation() {}
    Animation(int i, int f, int s)
    {
        index = i;
        frames = f;
        speed = s;
    }

};
