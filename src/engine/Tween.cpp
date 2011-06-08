/**
 *       @file  Tween.cpp
 *      @brief  Klasa od płynnych przejść.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *
 *   @internal
 *     Created  2011.06.08
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */

#include "Tween.h"
#include <cmath>

#define PI 3.141592653589793

namespace Blast {
    Tween::Tween() {
        start = 0;
        end = 0;
        time = 0;
        dur = 500;
        repeat = false;
        ready = false;
        trans = &Tween::linear;
        ease = &Tween::easeIn;
    }
    
    // Konfiguracja
    
    Tween& Tween::bounds(double start, double end) {
        this->start = start;
        this->end = end;
        return *this;
    }
    Tween& Tween::duration(int ms) {
        this->dur = ms;
        return *this;
    }
    Tween& Tween::loop() {
        repeat = !repeat;
        return *this;
    }
    Tween& Tween::transition(int trans) {
        if (trans & EASING_OUT) {
            ease = &Tween::easeOut;
        } else if (trans & EASING_BOTH) {
            ease = &Tween::easeBoth;
        } else {
            ease = &Tween::easeIn;
        }
        
        int transOnly = trans & ~(EASING_OUT | EASING_BOTH);

        switch (transOnly) {
            case TRANSITION_QUAD:
                this->trans = &Tween::quad;
                break;
            case TRANSITION_CUBIC:
                this->trans = &Tween::cubic;
                break;
            case TRANSITION_QUART:
                this->trans = &Tween::quart;
                break;
            case TRANSITION_QUINT:
                this->trans = &Tween::quint;
                break;
            case TRANSITION_SINE:
                this->trans = &Tween::sine;
                break;
            case TRANSITION_EXPO:
                this->trans = &Tween::expo;
                break;
            default:
                this->trans = &Tween::linear;
                break;
        }
        
        return *this;
    }
    
    // Funkcje przejścia
    
    double Tween::linear(double x) {
        return x;
    }
    double Tween::quad(double x) {
        return x*x;
    }
    double Tween::cubic(double x) {
        return x*x*x;
    }
    double Tween::quart(double x) {
        return x*x*x*x;
    }
    double Tween::quint(double x) {
        return x*x*x*x*x;
    }
    double Tween::sine(double x) {
        return 1 - cos(x*0.5*PI);
    }
    double Tween::expo(double x) {
        return pow(2, 8*(x-1));
    }
    
    // Funkcje wygładzania ruchu
    
    double Tween::easeIn(Transition f, double x) {
        return (this->*f)(x);
    }
    double Tween::easeOut(Transition f, double x) {
        return 1 - (this->*f)(1-x);
    }
    double Tween::easeBoth(Transition f, double x) {
        return ( (x <= 0.5) ? (this->*f)(2*x) : 2 - (this->*f)( 2 * (1-x) ) ) * 0.5;
    }
    
    // i tyle
    
    void Tween::reverse() {
        double temp = start;
        start = end;
        end = temp;
        
        ready = false;
    }
    
    double Tween::go(int delta) {
        if (!ready) {
            time = 0;
            ready = true;
        }
        
        double result;
        if (time < dur) {
            result = (end-start) * (this->*ease)(trans, (time/(double)dur)) + start;
            time += delta;
        } else {
            result = end;
            time = dur;
            
            if (repeat) reverse();
        }
        
        return result;
    }
}