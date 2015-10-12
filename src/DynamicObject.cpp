#include "DynamicObject.hpp"
#include "Vector3.hpp"

#include <cmath>

#include <iostream>

#define ACCEL 0.000001f
#define SPEED_LIMIT ACCEL

DynamicObject::DynamicObject() : _accel(0.0f), _speed(0.0f),
                                 _orientation(-1.0f, 0.0f, 0.0f) { }

DynamicObject::DynamicObject(Vector3 orientation) : DynamicObject()
{
    _orientation = orientation;
}

void DynamicObject::update(GLdouble delta_t) {
    setWireframeState();

    if (_turnRight) {
        _turnRight = false;
        Vector3 unitZ = Vector3(0.0f, 0.0f, 1.0f);
        Vector3 left = _orientation.crossProduct(unitZ);
        Vector3 newOrient = _orientation + left;
        angle = newOrient.angleBetween(Vector3(-1.0f, 0.0f, 0.0f));
        _orientation = newOrient;
    } else if (_turnLeft) {
        _turnLeft = false;
        Vector3 unitZ = Vector3(0.0f, 0.0f, 1.0f);
        Vector3 right = unitZ.crossProduct(_orientation);
        Vector3 newOrient = _orientation + right;
        angle = newOrient.angleBetween(Vector3(-1.0f, 0.0f, 0.0f));
        _orientation = newOrient;
    }

    setPosition(getPosition() +
                _orientation * _speed * delta_t +
                _orientation * _accel * 0.5f * pow(delta_t, 2));
    _speed = _speed + _accel * delta_t;
    _accel = 0;

}

void DynamicObject::speedUp() {
    _accel = ACCEL;
}

void DynamicObject::slowDown() {
    _accel = -ACCEL;
}

void DynamicObject::turnRight()
{
    _turnRight = true;
}

void DynamicObject::turnLeft()
{
    _turnLeft = true;
}



/* acceleration */
void DynamicObject::setAccel(GLdouble accel) {
    _accel = accel;
}

GLdouble DynamicObject::getAccel() const {
    return _accel;
}


/* speed */
void DynamicObject::setSpeed(GLdouble speed) {
    _speed = speed;
}

GLdouble DynamicObject::getSpeed() const {
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


