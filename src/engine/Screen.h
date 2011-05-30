#ifndef SCREEN_H
#define SCREEN_H

#include "SDL.h"
#include <vector>

#include "Surface.h"

class Screen {
    SDL_Surface* screen;
    std::vector<Surface> surfaces;
    
public:
    static const int WIDTH = 640;
    static const int HEIGHT = 480;
    static const int BPP = 32;    
    
    Screen();
    
    void render();
    void add(Surface s);
};

#endif