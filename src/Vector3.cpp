#include "Vector3.hpp"
#include <cmath>
#include <iostream>

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
#define pow2(x) pow(x, 2.0f)
    nrm = sqrt(  pow2(_x) + pow2(_y) + pow2(_z) );
    return nrm;
}

Vector3 Vector3::normalized() const {
    GLdouble inverse_norm = 1.0f / norm();
    Vector3 n = *this * inverse_norm;
    return n;
}


Vector3 Vector3::operator=(const Vector3 & vec) {
    _x = vec.getX();
    _y = vec.getY();
    _z = vec.getZ();

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
    auto x = v.getX();
    auto y = v.getY();
    auto z = v.getZ();

    return os << "(" << x << ", " << y << ", " << z << ")";
}
