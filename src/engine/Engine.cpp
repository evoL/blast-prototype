#include "types.h"
#include "Engine.h"
#include "Screen.h"
#include "Surface.h"
#include "Container.h"
#include "SDL.h"
#include "SDL_ttf.h"
namespace Blast {

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

                else if(event.type == SDL_MOUSEBUTTONDOWN) {
                    Point a; //struktura
                    a.x=event.button.x;
                    a.y=event.button.y;
                    Container *dupa;
				    dupa=(screen->objectAtPoint(a));
				    if(dupa!=NULL)dupa->fireEvent("click");
    				
                }//koniec elsa
            }//koniec while z eventem
        }//koniec running

        running = false;
    }
};