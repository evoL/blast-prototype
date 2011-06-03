#ifndef SURFACE_H
#define SURFACE_H

#include "SDL.h"
#include "Container.h"
#include "types.h"



class Surface : public Container{
public:
    SDL_Surface* surface;

    Surface();
    ~Surface();

    void setPosition(int x, int y);
    void setSize(int w, int h);
    void apply(SDL_Surface* screen);

};

#endif
