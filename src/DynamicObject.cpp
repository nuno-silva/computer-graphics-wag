#include "DynamicObject.hpp"
#include "Vector3.hpp"

#include <cmath>

#include <iostream>

DynamicObject::DynamicObject() : _acceleration(0.0f, 0.0f, 0.0f),
                                 _speed(0.0f, 0.0f, 0.0f),
                                 _orientation(-1.0f, 0.0f, 0.0f) { }

void DynamicObject::update(GLdouble delta_t) {
    setWireframeState();

    setPosition(getPosition() + _speed * delta_t +
                    _acceleration * 0.5f * pow(delta_t, 2));

    _speed = _speed + _acceleration * delta_t;
    // _orientation = _speed.normalize();
}

static void move(DynamicObject & o, const Vector3 & inc) {
    if (o.getAcceleration() != Vector3(0, 0, 0)) {
        o.setAcceleration(o.getAcceleration() + inc);
    } else {
        o.setAcceleration(o.getOrientation() + inc);
    }
}

void DynamicObject::speedUp() {
    move(*this, _orientation);
    std::cout << "(" << _acceleration.getX() << "," << _acceleration.getY() << "," << _acceleration.getZ() << ")" << std::endl;
}

void DynamicObject::slowDown() {
    move(*this, _orientation * (-1));
    std::cout << "(" << _acceleration.getX() << "," << _acceleration.getY() << "," << _acceleration.getZ() << ")" << std::endl;
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


