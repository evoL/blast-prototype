/**
 *       @file  ImageSurface.cpp
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

#include "ImageSurface.h"
#include "SDL_image.h"
namespace Blast {

    ImageSurface::ImageSurface() {}

    bool ImageSurface::load(std::string file) {
        SDL_Surface* img = NULL;
    
        img = IMG_Load(file.c_str());
        if (img == NULL) return false;
    
        surface = SDL_DisplayFormat(img);
        SDL_FreeSurface(img);
    
        return true;
    }

};
