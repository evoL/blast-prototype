#include "TextSurface.h"

TextSurface::TextSurface(){

	 font = NULL;
	color.r=0;
	color.g=0;
	color.b=0;
}

void TextSurface::setText(std::string text) {
    this->text = text;
}

bool TextSurface::setFont(std::string font, int size) {
    this->font = TTF_OpenFont(font.c_str(), size);
    return (this->font != NULL);
}

void TextSurface::setColor(int r, int g, int b) {
	color.r=r;
	color.g=g;
	color.b=b;
}

void TextSurface::apply(SDL_Surface* screen) {
    surface = TTF_RenderText_Blended(font, text.c_str(), color);
    Surface::apply(screen);
}



