#ifndef TESTSURFACE_H
#define TESTSURFACE_H


#include "SDL.h"
#include "Surface.h"


class button : public Surface {
public:
    int color;
    void apply (SDL_Surface* screen);
};




#endif
