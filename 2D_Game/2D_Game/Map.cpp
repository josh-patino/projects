//
//  Map.cpp
//  2D_Game
//
//  Created by Joshua Patino on 2/7/23.
//

#include "Map.hpp"
#include "Game.hpp"
#include <fstream>


Map::Map(){
}

Map::~Map(){ //destroy textures render

}

void Map::LoadMap(std::string path, int sizeX, int sizeY){//traverse the map
    char tile;
    std::fstream mapFile;
    mapFile.open(path);
    
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            mapFile.get(tile);
            Game::addTile(atoi(&tile), x * 32, y * 32);
            mapFile.ignore();
        }
    }
    mapFile.close();
}


