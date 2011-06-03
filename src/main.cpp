/**
 *       @file  main.cpp
 *      @brief  Główny plik z grą.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *     @author  Robert Pętlak, rpetlak@gmail.com
 *
 *   @internal
 *     Created  2011.06.04
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

#include "configuration.h"
#include <string>
#include <stdlib.h>
#include "engine/Engine.h"
#include "engine/ImageSurface.h"
#include "engine/TextSurface.h"
#include "engine/TestSurface.h"
#include "engine/EventListener.h"

class quit : public EventListener {  // To jest nasz event.
    void execute() {
        SDL_Quit();
        exit (0);
    }
};

/**
 * @brief   Tu się wszystko zaczyna i kończy.
 * @param   argc Ilość argumentów podanych w konsoli.
 * @param   argv Tablica z argumentami.
 * @return  To co zawsze \c main zwraca.
 */
int main (int argc, char* argv[]) {
    Engine e;
    Screen s;
    quit ev;// tu se robimy obiekt
    e.init();

    ImageSurface img (projectPath ("dziala.png"));
    img.addEvent ("click", &ev);
    s.add (&img);

    button but;
    but.setPosition (150, 300);
    but.setSize (300, 50);
    but.addEvent ("click", &ev); // A TU USTAWIAMY EVENT!!!!!!!!!!!!!!!!!!!!!

    TextSurface exit;   //tu jest napis na pseudo buttona
    exit.setText ("Click to Quit");
    exit.setFont (projectPath ("defused.ttf"), 20);
    exit.setPosition (190, 315);

    TextSurface txt;
    txt.setText ("Dziala!");
    txt.setFont (projectPath ("defused.ttf"), 96);
    txt.setPosition (80, 192);


    s.add (&txt);
    s.add (&but); //tu einfach dodaje sie buttona
    s.add (&exit);
    e.setScreen (&s);
    e.run();

    return 0;
}
