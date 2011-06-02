#include "ContainerClass.h"

void ContainerClass::add(Surface* s) {
    surfaces.push_back(s);
}

void ContainerClass::render() {
    std::vector<Surface*>::iterator i;
    
    if (surfaces.size() > 0) {
        for (i=surfaces.begin(); i<surfaces.end(); i++) {
            (*i)->apply(screen);
        }
    }
}
   
Surface *ContainerClass::colide_with(Point p) {
	std::vector<Surface*>::iterator it;
	
	
	return 0;
}