#ifndef EVENTS_H
#define EVENTS_H

#include<string>
#include<vector>
#include <map>
#include "EventListener.h"

typedef std::vector<EventListener*> event_vector;

class Events {
public:
    std::map<std::string, event_vector> eventMap;

    virtual void addEvent(std::string name, EventListener *event);
    virtual void fireEvent(std::string name);
    virtual void removeEvent(std::string name, EventListener *event);
};


#endif
