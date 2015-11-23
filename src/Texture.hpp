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

    virtual void loadTexture();
    virtual void setParameterf();

public:
    virtual void draw();
    virtual void setEnabled(bool value);
    virtual bool getEnabled() const;
    virtual bool loadImage();
    virtual void toggleEnabled();
  
    Texture(char* filename, int w, int h);
    ~Texture();

};
