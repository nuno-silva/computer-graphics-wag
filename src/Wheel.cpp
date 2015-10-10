#include "Wheel.hpp"

Wheel::Wheel(GLdouble inner_radius, GLdouble outer_radius,
             GLdouble x, GLdouble y, GLdouble z) : _inner_radius(inner_radius),
                                                   _outer_radius(outer_radius)
{
    setPosition(x, y, z);
}

void Wheel::draw() {
    glPushMatrix();
    {
        getPosition().glTranslate();
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glutSolidTorus(_inner_radius, _outer_radius, 40, 40);
    }
    glPopMatrix();
}
