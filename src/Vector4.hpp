#pragma once
#include "global.hpp"
#include <iostream>

class Vector4
{
protected:
    GLdouble _x;
    GLdouble _y;
    GLdouble _z;
    GLdouble _t;
public:
    Vector4();
    Vector4(GLdouble x, GLdouble y, GLdouble z, GLdouble t);
    ~Vector4();

    GLdouble getX() const;
    GLdouble getY() const;
    GLdouble getZ() const;
    GLdouble getT() const;

    void set(GLdouble x, GLdouble y, GLdouble z, GLdouble t);
    GLdouble norm() const;
    Vector4 normalized() const;

    friend std::ostream &operator<<(std::ostream&, const Vector4&);
    Vector4 operator=(const Vector4& vec);
    Vector4 operator*(GLdouble num)   const;
    Vector4 operator+(const Vector4&) const;
    Vector4 operator-(const Vector4&) const;
    bool operator==(const Vector4 &) const;
    bool operator!=(const Vector4 &) const;

};
