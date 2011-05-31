#ifndef TESTSURFACE_H
#define TESTSURFACE_H


#include "SDL.h"
#include "Surface.h"


class button : public Surface {
public:
 SDL_Rect *rect;
 int color;
 button(int x,int y,int px,int py);
 void apply(SDL_Surface* screen);

};




#endif