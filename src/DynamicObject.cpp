#include "DynamicObject.hpp"
#include "Vector3.hpp"

#include <cmath>

#include <iostream>

DynamicObject::DynamicObject() : _acceleration(0.0f, 0.0f, 0.0f),
                                 _speed(0.0f, 0.0f, 0.0f),
                                 _orientation(-1.0f, 0.0f, 0.0f) { }

DynamicObject::DynamicObject(Vector3 orientation) : DynamicObject()
{
    _orientation = orientation;
}

void DynamicObject::update(GLdouble delta_t) {
    setWireframeState();

    setPosition(getPosition() + _speed * delta_t +
                    _acceleration * 0.5f * pow(delta_t, 2));
    std::cout << "Position: (" << getPosition().getX() << "," << getPosition().getY() << "," << getPosition().getZ() << ")" << std::endl;


    _speed = _speed + _acceleration * delta_t;

    // std::cout << "Speed: " << _speed.norm() << std::endl;

    if (_speed != nullVector) {
        _orientation  = _speed.normalized();
    }
    _acceleration = nullVector;
}

void DynamicObject::speedUp() {
    _acceleration = _orientation * 0.0001;
    // std::cout << "Accel: (" << _acceleration.getX() << "," << _acceleration.getY() << "," << _acceleration.getZ() << ")" << std::endl;
}

void DynamicObject::slowDown() {
    _acceleration = _orientation * (-0.0001);
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


