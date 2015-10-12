#pragma once

#include "GameObject.hpp"
#include "Vector3.hpp"

class DynamicObject : public GameObject {
protected:
    Vector3 _acceleration;
    Vector3 _speed;
    Vector3 _orientation;
public:
    DynamicObject();
    void update(GLdouble delta_t);

    void speedUp();
    void slowDown();
    void turnRight();
    void turnLeft();

    void setAcceleration(const Vector3& acceleration);
    void setAcceleration(GLdouble x, GLdouble y, GLdouble z);

    void setSpeed(const Vector3& acceleration);
    void setSpeed(GLdouble x, GLdouble y, GLdouble z);

    void setOrientation(const Vector3& orientation);
    void setOrientation(GLdouble x, GLdouble y, GLdouble z);

    Vector3 getAcceleration() const;
    Vector3 getSpeed() const;
    Vector3 getOrientation() const;

    virtual void draw() = 0;
};
