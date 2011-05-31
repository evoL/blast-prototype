#ifndef EVENTS_H
#define EVENTS_H
#include<string>
#include<vector>
#include <map>
#include "EventListener.h"

class Events {
 
public:
	std::map<std::string,std::vector <EventListener*> >  EventTable;
	void AddEvent(std::string name,EventListener *event);
	void FireEvent(std::string name,EventListener *event);
	void RemoveEvent(std::string name,EventListener *event); 

};


#endif