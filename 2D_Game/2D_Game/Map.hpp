//
//  Map.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/7/23.
//

#pragma once
#include <string>

class Map{
public:
    Map();
    ~Map();
    
   static void LoadMap(std::string path, int sizeX, int sizeY);
private:

};
