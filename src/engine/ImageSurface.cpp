#include "ImageSurface.h"
#include "SDL_image.h"

ImageSurface::ImageSurface(std::string file) {
    ok = load(file);
}

bool ImageSurface::load(std::string file) {
    SDL_Surface* img = NULL;
    
    img = IMG_Load(file.c_str());
    if (img == NULL) return false;
    
    surface = SDL_DisplayFormat(img);
    SDL_FreeSurface(img);
    
    return true;
}

bool ImageSurface::loaded() {
    return ok;
}