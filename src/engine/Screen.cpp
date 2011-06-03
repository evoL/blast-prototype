#include "screen.h"
namespace Blast {
    Screen::Screen() {
        screen = SDL_SetVideoMode(Screen::WIDTH, Screen::HEIGHT, Screen::BPP, SDL_SWSURFACE);
        surfaces = std::vector<Container*>();
    }

    void Screen::render() {
	    Container::render();
        SDL_Flip(screen);
    }
};
