//
//  GameObject.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/6/23.
//

#include "Game.hpp"

class GameObject {
public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject();
    void Update();
    void Render(); 
    
private:
    int _gameObjYposition;
    int _gameObjXposition;
    SDL_Texture* _objectTexture;
    SDL_Rect _sourceRect, _destinationRect;
   
};
