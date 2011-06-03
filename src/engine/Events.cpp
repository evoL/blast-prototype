#include "Events.h"

void Events::addEvent ( std::string name, EventListener *event ) {
    eventMap[name.c_str()].push_back ( event );
}

void Events::fireEvent ( std::string name ) { //robimy wszystkie eventy z vektora
    event_vector::iterator it;
    event_vector vec;
    vec = eventMap[name.c_str()];

	if ( vec.size() > 0 ){
        for ( it = vec.begin(); it < vec.end(); it++ )
            ( *it )->execute();
	}
}


void Events::removeEvent ( std::string name, EventListener *event ) {
    event_vector::iterator it;

    for ( it = eventMap[name.c_str()].begin(); it < eventMap[name.c_str()].end(); it++ ) {
        if ( ( *it ) == ( event ) ) { //tu porownujemy czy dany event jest tym ktory chcemy wywalic
            eventMap[name.c_str()].erase ( it ); //wywalamy konkretny event
            break;
        }
    }
}
