/**
 *       @file  Tween.h
 *      @brief  Klasa od płynnych przejść.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *
 *   @internal
 *     Created  2011.06.08
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

namespace Blast {
    
    /**
     * @class Tween
     * @brief Umożliwia łatwą implementację płynnych przejść pomiędzy wartościami.
     */
    class Tween {
        typedef double (Tween::*Transition)(double); ///< Funkcja robiąca za przejście.
        typedef double (Tween::*Easing)(Transition, double); ///< Funkcja wygładzająca.
        
        double start; ///< Wartość początkowa
        double end; ///< Wartość końcowa
        double dur; ///< Czas trwania przejścia w milisekundach, domyślnie 500
        bool repeat; ///< Określa, czy przejście ma być zapętlone, domyślnie nie
        Transition trans; ///< Rodzaj przejścia
        Easing ease; ///< Rodzaj wygładzania ruchu
        int time; ///< Aktualny czas trwania
        
        bool ready; ///< Czy zostało już wszystko ustawione.
        
        // Funkcje przejścia
        
        /**
         * @brief Przejście liniowe
         * @param x Położenie względne w zakresie 0..1
         * @return Nowe położenie w zakresie 0..1
         */
        inline double linear(double x); 
        
        /**
         * @brief Przejście kwadratowe
         * @param x Położenie względne w zakresie 0..1
         * @return Nowe położenie w zakresie 0..1
         */
        inline double quad(double x); 
        
        /**
         * @brief Przejście sześcienne
         * @param x Położenie względne w zakresie 0..1
         * @return Nowe położenie w zakresie 0..1
         */
        inline double cubic(double x); 
        
        /**
         * @brief Przejście czwartego stopnia
         * @param x Położenie względne w zakresie 0..1
         * @return Nowe położenie w zakresie 0..1
         */
        inline double quart(double x); 
        
        /**
         * @brief Przejście piątego stopnia
         * @param x Położenie względne w zakresie 0..1
         * @return Nowe położenie w zakresie 0..1
         */
        inline double quint(double x); 
        
        /**
         * @brief Przejście sinusoidalne
         * @param x Położenie względne w zakresie 0..1
         * @return Nowe położenie w zakresie 0..1
         */
        inline double sine(double x); 
        
        /**
         * @brief Przejście wykładnicze
         * @param x Położenie względne w zakresie 0..1
         * @return Nowe położenie w zakresie 0..1
         */
        inline double expo(double x); 
        
        // Funkcje wygładzania
        
        /**
         * @brief Wygładzanie na początek ruchu
         * @param f Przejście
         * @param x Położenie względne w zakresie 0..1
         * @return Nowe położenie w zakresie 0..1
         */
        inline double easeIn(Transition f, double x); 
        
        /**
         * @brief Wygładzanie na koniec ruchu
         * @param f Przejście
         * @param x Położenie względne w zakresie 0..1
         * @return Nowe położenie w zakresie 0..1
         */
        inline double easeOut(Transition f, double x); 
        
        /**
         * @brief Wygładzanie na początek i koniec ruchu
         * @param f Przejście
         * @param x Położenie względne w zakresie 0..1
         * @return Nowe położenie w zakresie 0..1
         */
        inline double easeBoth(Transition f, double x);
        
        // Funkcje pomocnicze
        /**
         * @brief Odwraca przejście.
         */
        void reverse();

    public:
        static const int TRANSITION_LINEAR = 0; ///< Przejście liniowe
        static const int TRANSITION_QUAD = 1; ///< Przejście kwadratowe
        static const int TRANSITION_CUBIC = 2; ///< Przejście sześcienne
        static const int TRANSITION_QUART = 3; ///< Przejście czwartego stopnia
        static const int TRANSITION_QUINT = 4; ///< Przejście piątego stopnia
        static const int TRANSITION_SINE = 5; ///< Przejście sinusoidalne
        static const int TRANSITION_EXPO = 6; ///< Przejście wykładnicze
        
        static const int EASING_IN = 0; ///< Wygładzanie ruchu na jego początku.
        static const int EASING_OUT = 128; ///< Wygładzanie ruchu na jego końcu.
        static const int EASING_BOTH = 256; ///< Wygładzanie ruchu na jego początku i końcu.
        
        Tween(); ///< Konstruktor
        
        // Konfiguracja
        Tween& bounds(double start, double end); ///< Ustawia wartość początkową i końcową.
        Tween& duration(int ms); ///< Ustawia czas trwania przejścia w milisekundach.
        Tween& loop(); ///< Sprawia, że przejście będzie zapętlone. Ponowne wywołanie anuluje decyzję.
        Tween& transition(int trans); ///< Ustawia rodzaj przejścia.
        
        
        // Tyle
        double go(int delta); ///< Wykonuje następny krok animacji.
    };

};