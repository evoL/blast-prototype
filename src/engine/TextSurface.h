#ifndef TEXTSURFACE_H_ON0L15PT
#define TEXTSURFACE_H_ON0L15PT

#include "SDL_ttf.h"
#include <string>

class TextSurface : public Surface {
    std::string text;
    TTF_Font* font = NULL;
    SDL_Color color = {0,0,0};
    
public:
    void setText(std::string text);
    bool setFont(std::string font, int size);
    void setColor(int r, int g, int b);
    
    void apply(SDL_Surface* screen);
};

#endif /* end of include guard: TEXTSURFACE_H_ON0L15PT */
