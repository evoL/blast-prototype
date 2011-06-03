#include "configuration.h"
#include <string>
#include <stdlib.h>
#include "engine/Engine.h"
#include "engine/ImageSurface.h"
#include "engine/TextSurface.h"
#include "engine/TestSurface.h"
#include "engine/EventListener.h"
using namespace Blast;
class quit : public EventListener {  // To jest nasz event.
    void execute() {
        SDL_Quit();
        exit (0);
    }
};

int main (int argc, char* argv[]) {
    Engine e;
    Screen s;
    quit ev;// tu se robimy obiekt
    e.init();

    ImageSurface img (projectPath ("dziala.png"));
    s.add (&img);

    button but;
    but.setPosition(150, 300);
    but.setSize(300, 50);
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
