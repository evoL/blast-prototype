/**
 *       @file  Events.h
 *      @brief  Klasa odpowiedzialna za obsługę zdarzeń w obiektach.
 *
 * Detailed description starts here.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *     @author  Robert Pętlak, rpetlak@gmail.com
 *
 *   @internal
 *     Created  2011.06.03
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

#ifndef EVENTS_H
#define EVENTS_H

#include<string>
#include<vector>
#include <map>
#include "EventListener.h"


/** @brief Definiuje wektor ze wskaźnikami do obiektów EventListener. */
typedef std::vector<EventListener*> event_vector;


/**
 * @class Events
 * @brief Klasa abstrakcyjna odpowiedzialna za obsługę zdarzeń w obiektach.
 * 
 * Żeby dany obiekt mógł odpowiadać na zdarzenia, musi dziedziczyć po klasie Events.
 */
class Events {
public:
    std::map<std::string, event_vector> eventMap;

    virtual void addEvent(std::string name, EventListener *event);
    virtual void fireEvent(std::string name);
    virtual void removeEvent(std::string name, EventListener *event);
};


#endif
