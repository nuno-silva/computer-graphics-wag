#include "Roadside.hpp"
#include <cstdio>
#include <cmath>

Roadside::~Roadside() {

}

void draw_cheerio( GLfloat x, GLfloat y, GLfloat z ) {
    glColor3f( 1.0f, 0.33f, 0.0f );
    glPushMatrix();
    glTranslatef( x, y, z );
    glutWireTorus( 0.011f, 0.02, 10, 10 );
    glPopMatrix();
}

//void draw_track_edge

void Roadside::draw()
{
    printf("Roadside::draw();\n");
    #warning this is not working. Use std::shared_ptr instead of pointers?
    // Rodrigo: Of course!


    const int cheerios_no = 100;

    const GLfloat inside_radius = 0.6f;
    const GLfloat outside_radius = 0.8f;

    const GLfloat z = +0.1f;

    // draw_track_edge
    for (int i = 0; i < cheerios_no; ++i) {
        GLfloat x = inside_radius * sin(i);
        GLfloat y = inside_radius * cos(i);
        draw_cheerio(x, y, z);
    }

    for (int i = 0; i < cheerios_no; ++i) {
        GLfloat x = outside_radius * sin(i);
        GLfloat y = outside_radius * cos(i);
        draw_cheerio(x, y, z);
    }

}

