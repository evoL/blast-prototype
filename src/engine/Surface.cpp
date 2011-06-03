#include "Surface.h"
#include "SDL.h"

Surface::Surface()  {
    surface = NULL;
    offset.x = 0;
    offset.y = 0;
}

Surface::~Surface() {
    SDL_FreeSurface(surface);
}

void Surface::setPosition(int x, int y) {
    offset.x = x;
    offset.y = y;
}
void Surface::setSize(int w, int h) {
    offset.w = w;
    offset.h = h;
}

void Surface::apply(SDL_Surface* screen) {
    SDL_BlitSurface(surface, NULL, screen, &offset);
}


