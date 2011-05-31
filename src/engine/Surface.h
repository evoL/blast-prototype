#ifndef SURFACE_H
#define SURFACE_H

#include "SDL.h"
#include "events.h"
struct Size {
	int x,y,h,w;
};

class Surface :public Events{
public:
    SDL_Surface* surface;
    SDL_Rect offset;
	Size siz;
    Surface();
    ~Surface();
    
    void setPosition(int x, int y);
    virtual void apply(SDL_Surface* screen);
	virtual bool check(Size a); //sprawdza kolizje
};

#endif