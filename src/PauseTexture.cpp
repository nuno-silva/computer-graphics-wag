#include "PauseTexture.hpp"

void PauseTexture::draw()
{
    Texture::draw(); // load texture, set color to white

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texId);

    glBegin(GL_QUADS); 
    {
        glTexCoord2f(0, 0); glVertex3f(-QUAD_SIDE   *   _ar,    -QUAD_SIDE, Z_DIST);
        glTexCoord2f(1, 0); glVertex3f( QUAD_SIDE   *   _ar,    -QUAD_SIDE, Z_DIST);
        glTexCoord2f(1, 1); glVertex3f( QUAD_SIDE   *   _ar,     QUAD_SIDE, Z_DIST);
        glTexCoord2f(0, 1); glVertex3f(-QUAD_SIDE   *   _ar,     QUAD_SIDE, Z_DIST);

    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

PauseTexture::PauseTexture(char* fileName, int w, int h) : Texture(fileName, w, h), _ar(_w/_h) { }
