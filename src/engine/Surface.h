#ifndef SURFACE_H
#define SURFACE_H

#include "SDL.h"

class Surface {
protected:
    SDL_Surface* surface;
    SDL_Rect offset;
public:
    ~Surface();
    
    void setPosition(int x, int y);
    void apply(SDL_Surface* screen);
};

#endif