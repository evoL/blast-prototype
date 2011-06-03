#include "screen.h"

Screen::Screen() {
    screen = SDL_SetVideoMode(Screen::WIDTH, Screen::HEIGHT, Screen::BPP, SDL_SWSURFACE);
    surfaces = std::vector<Container*>();
	collide=false;
}

void Screen::render() {
	Container::render();
    SDL_Flip(screen);
}

