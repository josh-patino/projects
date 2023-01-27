//
//  main.cpp
//  Snake
//
//  Created by Joshua Patino on 1/26/23.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <algorithm>
#include <deque>
#include <vector>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>



int main(int argc, const char * argv[]) {
    //init
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);
    int init2 = Mix_Init(0);
    
    //window
    auto window = SDL_CreateWindow("Simple Snake Game",
                                   SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
    auto renderer = SDL_CreateRenderer(window, -1, 0);
    
    //text
    TTF_Font* font = TTF_OpenFont("/Users/joshuapatino/Desktop/projects/projects/Resources/Acme-Regular.ttf", 50);
    SDL_Surface* textSurf = TTF_RenderText_Solid(font, "Game Over", {255,255,255});
    SDL_Texture * textTexture = SDL_CreateTextureFromSurface(renderer, textSurf);
    
    SDL_Rect textRect = {275,375,textSurf->w,textSurf->h};
    SDL_FreeSurface(textSurf);
    TTF_CloseFont(font);
    
    SDL_Event e;
    
    //audio set up
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music* music = Mix_LoadMUS("/Users/joshuapatino/Desktop/projects/projects/Sounds_Songs/8_bit_select.wav");
    if (!music) {
        std::cout<< SDL_GetError() << std::endl;
    }
    Mix_Chunk* eating_sound = Mix_LoadWAV("/Users/joshuapatino/Desktop/projects/projects/Sounds_Songs/eating_se.wav");
    Mix_Chunk* dying_sound = Mix_LoadWAV("/Users/joshuapatino/Desktop/projects/projects/Sounds_Songs/retro_gameover_se.wav");
    Mix_PlayMusic(music, -1); //-1 loop infinitely
    
    //screen border coords
    const int MIN = 0;
    const int MAX = 800;
    
    enum Direction{
        DOWN, LEFT, RIGHT, UP
    };
    
    bool playing = true;
    int dir = 0;
    
    //head
    SDL_Rect head {400,400,10,10}; //x ,y origin, 10,10 size
    
    //body container
    std::deque<SDL_Rect> rq;
    unsigned int size = 1;
    //apple container
    std::vector<SDL_Rect> apples;
    
    // creation of apples
    for (int i = 0; i < 150; i++) {
        
        apples.push_back({rand()%80*10, rand()%80*10,10,10}); // push back ({})
    }
    
    while (playing) {
        //check input
        while (SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT){playing = false;}
            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_DOWN) { dir = DOWN; }
                if (e.key.keysym.sym == SDLK_UP) { dir = UP; }
                if (e.key.keysym.sym == SDLK_LEFT) { dir = LEFT; }
                if (e.key.keysym.sym == SDLK_RIGHT) { dir = RIGHT; }
            }
            
        }
        //move
        switch (dir) {
            case DOWN:
                head.y += 10;
                break;
            case UP:
                head.y -= 10;
                break;
            case LEFT:
                head.x -= 10;
                break;
            case RIGHT:
                head.x += 10;
                break;
        }
        std::cout << "X: " << head.x << " Y: " << head.y<<std::endl;
        //Out of Bounds
        if (head.x >= MAX || head.x <= MIN || head.y >= MAX || head.y <= MIN) {
            std::cout << "you died" << std::endl;
            Mix_PlayChannel(-1, dying_sound, 0);
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
            SDL_RenderPresent(renderer);
            SDL_Delay(3000);
            exit(0);
        }
        
        //collison detect, apple and snake head
        std::for_each(apples.begin(), apples.end(), [&](auto& apple){
            if (head.x == apple.x && head.y == apple.y) {
                size+= 10;
                apple.x = -10;
                apple.y = -10;
                Mix_PlayChannel(-1, eating_sound, 0);
            }
        });
        //collison detect, snake and itself
        std::for_each(rq.begin(), rq.end(), [&](auto& snake_segment){
            if (head.x == snake_segment.x && head.y == snake_segment.y) {
                size = 1;
                //SDL_BlitSurface(textSurf, NULL, window, NULL);
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                SDL_RenderPresent(renderer);
                Mix_PlayChannel(-1, dying_sound, 0);
                SDL_Delay(3000);
                exit(0);
                
            }
        });
        
        //add newest head to the snake
        rq.push_front(head);
        while (rq.size() > size) {
            rq.pop_back();
        }
        
        //clear window
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        //draw body
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        std::for_each(rq.begin(), rq.end(), [&](auto& snake_segment) {
            SDL_RenderFillRect(renderer, &snake_segment);
        });
        //SDL_RenderFillRect(renderer, &head);
        
        //draw apples
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        std::for_each(apples.begin(), apples.end(), [&](auto& apple){
            SDL_RenderFillRect(renderer, &apple); 
        });
        
        //display
        SDL_RenderPresent(renderer);
        SDL_Delay(25);
        
    }
    
    
}
