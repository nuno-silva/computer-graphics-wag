#pragma once
#include "global.hpp"

class Vector3 {
protected:
    GLdouble _x;
    GLdouble _y;
    GLdouble _z;

public:
    Vector3();
    Vector3(GLdouble x, GLdouble y, GLdouble z);
    ~Vector3();
    GLdouble getX() const;
    GLdouble getY() const;
    GLdouble getZ() const;
    void set(GLdouble x, GLdouble y, GLdouble z);
    Vector3 operator=(const Vector3& vec);
    Vector3 operator*(GLdouble num);
    Vector3 operator+(const Vector3&);
    Vector3 operator-(const Vector3&);

};
