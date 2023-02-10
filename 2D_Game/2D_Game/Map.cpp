//
//  Map.cpp
//  2D_Game
//
//  Created by Joshua Patino on 2/7/23.
//

#include "Map.hpp"
#include "TextureManager.hpp"


std::vector<std::vector<int>> level_1 = {
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,2,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,2,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,2,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,2,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map(){
    _dirt = TextureManager::LoadTexture("/Users/joshuapatino/Desktop/projects/projects/Resources/dirt.png"); //2
    _grass = TextureManager::LoadTexture("/Users/joshuapatino/Desktop/projects/projects/Resources/grass.png"); //1
    _water = TextureManager::LoadTexture("/Users/joshuapatino/Desktop/projects/projects/Resources/water.png"); //0
    
    LoadMap(level_1);
    
    //source defaults, change when we draw
    _sourceMap.x = _sourceMap.y = 0;
    _destinationMap.x = _destinationMap.y = 0;
    // src des width height default
    _sourceMap.w = _destinationMap.w = 32;
    _sourceMap.h = _destinationMap.h = 32;
    
}

Map::~Map(){ //destroy textures render
    SDL_DestroyTexture(_dirt);
    SDL_DestroyTexture(_water);
    SDL_DestroyTexture(_grass);

}

void Map::LoadMap(std::vector<std::vector<int>> vectorMap){//traverse the map 
    for (int row = 0; row < 20; row++) {
        for(int column = 0; column < 25; column++){
            _vector_map[row][column] = vectorMap[row][column];
        }
    }
}

void Map::DrawMap(){
    int blockType = 0;
    
    for (int row = 0; row < 20; row++) {
        for(int column = 0; column < 25; column++){
            blockType = _vector_map[row][column];
            //where on the screen the block 32x32 is drawn
            _destinationMap.x = column * 32;
            _destinationMap.y = row * 32;
            switch (blockType) {
                case 0:
                    TextureManager::Draw(_water, _sourceMap, _destinationMap);
                    break;
                case 1:
                    TextureManager::Draw(_grass, _sourceMap, _destinationMap);
                    break;
                case 2:
                    TextureManager::Draw(_dirt, _sourceMap, _destinationMap);
                default:
                    break;
            }
        }
    }
}
