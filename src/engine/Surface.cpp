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

bool Surface::collidesWith(Rect r) {
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of parametry tego surface'a
    leftA = offset.x;
    rightA = offset.x + offset.w;
    topA = offset.y;
    bottomA = offset.y + offset.h;

    //Calculate the sides of podanego w size a klikniecia myszy
    leftB = r.x;
    rightB = r.x + r.w;
    topB = r.y;
    bottomB = r.y + r.h;

    if( bottomA <= topB ) {
        return false;
    }

    if( topA >= bottomB ) {
        return false;
    }

    if( rightA <= leftB ) {
        return false;
    }

    if( leftA >= rightB ) {
        return false;
    }

    //jesli jest kolizja
    return true;
}

bool Surface::collidesWith(Point p) {
    Rect rect;
    rect.x = p.x;
    rect.y = p.y;
    rect.w = 1;
    rect.h = 1;

    return collidesWith(rect);
}
