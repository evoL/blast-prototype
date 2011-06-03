/**
 *       @file  Container.h
 *      @brief  Kontener na powierzchnie.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *     @author  Robert Pętlak, rpetlak@gmail.com
 *
 *   @internal
 *     Created  2011.06.04
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

#ifndef CONATINERCLASS_H
#define CONATINERCLASS_H


#include "types.h"
#include "vector"
#include "Events.h"

/**
 * @class Container
 * @brief Kontener na powierzchnie.
 */
class Container : public Events {
public:
    SDL_Surface* screen; ///< Powierzchnia właściwa.
    bool collide; ///< Określa czy może kolidować z innym kontenerem.
    SDL_Rect offset; ///< Rozmiar i pozycja.
    std::vector<Container*> surfaces; ///< Wektor z powierzchniami.

    virtual void render(); ///< Wyświetla zawartość kontenera.
    /**
     * @brief   Dodaje do kontenera inny kontener.
     * @param   s Kontener do dodania.
     */
    virtual void add (Container* s);
    /**
     * @brief   Sprawdza, czy kontener koliduje z danym punktem.
     * @param   p Punkt.
     * @return  Koliduje czy nie.
     */
    virtual bool collidesWith (Point p);
    /**
     * @brief   Aplikuje kontener na powierzchnię.
     * @param   screen Powierzchnia SDL
     */
    virtual void apply (SDL_Surface* screen);

    /**
     * @brief   Zwraca kontener znajdujący się w danym punkcie.
     * @param   x Punkt.
     * @return  Wskaźnik do kontenera.
     */
    virtual Container *objectAtPoint (Point x);
};
#endif
