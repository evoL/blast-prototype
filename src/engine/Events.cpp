/**
 *       @file  Events.cpp
 *      @brief  Klasa odpowiedzialna za obsługę zdarzeń w obiektach.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *     @author  Robert Pętlak, rpetlak@gmail.com
 *
 *   @internal
 *     Created  2011.06.03
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

#include "Events.h"
namespace Blast {
    void Events::addEvent ( std::string name, EventListener *event ) {
        eventMap[name.c_str()].push_back ( event );
    }

    void Events::fireEvent ( std::string name ) { //robimy wszystkie eventy z vektora
        event_vector::iterator it;
        event_vector vec;
        vec = eventMap[name.c_str()];

	    if (vec.size() > 0){
			for (it = vec.begin(); it < vec.end(); it++ ) {
                (*(*it))();
			}
        }
    }


    void Events::removeEvent ( std::string name, EventListener *event ) {
        event_vector::iterator it;
        event_vector* vec;
        vec = &eventMap[name.c_str()];

        for ( it = vec->begin(); it < vec->end(); it++ ) {
            if ((*it) == (event)) { //tu porownujemy czy dany event jest tym ktory chcemy wywalic
                vec->erase ( it ); //wywalamy konkretny event
                break;
            }
        }
    }
};