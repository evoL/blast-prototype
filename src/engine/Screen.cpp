#include "screen.h"

Screen::Screen() {
    screen = SDL_SetVideoMode(Screen::WIDTH, Screen::HEIGHT, Screen::BPP, SDL_SWSURFACE);
}

void Screen::render() {
    std::vector<Surface>::iterator i;
    
    for (i=surfaces.begin(); i<=surfaces.end(); i++) {
        (*i).apply(screen);
    }
    
    SDL_Flip(screen);
}

void Screen::add(Surface s) {
    surfaces.push_back(s);
}