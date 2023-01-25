//
//  screen.h
//  Basic Sort Visualizer
//
//  Created by Joshua Patino on 1/25/23.
//

SDL_Event e;
SDL_Window* window;
SDL_Renderer* renderer;



class Screen {
public:
    //get vec, render each state of the iterator in the loop.
    //hence passing a whole renderer pointer
    void draw_state(std::vector<int>& v, SDL_Renderer* renderer, unsigned int green, unsigned int blue) {
        int index = 0;
        //loop and draw each element in v (random list vector)
        for (int i : v) {
            if (index == green) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            } else if (index == blue){
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
            SDL_RenderDrawLine(renderer, index, 500, index, i);
            index += 1; // move right after every iteration and draw the next line
        }
    }
    
    void input(){
        while(SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT) {
                exit(0);
            }
        }
    }
    
    void ScreenSetUp(){
        //SDL Window
        SDL_Init(SDL_INIT_VIDEO);//1000/1000, 2 - 2
        SDL_CreateWindowAndRenderer(1000, 500, 0, &window, &renderer);
        SDL_RenderSetScale(renderer,2 , 1);
    }
    
    void updateFrame(std::vector<int> &v, int i, int j) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        input();
        //draw current state (i) of the sort
        draw_state(v, renderer, i, j);
        //show to window and delay 10 ms
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
    
    
};

