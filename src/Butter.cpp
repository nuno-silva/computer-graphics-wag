#include "Butter.hpp"
#include <cmath>


Butter::Butter( GLdouble x, GLdouble y, GLdouble z )
{
    setPosition( x, y, z );
#if defined DEBUG
    _axis_size = box_length * 1.5f;
#endif
    _boundingSphere._radius = box_length / 2.0f;
    _boundingSphere._initCenter = _boundingSphere._center = getPosition() + Vector3( 0.0f, 0.0f, box_height/2 + lid_height/2 );
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

void Butter::update(GLdouble delta_t) {
    DynamicObject::update(delta_t);
    if (getSpeed() < 0.0f) {
        stop();
    }
}

void Butter::processCollision(Car &car) {
    GLdouble speed = car.getSpeed() * 0.5f;
    const auto reverse = (speed / fabs(speed) < 0);

    if( fabs(speed) > 0 ) {
        Vector3 orientation = car.getOrientation();

        if (reverse) {
            setOrientation( orientation * -1 );
            setSpeed( speed * -1 );
        } else {
            setOrientation( orientation );
            setSpeed( speed );
        }

        setAccel( cm(-80) );
        car.stop();
    }
}
