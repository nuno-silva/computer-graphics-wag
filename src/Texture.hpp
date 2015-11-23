#pragma once
#include "glut.hpp"
#include <string>

class Texture {

protected:
    bool _isEnabled;
    bool _isImageLoaded;
    char _fileName[256];
    const int _w;
    const int _h;
    GLuint _texId;
    GLubyte* _texImage;

    virtual void loadTexture() = 0;


public:
    virtual void draw() = 0;
    virtual void setEnabled(bool value) = 0;
    virtual bool getEnabled() const = 0;
    virtual bool loadImage() = 0;
    virtual void toggleEnabled() = 0;


    Texture(char* filename, int w, int h);

};

/* texture paths */
#if __GNUC__
# define TEXTURE_PATH "../res/textures/"
#else
# define TEXTURE_PATH ""
#endif

