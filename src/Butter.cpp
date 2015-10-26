#include "Butter.hpp"


Butter::Butter( GLdouble x, GLdouble y, GLdouble z )
{
    setPosition( x, y, z );
#if defined DEBUG
    _axis_size = box_length * 1.5f;
#endif
    _boundingSphere._radius = box_length / 2.0f;
    _boundingSphere._center = getPosition() + Vector3( 0.0f, 0.0f, box_height/2 + lid_height/2 );
}

void Butter::draw()
{
    glPushMatrix();
    GameObject::draw(); // translate to position
    glTranslatef( cm(0), cm(0), box_height/2 ); // butter origin is on the bottom face

    /* butter box */
    glColor3f( components3( ButterColors::box ) );
    glPushMatrix();
    glScalef( box_width, box_length, box_height );
    GameObject::drawCube( 1.0f ); // draw a 1x1 cube (now scaled)
    glPopMatrix();

    /* butter box lid */
    glPushMatrix();
    glTranslatef( cm(0), cm(0), box_height/2 + lid_height/2 );
    glColor3f( components3( ButterColors::lid ) );
    glScalef( lid_width, lid_length, lid_height );
    GameObject::drawCube( 1.0f );
    glPopMatrix();

    glPopMatrix();
}

void Butter::processCollision(Car &car) {
    GLdouble speed = car.getSpeed() * 0.5f;

    if( speed > 0.0f ) {
        Vector3 orientation = car.getOrientation();
        setSpeed( speed );
        setOrientation( orientation );

        car.stop();
    }
}
