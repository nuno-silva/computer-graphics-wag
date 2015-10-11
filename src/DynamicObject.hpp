#pragma once

#include "GameObject.hpp"
#include "Vector3.hpp"

class DynamicObject : public GameObject {
public:
    void update(GLdouble delta_t);

    void setSpeed(const Vector3& speed);
    void setSpeed(GLdouble x, GLdouble y, GLdouble z);

    Vector3 getSpeed() const;

    virtual void draw() = 0;
};
