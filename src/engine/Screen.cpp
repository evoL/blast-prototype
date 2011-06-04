/**
 *       @file  Screen.cpp
 *      @brief  Powierzchnia ekranu.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *     @author  Robert Pętlak, rpetlak@gmail.com
 *
 *   @internal
 *     Created  2011.06.03
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

#include "Screen.h"
#include "Surface.h"

namespace Blast {
    Screen::Screen() {
        surface = SDL_SetVideoMode(Screen::WIDTH, Screen::HEIGHT, Screen::BPP, SDL_SWSURFACE);
        setSize(Screen::WIDTH, Screen::HEIGHT);
    }

    void Screen::render() {
	    Surface::render();
        SDL_Flip(surface);
    }
};
