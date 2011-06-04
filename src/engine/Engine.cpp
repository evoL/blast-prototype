/**
 *       @file  Engine.cpp
 *      @brief  Zawiera silnik gry.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *     @author  Robert Pętlak, rpetlak@gmail.com
 *
 *   @internal
 *     Created  2011.06.03
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

#include "types.h"
#include "Engine.h"
#include "Screen.h"
#include "Surface.h"
#include "SDL.h"
#include "SDL_ttf.h"

namespace Blast {

    Engine::Engine() {
        running = false;
        screen = NULL;
    }
    Engine::~Engine() {
        TTF_Quit();
        SDL_Quit();
    }

    bool Engine::init() {
        if (SDL_Init (SDL_INIT_EVERYTHING) == -1) return false;
        if (TTF_Init() == -1) return false;

        SDL_WM_SetCaption ("Cuboid", NULL);

        return true;
    }

    void Engine::setScreen (Screen *s) {
        screen = s;
    }

    void Engine::run() {
        if (screen == NULL) return;
        
        running = true;

        SDL_Event event;
        Point a;

        // Tu będzie pętla (wątek?) od odświeżania obrazu.
        screen->render();

        // Pętla do eventów
        // TODO: zrobić to w osobnym wątku
        while (running) {
            while (SDL_PollEvent (&event)) {
                switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_MOUSEBUTTONUP:
                    a.x = event.button.x;
                    a.y = event.button.y;

                    Surface* dupa;
                    dupa = screen->objectAtPoint (a);
                    dupa->fireEvent("click");
                    break;
                }
            }
        }
        
        running = false;
    }

};