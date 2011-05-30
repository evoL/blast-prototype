#ifndef IMAGESURFACE_H_AX5NGNQT
#define IMAGESURFACE_H_AX5NGNQT

#include "Surface.h"
#include <string>

class ImageSurface : public Surface {
    bool ok;
    
    bool load(std::string file);
    
public:
    ImageSurface(std::string file);
    bool loaded();
};

#endif /* end of include guard: IMAGESURFACE_H_AX5NGNQT */