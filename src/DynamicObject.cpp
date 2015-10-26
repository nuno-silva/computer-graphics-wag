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

void DynamicObject::stop() {
    setTurnRight( false );
    setTurnLeft( false );
    setSpeed( 0.0f );
    setAccel( 0.0f );
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

/** should be used by objects which need either _angleX or _angleZ */
void DynamicObject::draw() {
    // translate to the object's position
    // subclasses should call gl[Push|Pop]Matrix
    getPosition().glTranslate();

    // Only rotate if needed
    if (_angleX != 0) {
        glRotatef(_angleX, 1.0f, 0.0f, 0.0f);
    }
    // Only rotate if needed
    if(_angleZ != 0) {
        glRotatef(_angleZ, 0.0f, 0.0f, 1.0f);
    }

#if defined DEBUG
    Axis3d_draw(_axis_size);
    drawBoundingSphere();
#endif
}


void DynamicObject::setPosition(GLdouble x, GLdouble y, GLdouble z) {
    Vector3 newPos = Vector3(x, y, z);
    Vector3 offset = newPos - getPosition();
    _boundingSphere._center = _boundingSphere._center + offset;

    Entity::setPosition( newPos );
}

void DynamicObject::setPosition(const Vector3 & p) {
    Vector3 offset = p - getPosition();
    _boundingSphere._center = _boundingSphere._center + offset;

    Entity::setPosition( p );
}

void DynamicObject::resetInitPosition()
{
    _boundingSphere._center = _boundingSphere._initCenter;
    Entity::setPosition(_initPosition);
}

void DynamicObject::resetInitOrientation()
{
    setOrientation(_initOrientation);
}
