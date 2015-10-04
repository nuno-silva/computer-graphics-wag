#include "Roadside.hpp"
#include "Cheerio.hpp"
#include <cstdio>
#include <cmath>

Roadside::Roadside( GLdouble size ) : _size(size) {
    const GLfloat cheerio_count = 25.0f;
    const GLfloat deg_inc = 2.0f * PI / cheerio_count;

    const GLfloat inside_radius = _size * 0.70f;
    const GLfloat outside_radius = _size;

    const GLfloat cheerio_inside_r = 0.011f;
    const GLfloat cheerio_outside_r = 0.02f;


    const GLfloat z = cheerio_inside_r / 2.0f;

    for ( GLfloat i = 0.0f; i < 2.0f * PI; i+=deg_inc ) {
        GLfloat x = sin(i);
        GLfloat y = 0.8*cos(i) + 0.2*sin(i);
        add( std::make_shared<Cheerio>( cheerio_inside_r, cheerio_outside_r,
                                        x * inside_radius, y * inside_radius, z ) );
        add( std::make_shared<Cheerio>( cheerio_inside_r, cheerio_outside_r,
                                        x * outside_radius, y * outside_radius, z ) );
    }
}

Roadside::~Roadside() {

}


//void draw_track_edge

void Roadside::draw()
{
    DBG_PRINT("draw()\n");
    glPushMatrix();
    GameObjectCollection::draw();
    glPopMatrix();
}

