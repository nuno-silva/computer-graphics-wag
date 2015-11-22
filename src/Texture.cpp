#include "Texture.hpp"

Texture::Texture(char* fileName, int w, int h) : _w(w), _h(h), _texImage(nullptr), 
                                                _isImageLoaded(false),  _isEnabled(false) 
{ 
    strcpy(_fileName, fileName); 
}
