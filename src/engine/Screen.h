#ifndef SCREEN_H
#define SCREEN_H

#include "SDL.h"
#include <vector>

class Screen {
    const int WIDTH = 640;
    const int HEIGHT = 480;
    const int BPP = 32;
    
    SDL_Surface* screen;
    std::vector<Surface> surfaces;
    
    Screen();
    
    void render();
    void add(Surface s);
};

#endif