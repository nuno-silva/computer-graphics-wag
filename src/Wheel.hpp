#pragma once

#include "DynamicObject.hpp"
class Wheel : public DynamicObject {
    GLdouble _inner_radius;
    GLdouble _outer_radius;
public:
    Wheel(GLdouble inner_radius, GLdouble outer_radius,
          GLdouble x, GLdouble y, GLdouble z);
    Wheel();

    virtual void setState(GLdouble inner_radius, GLdouble outer_radius,
        GLdouble x, GLdouble y, GLdouble z);

    virtual void draw() override;

    virtual void processCollision(GameObject &go) override;
};
