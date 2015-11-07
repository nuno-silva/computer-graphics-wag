#include "Vector4.hpp"
#include <cmath>



Vector4::Vector4() : _x(0), _y(0), _z(0), _t(0) { }

Vector4::Vector4(GLdouble x, GLdouble y, GLdouble z, GLdouble t)
{
    _x = x;
    _y = y;
    _z = z;
    _t = t;
}

Vector4::~Vector4() { }


GLdouble Vector4::getX() const { return _x; }
GLdouble Vector4::getY() const { return _y; }
GLdouble Vector4::getZ() const { return _z; }
GLdouble Vector4::getT() const { return _t; }

void Vector4::set(GLdouble x, GLdouble y, GLdouble z, GLdouble t) { _x = x; _y = y; _z = z; _t = t; }

GLdouble Vector4::norm() const {
    GLdouble nrm;
    nrm = sqrt(pow2(_x) + pow2(_y) + pow2(_z) + pow2(_t));
    return nrm;
}

Vector4 Vector4::normalized() const
{
    GLdouble inverse_form = 1.0f / norm();
    return *this * inverse_form;
}

Vector4 Vector4::operator*(GLdouble num) const {
    return Vector4(getX() * num, getY() * num, getZ() * num, getT() * num);
}

Vector4 Vector4::operator+(const Vector4& vec) const {
    return Vector4(getX() + vec.getX(), getY() + vec.getY(), getZ() + vec.getZ(), getT() + vec.getT());
}

Vector4 Vector4::operator-(const Vector4& vec) const {
    return Vector4(getX() - vec.getX(), getY() - vec.getY(), getZ() - vec.getZ(), getT() - vec.getT());
}

bool Vector4::operator==(const Vector4 & v) const {
    return _x == v.getX() && _y == v.getY() && _z == v.getZ() && _t == v.getT();
}

bool Vector4::operator!=(const Vector4 & v) const {
    return !(*this == v);
}

Vector4 Vector4::operator=(const Vector4 & vec) {
    set(vec.getX(), vec.getY(), vec.getZ(), vec.getT());
    return *this;
}

std::ostream & operator<<(std::ostream & os, const Vector4 & v) {
    return os << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ", " << v.getT() << ")";
}
