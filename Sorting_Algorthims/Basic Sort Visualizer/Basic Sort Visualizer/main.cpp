//
//  main.cpp
//  Basic Sort Visualizer
//
//  Created by Joshua Patino on 1/23/23.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <random>
#include <ranges>
#include <algorithm>
#include <SDL2_mixer/SDL_mixer.h>
SDL_Event e;
int intit2 = Mix_Init(0);


void input(){
    while(SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT) {
            exit(0);
        }
    }
}



//get vec, render each state of the iterator in the loop.
//hence passing a whole renderer pointer
void draw_state(std::vector<int>& v, SDL_Renderer* renderer, unsigned int red, unsigned int blue) {
    int index = 0;
    //loop and draw each element in v (random list vector)
    for (int i : v) {
        if (index == red) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        } else if (index == blue){
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        SDL_RenderDrawLine(renderer, index, 99, index, i);
        index += 1; // move right after every iteration and draw the next line
    }
}

int main(int argc, const char * argv[]) {
    
    //sounds
    //           frequency, default format, (mono 1 stereo 2, chunksize(normal 1024))
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Chunk* airSound = Mix_LoadWAV("/Users/joshuapatino/Desktop/projects/projects/Sorting_Algorthims/Sounds/dot_se.wav");
    if(!airSound) {
        std::cout << "Error: " << Mix_GetError() << std::endl;
    }
    
    std::random_device rd; //seed for rand generator
    std::uniform_int_distribution d(1,99); //random numbers 1 - 99
    std::vector<int> randList;
    
    //populate vector with random numbers
    for (int i = 0; i < 99; i++) {
        randList.push_back(d(rd));
    }
    
    //SDL Window
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(100*6, 100*6, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 6, 6);
    

    
    
    //Basic sort algo
    for (unsigned int i = 0; i < randList.size(); i++) {
        for (unsigned int j = i; j < randList.size(); j++) {
            if(randList[j] < randList[i]){
                std::swap(randList[j], randList[i]);
                
            }
            //clear screen
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            input();
            //draw current state (i) of the sort
            draw_state(randList, renderer, i, j);
            //show to window and delay 10 ms
            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
        Mix_PlayChannel(-1, airSound, 0);
    }
    
    for( int i : randList){
        std::cout << i << std::endl;
    }
    
    return 0;
}
