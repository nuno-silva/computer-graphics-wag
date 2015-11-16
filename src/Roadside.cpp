#include "Roadside.hpp"
#include "Cheerio.hpp"
#include <cstdio>
#include <cmath>

Roadside::Roadside( GLdouble size ) : _size(size) {
    const GLfloat cheerio_count     = 80.0f;
    const GLfloat deg_inc           = 2.0f * PI / cheerio_count;

    const GLfloat inside_radius     = _size * 0.60f;
    const GLfloat outside_radius    = _size;

    const GLfloat cheerio_inside_r  = cm(0.25);
    const GLfloat cheerio_outside_r = cm(0.45);

    const GLfloat z                 = cheerio_inside_r / 2.0f;

    for ( GLfloat i = 0.0f; i < 2.0f * PI; i+=deg_inc ) {
        GLfloat x = sin(i);
        GLfloat y = 0.8*cos(i) + 0.2*sin(i);
        add( std::make_shared<Cheerio>( cheerio_inside_r, cheerio_outside_r,
                                        x * inside_radius, y * inside_radius, z ) );
        add( std::make_shared<Cheerio>( cheerio_inside_r, cheerio_outside_r,
                                        x * outside_radius, y * outside_radius, z ) );
    }
}

void Roadside::draw()
{
    //DBG_PRINT("draw()\n");
    glPushMatrix();
    { /* red rubber */
        GLfloat amb[]={0.05f,0.0f,0.0f,1.0f};
        GLfloat diff[]={0.7f,0.4f,0.4f,1.0f};
        GLfloat spec[]={0.7f,0.04f,0.04f,1.0f};
        GLfloat shine=10.0f;
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,amb);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diff);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spec);
        glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,shine);
    }
    GameObjectCollection::draw();
    glPopMatrix();
}

