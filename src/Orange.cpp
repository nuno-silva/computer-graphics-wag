#include "Orange.hpp"

#include <cmath>
#include <iostream>

Orange::Orange(GLdouble radius) : Orange(radius, 0, 0, 0) {}

Orange::Orange(GLdouble radius, GLdouble x, GLdouble y, GLdouble z) :
                Obstacle( Vector3(0.0f, 1.0f, 0.0f) ),
                _radius(radius)
 {
    Entity::setPosition(x, y, z); // set position without updating _angleX

    _stalk_width  = radius / 20.0f;
    _stalk_height = radius / 3.0f;
    // compute z axis offset (due to rotation)
    const GLdouble _stalk_z_offset = std::sin( DEG_TO_RAD(STALK_ROTATION) ) * _stalk_width;
    // these are relative to the orange's center
    _stalk_x = 0.0f;
    _stalk_y = 0.0f;
    _stalk_z = _stalk_height / 2.0f + _radius - _stalk_z_offset;

#if defined DEBUG
    _axis_size = radius * 1.5f;
#endif

    _boundingSphere._radius = radius;
    _boundingSphere._center = getPosition();
}

/** sets the Orange's position and rotates it */
void Orange::setPosition(const Vector3& p) {
    Vector3 oldPos = getPosition();
    // rotate orange as it moves.
    GLdouble distance = (p - oldPos).norm();
    // The X axis and _orientation are orthogonal, so we only need to rotate around X.
    _angleX -= fmod( RAD_TO_DEG( distance / _radius ), (GLdouble)360.0f );
    Entity::setPosition(p);
}

void Orange::draw() {
    const GLint num_slices = 20;
    const GLint num_slacks = 20;


    if( !_isActive ) {
        DBG_PRINTF( "draw() ignoring inactive Orange %p\n", (void*)this );
        return; // ignore inactive Orange
    }

    glPushMatrix();
    DynamicObject::draw(); // translate to position, rotate and draw axis

    // rotate orange so the stalk is not completely on top
    glRotatef(ORANGE_ROTATION, 0.0f, 1.0f, 0.0f);

    glColor3f( components3( OrangeColors::skin ));
    drawSphere(_radius, num_slices, num_slacks);


    glPushMatrix();
    { // draw orange stalk
        glTranslatef( _stalk_x, _stalk_y, _stalk_z );
        glColor3f( components3( OrangeColors::stalk ));
        glRotatef(STALK_ROTATION, 0.0f, 1.0f, 0.0f);
        glScalef( _stalk_width, _stalk_width, _stalk_height );
        drawCube( 1.0f );
    }
    glPopMatrix();

    glPopMatrix();
}

void Orange::setActive( bool value ) {
    DBG_PRINTF( "%p -> setActive( %s )\n", (void*)this, value ? "true":"false" );
    std::cout << "pos: " << getPosition() << std::endl;
    std::cout << "speed: " << getSpeed() << std::endl;
    std::cout << "orientation: " << getOrientation() << std::endl;
    _isActive = value;
}

bool Orange::isActive( ) {
    return _isActive;
}


void Orange::processCollision(Car &go) {
    // TODO
}
