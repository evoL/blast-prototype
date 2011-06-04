#include "TestSurface.h"
namespace Blast {
    button::button() {};

    void button::apply(SDL_Surface* target) {
	    int color = SDL_MapRGB(target->format, 255, 0, 0);
	    SDL_FillRect(target, &offset, color);
    }
};