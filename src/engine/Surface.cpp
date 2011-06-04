/**
 *       @file  Surface.cpp
 *      @brief  Powierzchnia.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *     @author  Robert Pętlak, rpetlak@gmail.com
 *
 *   @internal
 *     Created  2011.06.04
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

#include "Surface.h"
#include "SDL.h"

namespace Blast {
    Surface::Surface()  {
        surface = NULL;
        collide = true;
        offset.x = 0;
        offset.y = 0;
        offset.w = 0;
        offset.h = 0;
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

    void Surface::noCollide() {
        collide = false;
    }
    
    void Surface::add(Surface* s) {
	    surfaces.push_back(s);
    }

    void Surface::apply(SDL_Surface* target) {
        SDL_BlitSurface(surface, NULL, target, &offset);
    }
    
    void Surface::render() {
        std::vector<Surface*>::iterator i;
        
        if (surfaces.size() > 0) {
		    for (i=surfaces.begin(); i<surfaces.end(); i++) {
                (*i)->render(); // żeby zrobiło apply() na dzieciach
			    (*i)->apply(surface);
            }
        }
    }
    
    bool Surface::collidesWith(Point p) {
        int right = offset.x + offset.w;
        int bottom = offset.y + offset.h;
        
        return ( (p.x >= offset.x) && (p.x < right) && (p.y >= offset.y) && (p.y < bottom) );
    }
    
    Surface* Surface::objectAtPoint(Point x) {
        std::vector<Surface*>::iterator it;
        
        for (it=surfaces.begin(); it<surfaces.end(); it++) {
            if ( (*it)->collidesWith(x) && (*it)->collide ) {
                if ( (*it)->surfaces.empty() ) {
                    return (*it);
                } else {
                    return (*it)->objectAtPoint(x);
                }
            }
        }
        
        return this;
    }
};

