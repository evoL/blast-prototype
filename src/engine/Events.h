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
    std::map<std::string, event_vector> eventMap; ///< Mapa zawierająca obiekty #event_vector

    /**
     * @brief   Dodaje zdarzenie danego typu do obiektu.
     * @param   name Typ zdarzenia.
     * @param   event Obiekt zawierający zdarzenie.
     */
    virtual void addEvent(std::string name, EventListener *event);

    /**
     * @brief   Wywołuje zdarzenie danego typu.
     * @param   name Typ zdarzenia.
     */
    virtual void fireEvent(std::string name);

    /**
     * @brief   Usuwa zdarzenie danego typu.
     * @param   name Typ zdarzenia.
     * @param   event Zdarzenie do usunięcia.
     */
    virtual void removeEvent(std::string name, EventListener *event);
};


#endif
