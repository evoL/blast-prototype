#include "configuration.h"
#include <string>

#include "engine/Engine.h"

int main (int argc, char* argv[]) {
    Engine e;
    Screen s;
    
    e.init();
    e.setScreen(s);
    e.run();
    
    return 0;
}