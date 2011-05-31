#include "TestSurface.h"

button::button(int x,int y,int px,int py) {
	rect=new SDL_Rect;
	rect->x=x;
	rect->y=y;
	rect->h=px;
	rect->w=py;	

	siz.h=px;
	siz.w=py;
	siz.x=x;
	siz.y=y;
}

void button::apply(SDL_Surface* screen) {
	color = SDL_MapRGB(screen->format, 255, 0, 0);
	SDL_FillRect(screen,rect,color);
   	
}