#ifndef SURFACE_H
#define SURFACE_H

#include "SDL.h"
#include "Events.h"
#include "types.h"


class Surface : public Events {
public:
    SDL_Surface* surface;
    SDL_Rect offset;

    Surface();
    ~Surface();

    void setPosition(int x, int y);
    void setSize(int w, int h);
    virtual void apply(SDL_Surface* screen);

    virtual bool collidesWith(Rect r);
    virtual bool collidesWith(Point p); //sprawdza kolizje
};

#endif
