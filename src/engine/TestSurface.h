#ifndef TESTSURFACE_H
#define TESTSURFACE_H


#include "SDL.h"
#include "Surface.h"
namespace Blast {
    class button : public Surface {
    public:
        void apply (SDL_Surface* target);
	button();
    };
};



#endif
