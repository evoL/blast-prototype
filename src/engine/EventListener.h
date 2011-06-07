/**
 *       @file  EventListener.h
 *      @brief  Zawiera klasę bazową do obsługi zdarzeń.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *     @author  Robert Pętlak, rpetlak@gmail.com
 *
 *   @internal
 *     Created  2011.06.03
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

/**
 * @class EventListener
 * @brief Klasa bazowa do obsługi zdarzeń.
 *
 * Klasa ta jest abstrakcyjna. Żeby jej użyć, należy utworzyć podklasę i nadpisać metodę
 * \c execute() .
 *
 * Przykład użycia:
 * @code
 * class LolEvent : public EventListener {
 *     void execute() {
 *         std::cout << "LOL!" << std::endl;
 *     }
 * }
 * @endcode
 *
 * @see Events
 */
class EventListener {

public:
    EventListener(); ///< Konstruktor.
    virtual void operator()() = 0; ///< Zawiera kod zdarzenia.
};


#endif
