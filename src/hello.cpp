#include "configuration.h"
#include "SDL.h"
#include "SDL_image.h"

#include <string>

SDL_Surface* loadImage(std::string filename) {
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    
    loadedImage = IMG_Load(filename.c_str());
    
    if (loadedImage != NULL) {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        
        SDL_FreeSurface(loadedImage);
    }
    
    return optimizedImage;
}

int main (int argc, char* argv[]) {
    // surfacy
    SDL_Surface* hello = NULL;
    SDL_Surface* screen = NULL;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    
    hello = loadImage(projectPath("dziala.png"));
    
    SDL_BlitSurface(hello, NULL, screen, NULL);
    SDL_Flip(screen);
    
    SDL_Delay(5000);
    
    SDL_FreeSurface(hello);
    SDL_Quit();
    
    return 0;
}