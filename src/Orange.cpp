#include "Orange.hpp"

#define SLICES 10
#define STACKS 10

Orange::Orange(GLdouble radius) : Orange(radius, 0, 0, 0) {}

Orange::Orange(GLdouble radius, GLdouble x, GLdouble y, GLdouble z) : _radius(radius) {
    setPosition(x, y, z);
}

void Orange::draw() {
    glPushMatrix();
    GameObject::draw();

    glColor3f( 1.0f, 0.4f, 0.0f);
    glutSolidSphere(_radius, SLICES, STACKS);

#ifdef DEBUG
    glColor3f(0.5f, 0.2f, 0.0f);
    glutWireSphere(2.0f);
#endif
    glPopMatrix();
};
