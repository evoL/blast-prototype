#include "surface.h"
#include "SDL.h"

Surface::~Surface() {
    SDL_FreeSurface(surface);
}

void Surface::setPosition(int x, int y) {
    offset.x = x;
    offset.y = y;
}

void Surface::apply(SDL_Surface* screen) {
    SDL_BlitSurface(surface, NULL, screen, &offset);
}