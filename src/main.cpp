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
using namespace Blast;

class quit {  // To jest nasz event.
public:
    Engine* e;
    quit(Engine* e) {
        this->e = e;
    }
    void operator()() {
        e->quit();
    }
};

class animate {
public:
    float dupa;
    bool in;
    button* but;
    
    animate(button* b) {
        but = b;
        dupa = 0;
        in = true;
    }
    void operator()(int delta) {
        if (in) {
            dupa += (128 * (delta / 1000.0f));
        } else {
            dupa -= (128 * (delta / 1000.0f));
        }
        
        but->anim = (int)dupa;
        
        if (but->anim < 0) {
            but->anim = 0;
            in = true;
        } else if (but->anim > 128) {
            but->anim = 128;
            in = false;
        }
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
    quit ev(&e);
    
    Screen s;
    
    e.init();

    ImageSurface img;
    img.load(projectPath("dziala.png"));
    s.add (&img);

    button but;
    but.setPosition (150, 300);
    but.setSize (300, 50);
    //but.addEvent ("click", &ev); // A TU USTAWIAMY EVENT!!!!!!!!!!!!!!!!!!!!!
    but.onClick.connect(ev);
    
    animate ev2(&but);
    e.onTick.connect(ev2);

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
