/**
 *       @file  TextSurface.h
 *      @brief  Powierzchnia zawierająca tekst.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *     @author  Robert Pętlak, rpetlak@gmail.com
 *
 *   @internal
 *     Created  2011.06.04
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

#ifndef TEXTSURFACE_H_ON0L15PT
#define TEXTSURFACE_H_ON0L15PT

#include "SDL_ttf.h"
#include <string>

#include "Surface.h"

namespace Blast {

    /**
     * @class TextSurface
     * @brief Powierzchnia zawierająca tekst.
     */
    class TextSurface : public Surface {
        std::string text; ///< Tekst.
        TTF_Font* font; ///< Obiekt fontu, którym tekst będzie wyświetlony.
        SDL_Color color; ///< Kolor tekstu.
    
    public:
        TextSurface(); ///< Konstruktor.
        ~TextSurface(); ///< Destruktor.
    
    
        /**
         * @brief   Ustawia tekst do wyświetlenia
         * @param   text Tekst.
         */
        void setText(std::string text);
        /**
         * @brief   Ustawia font tekstu.
         * @param   font Ścieżka do pliku z fontem.
         * @param   size Rozmiar tekstu.
         */
        bool setFont(std::string font, int size);
        /**
         * @brief   Ustawia kolor tekstu.
         * @param   r Komponent czerwony.
         * @param   g Komponent zielony.
         * @param   b Komponent niebieski.
         */
        void setColor(int r, int g, int b);
    
        /**
         * @brief   Aplikuje powierzchnię na inną.
         * @param   screen Powierzchnia, na którą ma zaaplikować.
         */
        virtual void apply(SDL_Surface* screen);
    };

};

#endif /* end of include guard: TEXTSURFACE_H_ON0L15PT */
