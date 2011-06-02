#include "screen.h"

Screen::Screen() {
    screen = SDL_SetVideoMode(Screen::WIDTH, Screen::HEIGHT, Screen::BPP, SDL_SWSURFACE);
    surfaces = std::vector<Surface*>();
}

void Screen::render() {
	ContainerClass::render();
    SDL_Flip(screen);
}

