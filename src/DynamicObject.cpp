#include "DynamicObject.hpp"

DynamicObject::DynamicObject() : _acceleration(0.0f, 0.0f, 0.0f),
                                 _speed(0.0f, 0.0f, 0.0f),
                                 _orientation(0.0f, 0.0f, 0.0f) { }

void DynamicObject::update(GLdouble delta_t) {
    (void) delta_t;
    setWireframeState();
}


/* acceleration */
void DynamicObject::setAcceleration(const Vector3 & acceleration) {
    _acceleration = acceleration;
}

void DynamicObject::setAcceleration(GLdouble x, GLdouble y, GLdouble z) {
    Vector3 v;
    v.set(x, y, z);
    _acceleration = v;
}

Vector3 DynamicObject::getAcceleration() const {
    return _acceleration;
}


/* speed */
void DynamicObject::setSpeed(const Vector3 & speed) {
    _speed = speed;
}

void DynamicObject::setSpeed(GLdouble x, GLdouble y, GLdouble z) {
    Vector3 v;
    v.set(x, y, z);
    _speed = v;
}

Vector3 DynamicObject::getSpeed() const {
    return _speed;
}


/* orientation */
void DynamicObject::setOrientation(const Vector3 & orientation) {
    _orientation = orientation;
}

void DynamicObject::setOrientation(GLdouble x, GLdouble y, GLdouble z) {
    Vector3 v;
    v.set(x, y, z);
    _orientation = v;
}

Vector3 DynamicObject::getOrientation() const {
    return _orientation;
}


