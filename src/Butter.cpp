#include "Butter.hpp"


Butter::Butter( GLdouble x, GLdouble y, GLdouble z )
{
    setPosition( x, y, z );
}

Butter::~Butter() { }

void Butter::draw()
{
	glPushMatrix();
	GameObject::draw(); // translate to position
    glTranslatef( cm(0), cm(0), cm(8.0f/2) ); // butter origin is on the bottom face

    /* butter box */
    glColor3f( components3( wallColor) );
    glPushMatrix();
    glScalef( cm(14), cm(9), cm(8) );
    glutSolidCube( 1.0f ); // draw a 1x1 cube (now scaled)
    glPopMatrix();

    /* butter box lid */
    glColor3f( components3( lidColor ) );
    glPushMatrix();
    glTranslatef( cm(0), cm(0), cm(8.0f/2 + 1.0f/2) );
    glScalef( cm(15), cm(10), cm(1) );
    glutSolidCube( 1.0f );
    glPopMatrix();

    glPopMatrix();
}
