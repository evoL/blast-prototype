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
		exit(0);
	}
};

int main (int argc, char* argv[]) {
    Engine e;
    Screen s;
    quit ev;// tu se robimy obiekt
    e.init();
    
    ImageSurface img(projectPath("dziala.png"));
    s.add(&img);
    
    
	button but(150,300,50,300);// tu moj pseudo button ustawiamy
	but.AddEvent("click",&ev);	// A TU USTAWIAMY EVENT!!!!!!!!!!!!!!!!!!!!!
	//but.RemoveEvent("click",&ev);//tu mozna sprawdzic ze nawet usuwanie dziala

	TextSurface exit;	//tu jest napis na pseudo buttona
	exit.setText("Click to Quit");
	exit.setFont(projectPath("defused.ttf"), 20);
	exit.setPosition(190, 315);

	TextSurface txt;
    txt.setText("Dziala!");
    txt.setFont(projectPath("defused.ttf"), 96);
    txt.setPosition(80, 192);

	
    s.add(&txt);
    s.add(&but);//tu einfach dodaje sie buttona
	s.add(&exit);
    e.setScreen(&s);
    e.run();
    
    return 0;
}