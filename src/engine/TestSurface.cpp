#include "TestSurface.h"
button::button() {collide=true;};
void button::apply(SDL_Surface* screen) {
	color = SDL_MapRGB(screen->format, 255, 0, 0);
	SDL_FillRect(screen, &offset, color);
}
