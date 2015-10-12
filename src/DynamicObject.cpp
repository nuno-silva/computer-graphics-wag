#include "DynamicObject.hpp"
#include "Vector3.hpp"

#include <cmath>

#include <iostream>

#define ACCEL cm(2)

#define MAX_SPEED cm(20)

DynamicObject::DynamicObject() : _accel(0.0f), _speed(0.0f),
                                 _orientation(-1.0f, 0.0f, 0.0f) { }

DynamicObject::DynamicObject(Vector3 orientation) : DynamicObject()
{
    _orientation = orientation;
}

void DynamicObject::update(GLdouble delta_t) {
    GLdouble delta_t_s = delta_t/1000.0f;
    setWireframeState();

    Vector3 neg_x(-1.0f, 0.0f, 0.0f);
    if (_turnRight) {
        _turnRight = false;
        Vector3 unitZ = Vector3(0.0f, 0.0f, 1.0f);
        Vector3 left = _orientation.crossProduct(unitZ);
        Vector3 newOrient = _orientation + left;
        angle = newOrient.angleBetween(neg_x);
        _orientation = newOrient;
    } else if (_turnLeft) {
        _turnLeft = false;
        Vector3 unitZ = Vector3(0.0f, 0.0f, 1.0f);
        Vector3 right = unitZ.crossProduct(_orientation);
        Vector3 newOrient = _orientation + right;
        angle = newOrient.angleBetween(neg_x);
        _orientation = newOrient;
    }

    setPosition(getPosition() +
                _orientation * _speed * delta_t_s +
                _orientation * _accel * 0.5f * pow(delta_t_s, 2));

    _speed = _speed + _accel * delta_t_s;
    if(fabs(_speed) > MAX_SPEED) {
        std::cout << "MAX_SPEED" << std::endl;
        _speed -= _accel * delta_t_s;
    }


    if ((_speed > 0 && _accel > 0) || (_speed < 0 && _accel < 0)) {
        std::cout << "that strange if" << std::endl;
        _accel /= -10.0f;
    }
    std::cout << "pos: " << getPosition() << "; speed: " << _speed << "; accel: " << _accel << "; fabs speed: " << fabs(_speed)<< std::endl;
}

void DynamicObject::speedUp() {
    _accel = ACCEL;
}

void DynamicObject::slowDown() {
    _accel = -3.0f*ACCEL;
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


