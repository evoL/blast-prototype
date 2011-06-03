/**
 *       @file  ImageSurface.h
 *      @brief  Powierzchnia zawierająca obrazek.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *     @author  Robert Pętlak, rpetlak@gmail.com
 *
 *   @internal
 *     Created  2011.06.03
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

#ifndef IMAGESURFACE_H_AX5NGNQT
#define IMAGESURFACE_H_AX5NGNQT

#include "Surface.h"
#include <string>
namespace Blast {
    
    /**
     * @class ImageSurface
     * @brief Powierzchnia zawierająca obrazek.
     */
    class ImageSurface : public Surface {
    public:
        ImageSurface(); ///< Konstruktor.

        /**
         * @brief   Ładuje podany obrazek.
         * @param   file Ścieżka do pliku z obrazkiem.
         * @return  Czy załadowało, czy nie.
         */
        bool load(std::string file);

    };

};
#endif /* end of include guard: IMAGESURFACE_H_AX5NGNQT */
