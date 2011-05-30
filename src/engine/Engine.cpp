#include "Engine.h"
#include "Screen.h"

#include "SDL.h"
#include "SDL_ttf.h"

Engine::Engine() {
    running = false;
}
Engine::~Engine() {
    TTF_Quit();
    SDL_Quit();
}

bool Engine::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) return false;
    if (TTF_Init() == -1) return false;
    
    SDL_WM_SetCaption("Cuboid", NULL);
    
    return true;
}

void Engine::setScreen(Screen *s) {
    screen = s;
}

void Engine::run() {
    running = true;
    
    SDL_Event event;
    
    screen->render();
    
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    }
    
    running = false;
}