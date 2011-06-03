#include "Container.h"
namespace Blast {
    void Container::add(Container* s) {
	    surfaces.push_back(s);
	    collide=true;
    }

    void Container::render() {
        std::vector<Container*>::iterator i;
        
        if (surfaces.size() > 0) {
		    for (i=surfaces.begin(); i<surfaces.end(); i++) {
			    (*i)->apply(screen);
            }
        }
    }
       
    bool Container::colide_with(Point p) {
	    //std::vector<Container*>::iterator it;
	    Rect r;
        r.x = p.x;
        r.y = p.y;
        r.w = 1;
	    r.h = 1;

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
    	
	    return 0;
    }
    void Container::apply(SDL_Surface* screen) {};

    Container *Container::objectAtPoint(Point x) {

	    std::vector<Container*>::iterator it;	

	    for(it=surfaces.begin();it<surfaces.end();it++) {
	        if((*it)->colide_with(x)&&(*it)->collide!=false) {
                if((*it)->surfaces.empty()) return (*it);	
			    else return (*it)->objectAtPoint(x);
		    }
    		
	    }

    	
    }

};