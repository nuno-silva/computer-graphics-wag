#include "Butter.hpp"


Butter::Butter( GLdouble x, GLdouble y, GLdouble z )
{
    setPosition( x, y, z );
    setWireframeState();
}

Butter::~Butter() { setWireframeState(); }

void Butter::draw()
{
    glPushMatrix();
    GameObject::draw(); // translate to position
    glTranslatef( cm(0), cm(0), box_height/2 ); // butter origin is on the bottom face

    /* butter box */
    glColor3f( components3( ButterColors::box ) );
    glPushMatrix();
    glScalef( box_width, box_length, box_height );
    drawCube( 1.0f ); // draw a 1x1 cube (now scaled)
    glPopMatrix();

    /* butter box lid */
    glPushMatrix();
    glTranslatef( cm(0), cm(0), box_height/2 + lid_height/2 );
    glColor3f( components3( ButterColors::lid ) );
    glScalef( lid_width, lid_length, lid_height );
    drawCube( 1.0f );
    glPopMatrix();

    glPopMatrix();
}

void Butter::setWireframeState()
{
    if (drawAsWireframe) {
        drawCube = glutWireCube;
    }
    else {
        drawCube = glutSolidCube;
    }
}
