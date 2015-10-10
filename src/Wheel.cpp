#include "Wheel.hpp"

Wheel::Wheel(GLdouble x, GLdouble y, GLdouble z) {
    setPosition(x, y, z);
}

void Wheel::draw() {
    glPushMatrix();

    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glutSolidTorus(WHEEL_INNER_RADIUS, WHEEL_OUTER_RADIUS, 10, 10);

    glPopMatrix();
}
