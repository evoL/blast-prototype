#include "configuration.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include <string>

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP    = 32;

SDL_Surface* screen = NULL;

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

void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    
    SDL_BlitSurface(source, NULL, destination, &offset);
}

bool init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) return false;
    
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (screen == NULL) return false;
    
    if (TTF_Init() == -1) return false;
    
    SDL_WM_SetCaption("Cuboid", NULL);
    return true;
}

int main (int argc, char* argv[]) {
    // surfacy
    SDL_Surface* text = NULL;
    SDL_Surface* bg = NULL;
    
    // event
    SDL_Event event;
    
    // font
    TTF_Font *font = NULL;
    SDL_Color textColor = { 0, 0, 0 };
    
    bool quit = false;
    
    if (!init()) return 1;
    
    // loading
    bg = loadImage(projectPath("dziala.png"));
    font = TTF_OpenFont(projectPath("defused.ttf").c_str(), 96);
    
    // tekst
    text = TTF_RenderText_Blended(font, "Dziala!", textColor);
    
    // wciepywanie na ekran
    applySurface(0, 0, bg, screen);
    applySurface(80, 192, text, screen);
    
    // rysowanie
    if (SDL_Flip(screen) == -1) return 1;
    
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }
    
    SDL_FreeSurface(text);
    SDL_FreeSurface(bg);
    
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    
    return 0;
}