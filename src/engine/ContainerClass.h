#ifndef CONATINERCLASS_H
#define CONATINERCLASS_H

#include "Surface.h"
#include "types.h"
#include "vector"


class ContainerClass {
	
public:
	  SDL_Surface* screen;
	std::vector<Surface*> surfaces;
	virtual void render();
    virtual void add(Surface* s);
    virtual Surface *colide_with(Point p);

};

#endif