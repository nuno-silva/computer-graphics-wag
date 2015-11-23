#include "Texture.hpp"
#include <cstring>
#include "LibpngHelper.hpp"
#include <iostream>

Texture::Texture(char* fileName, int w, int h) : _w(w), _h(h), _texImage(nullptr),
                                                _isImageLoaded(false),  _isEnabled(false)
{
    strcpy(_fileName, fileName);
    glGenTextures(1, &_texId);
}

Texture::~Texture()
{
    // free the memory associated with the loaded image
    if (_texImage != nullptr) {
        free(_texImage);
    }
}

void Texture::loadTexture() {
    if (!loadImage()) {
        // NOTE: more approoriate error handling would be nice
        std::cout << "Error loading image" << std::endl;
        _isEnabled = false; // disable texture so that nothing bogus is drawn
        _isImageLoaded = false;
        return;
    }

    _isImageLoaded = true;

    /*
    * TODO: check if glBindTexture() and glTextImage() calls have to be done only once
    *  or every time the texture is drawn. In the first case, put those calls in "else" above
    */
    glBindTexture(GL_TEXTURE_2D, _texId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _w, _h, 0, GL_RGBA, GL_UNSIGNED_BYTE, _texImage);

    setParameterf();

   /* IMPORTANT: if subclasses wish to use a set of glParameterf's, they should
    * override setParameterf(), and loadTexture() and within loadTexture() call
    * Texture::loadTexture().
    */
}

void Texture::setParameterf()
{
    /**
        Contains the default set of glTexParameterf()'s. If subclasses wish to
        use a different one, they should override this method.
    */
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void Texture::setEnabled(bool value)
{
    _isEnabled = value;
}

bool Texture::getEnabled() const { return _isEnabled; }

bool Texture::loadImage()
{
    // load image only if it's not already loaded
    if (!_isImageLoaded) {
        return LibpngHelper::loadImage(_fileName, _w, _h, true, &_texImage);
    }
    else {
        return true;
    }
}

GLuint Texture::getTexId() {
    return _texId;
}

void Texture::draw(){
    if (!_isEnabled) return;

    loadTexture();

    glColor3f(1.0f, 1.0f, 1.0f); // IMPORTANT for mixtures
}

void Texture::toggleEnabled()
{
    _isEnabled = !_isEnabled;
}
