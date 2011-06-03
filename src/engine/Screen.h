#ifndef SCREEN_H
#define SCREEN_H

#include "SDL.h"
#include <vector>


#include "Container.h"
namespace Blast {
    class Screen : public Container {    
    public:
        void render();
        static const int WIDTH = 640;
        static const int HEIGHT = 480;
        static const int BPP = 32;    
        
        Screen();  
        
    };
};
#endif