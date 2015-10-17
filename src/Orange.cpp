#include "Orange.hpp"

Orange::Orange(GLdouble radius) : Orange(radius, 0, 0, 0) {}

Orange::Orange(GLdouble radius, GLdouble x, GLdouble y, GLdouble z) : _radius(radius) {
    setPosition(x, y, z);
}

void Orange::draw() {
    const GLint num_slices = 20;
    const GLint num_slacks = 20;

    glPushMatrix();
    GameObject::draw();

    glColor3f( components3( OrangeColors::skin ));
    drawSphere(_radius, num_slices, num_slacks);
    glPopMatrix();
}
