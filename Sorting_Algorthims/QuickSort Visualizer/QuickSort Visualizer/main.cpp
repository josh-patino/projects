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
#include "screen.h"
#include <SDL2_ttf/SDL_ttf.h>

int Partition(std::vector<int> &v, int start, int end);
void Quicksort(std::vector<int> &v, int start, int end );
void PrintVector(std::vector<int> v);
Screen screen;
int intit2 = Mix_Init(0);
int intit3 = TTF_Init(); 



int main(int argc, const char * argv[]) {
    // num generator
    std::random_device rd; //seed for rand generator
    std::uniform_int_distribution d(1,500); //random numbers 1 - 99
    std::vector<int> v;
    
    
    //populate vector with random numbers
    for (int i = 0; i < 500; i++) {
        v.push_back(d(rd));
    }
    screen.ScreenSetUp();
    
    std::cout<<"Vector Before Sorting: "<<std:: endl;
    PrintVector(v);
    Quicksort(v,0,v.size() - 1);
    std::cout<<"Vector After Sorting: "<<std::endl;
    PrintVector(v);
    
    return 0;
}

int Partition(std::vector<int> &v, int start, int end){
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Chunk* arcade_se = Mix_LoadWAV("/Users/joshuapatino/Desktop/projects/projects/Sorting_Algorthims/Sounds/dot_se.wav");
    if(!arcade_se) {
        std::cout << "Error: " << Mix_GetError() << std::endl;
    }
    int pivot = end;
    int j = start;
    for(int i = start; i < end; ++i){
        if(v[i] < v[pivot]){
            std::swap(v[i], v[j]);
            ++j;
            screen.updateFrame(v, i, j);
        }
        //Mix_PlayChannel(-1, arcade_se, 0);
    }
    Mix_PlayChannel(-1, arcade_se, 0);
    std::swap(v[j], v[pivot]);
    return j;
}

void Quicksort(std::vector<int> &v, int start, int end ){

    if(start<end){
        int p = Partition(v,start,end);
        Quicksort(v,start,p-1);
        Quicksort(v,p+1,end);
    }
    
}

void PrintVector(std::vector<int> v){
    for(int i=0;i<v.size();++i)
        std::cout<<v[i]<<" ";
    std::cout<<"\n\n";
}
