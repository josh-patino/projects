//
//  Map.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/7/23.
//

#pragma once
#include <string>

class Map
{
public:
     
    Map(std::string tID, int ms, int ts);
    ~Map();

    void LoadMap(std::string path, int sizeX, int sizeY);
    void AddTile(int srcX, int srcY, int xpos, int ypos);

private:
    std::string texID;
    int mapScale;
    int tileSize;
    int scaledSize;

};
