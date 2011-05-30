#include "configuration.h"
#include <string>

#include "engine/Engine.h"
#include "engine/ImageSurface.h"
#include "engine/TextSurface.h"

int main (int argc, char* argv[]) {
    Engine e;
    Screen s;
    
    ImageSurface img(projectPath("dziala.png"));
    s.add(img);
    
    TextSurface txt;
    txt.setText("Dziala!");
    txt.setFont(projectPath("defused.ttf"), 96);
    txt.setPosition(80, 192);
    s.add(txt);
    
    e.init();
    e.setScreen(&s);
    e.run();
    
    return 0;
}