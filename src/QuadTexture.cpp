#include "QuadTexture.hpp"

void QuadTexture::draw()
{
    Texture::draw(); // load texture, set color to white

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texId);

    glBegin(GL_QUADS);
    {
        glTexCoord2f(0, 0); glVertex3f(-_radius  *  _ar, -_radius, Z_DIST);
        glTexCoord2f(1, 0); glVertex3f( _radius  *  _ar, -_radius, Z_DIST);
        glTexCoord2f(1, 1); glVertex3f( _radius  *  _ar,  _radius, Z_DIST);
        glTexCoord2f(0, 1); glVertex3f(-_radius  *  _ar,  _radius, Z_DIST);

    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

QuadTexture::QuadTexture(char* fileName, int w, int h, GLfloat quad_radius) :
                Texture(fileName, w, h), _ar(_w/_h), _radius(quad_radius) { }
