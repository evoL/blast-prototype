/**
 *       @file  Engine.h
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


#ifndef ENGINE_H_9JZ11TDO
#define ENGINE_H_9JZ11TDO

#include "Screen.h"
namespace Blast {

    /**
     * @class Engine
     * @brief Klasa zawierające centrum sterowania grą.
     *
     * Prawidłowy sposób użycia:
     * @code
     * Engine engine;
     * Screen screen;
     * if (engine.init()) {
     *     engine.setScreen(&screen);
     *     engine.run();
     * }
     * @endcode
     *
     * @see Screen
     */
    class Engine {
        Screen *screen; ///< Wskaźnik do używanego obiektu Screen.
        bool running; ///< Zmienna określająca, czy gra działa.

    public:
        boost::signals2::signal<void (int)> onTick; ///< Sygnał wywoływany co klatkę.
        
    
        /**
         * @brief   Konstuktor.
         * @see ~Engine()
         * @see init()
         */
        Engine();
    
        /**
         * @brief   Destruktor
         * @see Engine()
         */
        ~Engine();
    
    
        /**
         * @brief   Inicjuje silnik.
         * @return  Czy się udało, czy nie.
         * @see     Engine()
         */
        bool init();
    
        /**
         * @brief   Wywołuje główną pętlę.
         * @see Engine()
         * @see init()
         * @see setScreen()
         */
        void run();
    
        /**
         * @brief   Ustawia ekran, na którym wyświetlany będzie obraz.
         * @param   s Wskaźnik do obiektu Screen, będącego aktualnym ekranem.
         * @see Engine()
         * @see init()
         * @see run()
         */
        void setScreen(Screen *s);
        
        /**
         * @brief  Wyłącza grę.
         */
        void quit();
    };
}
#endif /* end of include guard: ENGINE_H_9JZ11TDO */
