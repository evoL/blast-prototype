#ifndef TEXTSURFACE_H_ON0L15PT
#define TEXTSURFACE_H_ON0L15PT

#include "SDL_ttf.h"
#include <string>

#include "Surface.h"

class TextSurface : public Surface {
    std::string text;
    TTF_Font* font;
    SDL_Color color;
    
public:
    TextSurface();
    ~TextSurface();
    
    void setText(std::string text);
    bool setFont(std::string font, int size);
    void setColor(int r, int g, int b);
    
    void apply(SDL_Surface* screen);
	TextSurface();
};

#endif /* end of include guard: TEXTSURFACE_H_ON0L15PT */
