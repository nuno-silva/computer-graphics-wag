#include "Orange.hpp"

Orange::Orange(GLdouble radius) : Orange(radius, 0, 0, 0) {}

Orange::Orange(GLdouble radius, GLdouble x, GLdouble y, GLdouble z) : _radius(radius) {
    setPosition(x, y, z);

    _stalk_width  = radius / 20.0f;
    _stalk_height = radius / 3.0f;

    _boundingSphere._radius = radius;
    _boundingSphere._center = getPosition();
}


void Orange::draw() {
    const GLint num_slices = 20;
    const GLint num_slacks = 20;

    glPushMatrix();
    GameObject::draw(); // translate to position

    glColor3f( components3( OrangeColors::skin ));
    drawSphere(_radius, num_slices, num_slacks);


    glPushMatrix();
    { // draw orange stalk
        glTranslatef( 0.0f, 0.0f, _stalk_height / 2.0f + _radius );
        glColor3f( components3( OrangeColors::stalk ));
        glScalef( _stalk_width, _stalk_width, _stalk_height );
        drawCube( 1.0f );
    }
    glPopMatrix();

    glPopMatrix();
}

void Orange::processCollision(GameObject &go) {
    // Not yet implemented (or overloaded).
}
