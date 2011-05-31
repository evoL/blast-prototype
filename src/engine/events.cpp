#include "events.h"

void Events::AddEvent(std::string name,EventListener *event) {

	EventTable[name.c_str()].push_back(event);
}

void Events::FireEvent(std::string name) { //robimy wszystkie eventy z vektora

	std::vector<EventListener*>::iterator it;
	std::vector<EventListener*> vec;
	vec=EventTable[name.c_str()];

	if(vec.size()>0) 
		for(it=vec.begin();it<vec.end();it++) 
				(*it)->execute();
		
	
}

void Events::RemoveEvent(std::string name,EventListener *event) {

	std::vector<EventListener*>::iterator it;

	for (it=EventTable[name.c_str()].begin();it<EventTable[name.c_str()].end();it++) {
		if((*it)==(event)) { //tu porownujemy czy dany event jest tym ktory chcemy wywalic
			EventTable[name.c_str()].erase(it);//wywalamy konkretny event
			break;
		}

	}
}