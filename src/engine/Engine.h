#ifndef ENGINE_H_9JZ11TDO
#define ENGINE_H_9JZ11TDO

#include "Screen.h"
namespace Blast {
    class Engine {
        Screen *screen;
        bool running;

    public:
        Engine();
        ~Engine();
        
        bool init();
        void run();
        
        void setScreen(Screen *s);
    };
};
#endif /* end of include guard: ENGINE_H_9JZ11TDO */
