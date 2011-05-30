#ifndef SURFACE_H
#define SURFACE_H

class Surface {
    SDL_Surface* surface;
    SDL_Rect offset;
    
    ~Surface();
    
    void setPosition(int x, int y);
    void apply(SDL_Surface* screen);
};

#endif