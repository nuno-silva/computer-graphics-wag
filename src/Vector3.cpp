#include "Vector3.hpp"
#include <cmath>
#include <iostream>
#include "global.hpp"

Vector3::Vector3() : _x(0), _y(0), _z(0) { }

Vector3::Vector3(GLdouble x, GLdouble y, GLdouble z) {
    _x = x;
    _y = y;
    _z = z;
}

Vector3::~Vector3() {}

GLdouble Vector3::getX() const { return _x; }
GLdouble Vector3::getY() const { return _y; }
GLdouble Vector3::getZ() const { return _z; }

void Vector3::set(GLdouble x, GLdouble y, GLdouble z) { _x = x; _y = y; _z = z; }


GLdouble Vector3::norm() const {
    GLdouble nrm;
    nrm = sqrt(  pow2(_x) + pow2(_y) + pow2(_z) );
    return nrm;
}

Vector3 Vector3::normalized() const {
    GLdouble inverse_norm = 1.0f / norm();
    return *this * inverse_norm;
}

Vector3 Vector3::crossProduct(Vector3 &v) const {
    Vector3 cross;
    /* @see https://en.wikipedia.org/wiki/Cross_product#Mnemonic */
    GLdouble x = ( this->getY() * v.getZ() - v.getY() * this->getZ() );
    GLdouble y = ( this->getZ() * v.getX() - v.getZ() * this->getX() );
    GLdouble z = ( this->getX() * v.getY() - v.getX() * this->getY() );
    cross.set( x, y, z );
    return cross;
}

/** Computes the angle between two vectors in 2D, ignoring their Z value.
 *  @returns an angle in degrees
 */
GLdouble Vector3::angleBetweenZ(Vector3 & v) const
{
    GLdouble angle = atan2(getY(), getX()) - atan2(v.getY(), v.getX());
    angle = angle * 180 / PI;
    if (angle < 0){
        angle = angle + 360;
    }
    return angle;
}


Vector3 Vector3::operator=(const Vector3 & vec) {
    set(vec.getX(), vec.getY(), vec.getZ());
    return *this;
}

Vector3 Vector3::operator*(GLdouble num) const {
    return Vector3(getX() * num, getY() * num, getZ() * num);
}

Vector3 Vector3::operator+(const Vector3& vec) const {
    return Vector3(getX() + vec.getX(), getY() + vec.getY(), getZ() + vec.getZ());
}

Vector3 Vector3::operator-(const Vector3& vec) const {
    return Vector3(getX() - vec.getX(), getY() - vec.getY(), getZ() - vec.getZ());
}

bool Vector3::operator==(const Vector3 & v) const {
    return _x == v.getX() && _y == v.getY() && _z == v.getZ();
}

bool Vector3::operator!=(const Vector3 & v) const {
    return !(*this == v);
}

void Vector3::glTranslate() const {
    glTranslatef( _x, _y, _z );
}

std::ostream & operator<<(std::ostream & os, const Vector3 & v) {
    return os << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
}
