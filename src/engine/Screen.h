/**
 *       @file  Screen.h
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

#ifndef SCREEN_H
#define SCREEN_H

#include "SDL.h"
#include <vector>

#include "Surface.h"

/**
 * @class Screen
 * @brief Powierzchnia ekranu.
 */
class Screen {
    SDL_Surface* screen; ///< Właściwy Surface z SDL
public:
    std::vector<Surface*> surfaces; ///< Wektor z podpowierzchniami.
    static const int WIDTH = 640; ///< Rozdzielczość pozioma ekranu.
    static const int HEIGHT = 480; ///< Rozdzielczość pionowa ekranu.
    static const int BPP = 32; ///< Głębia kolorów w bitach.
    
    Screen(); ///< Konstruktor.
    
    /**
     * @brief   Wyświetla zawartość ekranu.
     */
    void render();

    /**
     * @brief   Dodaje powierzchnię do ekranu.
     * @param   s Wskaźnik do dodawanej powierzchni.
     */
    void add(Surface* s);
};

#endif
