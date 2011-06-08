/**
 *       @file  Surface.h
 *      @brief  Powierzchnia.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *     @author  Robert Pętlak, rpetlak@gmail.com
 *
 *   @internal
 *     Created  2011.06.04
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

#ifndef SURFACE_H
#define SURFACE_H

#include "SDL.h"
#include "types.h"
#include <vector>

#include "boost/signals2.hpp"

namespace Blast {
    
    /**
     * @class Surface
     * @brief Powierzchnia.
     */
    class Surface {
    public:
        SDL_Surface* surface; ///< Właściwa powierzchnia SDL.
        bool collide; ///< Określa czy może kolidować z inną powierzchnią.
        SDL_Rect offset; ///< Rozmiar i pozycja.
        std::vector<Surface*> surfaces; ///< Wektor z powierzchniami.
        
        boost::signals2::signal<void ()> onClick; ///< Sygnał klknięcia.

        Surface(); ///< Konstruktor.
        ~Surface(); ///< Destruktor.

        /**
         * @brief   Ustala pozycję powierzchni względem powierzchni bazowej.
         * @param   x Pozycja poziomo.
         * @param   y Pozycja pionowo.
         */
        void setPosition(int x, int y);
        
        /**
         * @brief   Ustala względną poziomą pozycję powierzchni.
         * @param   x Nowa pozycja.
         * @see setPosition
         */
        void setX(int x);
        
        /**
         * @brief   Ustala względną pionową pozycję powierzchni.
         * @param   y Nowa pozycja.
         * @see setPosition
         */
        void setY(int y);
        
        /**
         * @brief   Ustala rozmiar powierzchni.
         * @param   w Szerokość powierzchni.
         * @param   h Wysokość powierzchni.
         */
        void setSize(int w, int h);
        
        /**
         * @brief   Ustala szerokość powierzchni.
         * @param   w Nowa szerokość.
         * @see setSize
         */
        void setWidth(int w);
        
        /**
         * @brief   Ustala wysokość powierzchni.
         * @param   h Nowa wysokość.
         * @see setSize
         */
        void setHeight(int h);
        
        /**
         * @brief  Sprawia, że powierzchnia nie koliduje z niczym.
         */
        void noCollide();
        
        /**
         * @brief   Dodaje do powierzchni jakąś podpowierzchnię.
         * @param   s Powierzchnia do dodania.
         */
        virtual void add (Surface* s);

        /**
         * @brief   Aplikuje powierzchnię na inną.
         * @param   target Powierzchnia SDL, na którą ma zaaplikować.
         */
        virtual void apply(SDL_Surface* target);
        
        virtual void render(); ///< Wyświetla zawartość powierzchni.
        
        /**
         * @brief   Sprawdza, czy powierzchnia koliduje z danym punktem.
         * @param   p Punkt.
         * @return  Koliduje czy nie.
         */
        virtual bool collidesWith (Point p);
        
        /**
         * @brief   Zwraca wektor z wszystkimi powierzchniamy znajdującymi się w danym punkcie.
         * @param   x Punkt.
         * @return  Wektor.
         */
        virtual std::vector<Surface*> objectsAtPoint (Point x);
    };
    
    typedef std::vector<Surface*> surface_vector; ///< Wektor na powierzchnie.
};

#endif
