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
#include "Container.h"
#include "types.h"

namespace Blast {
    
    /**
     * @class Surface
     * @brief Powierzchnia.
     */
    class Surface : public Container{
    public:
        SDL_Surface* surface;

        Surface(); ///< Konstruktor.
        ~Surface(); ///< Destruktor.

        /**
         * @brief   Ustala pozycję powierzchni.
         * @param   x Pozycja poziomo.
         * @param   y Pozycja pionowo.
         */
        void setPosition(int x, int y);
        /**
         * @brief   Ustala rozmiar powierzchni.
         * @param   w Szerokość powierzchni.
         * @param   h Wysokość powierzchni.
         */
        void setSize(int w, int h);

        /**
         * @brief   Aplikuje powierzchnię na inną.
         * @param   screen Powierzchnia, na którą ma zaaplikować.
         */
        virtual void apply(SDL_Surface* screen);

        /**
         * @brief   Sprawdza, czy powierzchnia koliduje z prostokątem.
         * @param   r Prostokąt.
         * @return  Koliduje albo nie.
         */
        virtual bool collidesWith(Rect r);
        /**
         * @brief   Sprawdza, czy powierzchnia koliduje z punktem.
         * @param   p Punkt
         * @return  Koliduje albo nie.
         */
        virtual bool collidesWith(Point p); //sprawdza kolizje

    };

};

#endif
