#include "DynamicObject.hpp"
#include "Vector3.hpp"

#include <cmath>

#include <iostream>

#define ACCEL cm(100)

#define MAX_SPEED cm(200)

DynamicObject::DynamicObject() : DynamicObject(Vector3(-1.0f, 0.0f, 0.0f)) { }

DynamicObject::DynamicObject(Vector3 orientation) : _accel(0.0f), _speed(0.0f),
                                                    _orientation(orientation),
                                                    _initOrientation(orientation),
                                                    _turnRight(false), _turnLeft(false)
{
    _initPosition = getPosition();
}

DynamicObject::DynamicObject(Vector3 orientation, GLdouble x, GLdouble y, GLdouble z) : DynamicObject(orientation)
{
    setPosition(x, y, z);
    _initPosition = getPosition();
}

DynamicObject::DynamicObject(Vector3 orientation, Vector3 position) : DynamicObject(orientation,
                                                                      position.getX(), position.getY(), position.getZ()) { }

DynamicObject::DynamicObject(GLdouble x, GLdouble y, GLdouble z) : DynamicObject()
{
    setPosition(x, y, z);
    _initPosition = getPosition();
}

void DynamicObject::update(GLdouble delta_t) {
    GLdouble delta_t_s = delta_t/1000.0f;

    Vector3 unitZ = Vector3(0.0f, 0.0f, 1.0f);

    if (_turnRight) {
        Vector3 left = _orientation.crossProduct(unitZ);
        Vector3 newOrient = _orientation + left * 3.0f * delta_t_s;
        setOrientation( newOrient );
    } else if (_turnLeft) {
        Vector3 right = unitZ.crossProduct(_orientation);
        Vector3 newOrient = _orientation + right * 3.0f * delta_t_s;
        setOrientation( newOrient );
    }

    const Vector3 sphere_offset =
        _orientation * _speed * delta_t_s +
        _orientation * _accel * 0.5f * pow(delta_t_s, 2);

    const Vector3 position_offset = getPosition() +
        sphere_offset;

    setPosition(position_offset);
    if (getSpeed() != 0) {
        _boundingSphere._center = _boundingSphere._center + sphere_offset;
    }
    _speed = _speed + _accel * delta_t_s;
    if(fabs(_speed) > MAX_SPEED) {
        std::cout << "MAX_SPEED" << std::endl;
        _speed -= _accel * delta_t_s;
    }

    if ((fabs(_speed) < cm(2)) && !isAccelerating()) {
        _speed = 0;
    }
}

void DynamicObject::setSpeedUp( bool value ) {
    _accel = value ? ACCEL : 0.0f;
}

void DynamicObject::setSlowDown( bool value ) {
    _accel = value ? -1 * ACCEL : 0.0f;
}

void DynamicObject::setTurnRight( bool value )
{
    _turnRight = value;
}

void DynamicObject::setTurnLeft( bool value )
{
    _turnLeft = value;
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
    _orientation = orientation.normalized();
    _angleZ = _orientation.angleBetweenZ( _initOrientation );
}

void DynamicObject::setOrientation(GLdouble x, GLdouble y, GLdouble z) {
    Vector3 v;
    v.set(x, y, z);
    setOrientation(v);
}

bool DynamicObject::isAccelerating()
{
    return _accel != 0.0f;
}

Vector3 DynamicObject::getOrientation() const {
    return _orientation;
}

void DynamicObject::resetInitPosition()
{
    setPosition(_initPosition);
}

void DynamicObject::resetInitOrientation()
{
    setOrientation(_initOrientation);
}

void DynamicObject::resetColSphereInitPosition()
{
}

