#include "TestSurface.h"
namespace Blast {
    button::button() {
        anim = 0;
    };

    void button::apply(SDL_Surface* target) {
	    int color = SDL_MapRGB(target->format, 255, anim, 0);
	    SDL_FillRect(target, &offset, color);
    }
};