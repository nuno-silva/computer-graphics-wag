#include "PauseTexture.hpp"

void PauseTexture::loadTexture()
{

    if (!loadImage()) {
        // NOTE: more approoriate error handling would be nice
        std::cout << "Error loading image '" << _fileName << "'"<< std::endl;
        _isEnabled = false; // disable texture so that nothing bogus is drawn
        _isImageLoaded = false;
        return;
    }

    _isImageLoaded = true;

    glGenTextures(1, &_texId);
    glBindTexture(GL_TEXTURE_2D, _texId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _w, _h, 0, GL_RGBA, GL_UNSIGNED_BYTE, _texImage);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void PauseTexture::draw()
{
    if (!_isEnabled) return;

    loadTexture();

    GLfloat ar = _w / _h; // aspect ratio for QUAD side calculations

    glPushMatrix();
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDepthMask(GL_FALSE);
        glBindTexture(GL_TEXTURE_2D, _texId);
        glEnable(GL_TEXTURE_2D);

        glColor3f(1.0f, 1.0f, 1.0f);

        glBegin(GL_QUADS);
        {
            glTexCoord2f(0, 0); glVertex3f(-QUAD_SIDE * ar, -QUAD_SIDE, 0.3f);
            glTexCoord2f(1, 0); glVertex3f(QUAD_SIDE * ar, -QUAD_SIDE, 0.3f);
            glTexCoord2f(1, 1); glVertex3f(QUAD_SIDE * ar, QUAD_SIDE, 0.3f);
            glTexCoord2f(0, 1); glVertex3f(-QUAD_SIDE * ar, QUAD_SIDE, 0.3f);
        }
        glEnd();

        glDisable(GL_TEXTURE_2D);
        glDepthMask(GL_TRUE);
        glDisable(GL_BLEND);
    }
    glPopMatrix();
}

void PauseTexture::setEnabled(bool value)
{
    _isEnabled = value;
}

bool PauseTexture::getEnabled() const { return _isEnabled; }

bool PauseTexture::loadImage()
{
    // load image only if it's not already loaded
    if (!_isImageLoaded) {
        return LibpngHelper::loadImage(_fileName, _w, _h, true, &_texImage);
    }
    else {
        return true;
    }
}

void PauseTexture::toggleEnabled()
{
    _isEnabled = !_isEnabled;
}

PauseTexture::PauseTexture(char* fileName, int w, int h) : Texture(fileName, w, h) { }

PauseTexture::~PauseTexture()
{
    // free the memory associated with the loaded image
    if (_texImage != nullptr) {
        free(_texImage);
    }
}
