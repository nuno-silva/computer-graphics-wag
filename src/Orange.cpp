#include "Orange.hpp"
#include <cmath>

Orange::Orange(GLdouble radius) : Orange(radius, 0, 0, 0) {}

Orange::Orange(GLdouble radius, GLdouble x, GLdouble y, GLdouble z) : _radius(radius) {
    setPosition(x, y, z);

    _stalk_width  = radius / 20.0f;
    _stalk_height = radius / 3.0f;
    // compute z axis offset (due to rotation)
    const GLdouble _stalk_z_offset = std::sin( DEG_TO_RAD(STALK_ROTATION) ) * _stalk_width;
    // these are relative to the orange's center
    _stalk_x = 0.0f;
    _stalk_y = 0.0f;
    _stalk_z = _stalk_height / 2.0f + _radius - _stalk_z_offset;

    _boundingSphere._radius = radius;
    _boundingSphere._center = getPosition();
}


void Orange::draw() {
    const GLint num_slices = 20;
    const GLint num_slacks = 20;

    glPushMatrix();
    GameObject::draw(); // translate to position

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

void Orange::processCollision(GameObject &go) {
    // Not yet implemented (or overloaded).
}
