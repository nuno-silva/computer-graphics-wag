#include "Butter.hpp"


Butter::Butter( GLdouble x, GLdouble y, GLdouble z )
{
    setPosition( x, y, z );
}

Butter::~Butter() { }

void Butter::draw()
{
    glPushMatrix();
    glTranslatef( cm(0), cm(0), box_height/2 ); // butter origin is on the bottom face
    GameObject::draw(); // translate to position

    /* butter box */
    glColor3f( components3( wallColor) );
    glPushMatrix();
    glScalef( cm(14), cm(9), box_height );
    glutSolidCube( 1.0f ); // draw a 1x1 cube (now scaled)
    glPopMatrix();

    /* butter box lid */
    glColor3f( components3( lidColor ) );
    glPushMatrix();
    glTranslatef( cm(0), cm(0), box_height/2 + lid_height/2 );
    glScalef( cm(15), cm(10), lid_height );
    glutSolidCube( 1.0f );
    glPopMatrix();

    glPopMatrix();
}
