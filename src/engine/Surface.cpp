#include "surface.h"
#include "SDL.h"

Surface::Surface() {
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

void Surface::apply(SDL_Surface* screen) {
    SDL_BlitSurface(surface, NULL, screen, &offset);
}
bool Surface::check(Size a) {

	 
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of parametry tego surface'a
	leftA = this->siz.x;
	rightA = this->siz.x+this->siz.w;
    topA = this->siz.y;
    bottomA =this->siz.y +this->siz.h;
        
    //Calculate the sides of podanego w size a klikniecia myszy
    leftB = a.x;
    rightB = a.x + a.w;
    topB = a.y;
    bottomB = a.y + a.h;

	 if( bottomA <= topB )
    {
        return false;
    }
    
    if( topA >= bottomB )
    {
        return false;
    }
    
    if( rightA <= leftB )
    {
        return false;
    }
    
    if( leftA >= rightB )
    {
        return false;
    }
    
    //jesli jst kolizja
    return true;
}

