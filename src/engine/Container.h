#ifndef CONATINERCLASS_H
#define CONATINERCLASS_H

#include "types.h"
#include "vector"
#include "Events.h"
namespace Blast {
    class Container : public Events { 	
    public:
	    SDL_Surface* screen;
	    bool collide;
	    SDL_Rect offset;
	    std::vector<Container*> surfaces;
	    virtual void render();
        virtual void add(Container* s);
        virtual bool colide_with(Point p);
	    virtual void apply(SDL_Surface* screen);
	    virtual Container *objectAtPoint(Point x);
    };
};
#endif
