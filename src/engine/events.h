#ifndef EVENTS_H
#define EVENTS_H
#include<string>
#include<vector>
#include <map>
#include "EventListener.h"

class Events {
 
public:
	std::map<std::string,std::vector <EventListener*> >  EventTable; //taka tablica z vektorami
	virtual void AddEvent(std::string name,EventListener *event);
	virtual void FireEvent(std::string name);
	virtual void RemoveEvent(std::string name,EventListener *event); 

};


#endif