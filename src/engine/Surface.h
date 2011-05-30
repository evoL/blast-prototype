#ifndef SURFACE_H
#define SURFACE_H

#include "SDL.h"

class Surface {
public:
    SDL_Surface* surface;
    SDL_Rect offset;

    ~Surface();
    
    void setPosition(int x, int y);
    void apply(SDL_Surface* screen);
};

#endif