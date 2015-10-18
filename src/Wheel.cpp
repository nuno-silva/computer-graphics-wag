#include "Wheel.hpp"

Wheel::Wheel(GLdouble inner_radius, GLdouble outer_radius,
             GLdouble x, GLdouble y, GLdouble z) : _inner_radius(inner_radius),
                                                   _outer_radius(outer_radius)
{
    setPosition(x, y, z);
}

Wheel::Wheel() : Wheel(0, 0, 0, 0, 0) { }

void Wheel::draw() {
    glPushMatrix();
    {
        getPosition().glTranslate();
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        drawTorus(_inner_radius, _outer_radius, 10, 10);
    }
    glPopMatrix();
}

void Wheel::setState(GLdouble inner_radius, GLdouble outer_radius, GLdouble x, GLdouble y, GLdouble z)
{
    this->_inner_radius = inner_radius;
    this->_outer_radius = outer_radius;
    setPosition(x, y, z);
}

