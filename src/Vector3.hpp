#pragma once
#include "global.hpp"
#include <iostream>

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

    GLdouble norm() const;
    Vector3 normalized() const;
    Vector3 crossProduct(Vector3 &v) const;

    Vector3 operator=(const Vector3& vec);
    Vector3 operator*(GLdouble num)   const;
    Vector3 operator+(const Vector3&) const;
    Vector3 operator-(const Vector3&) const;

    bool operator==(const Vector3 &) const;
    bool operator!=(const Vector3 &) const;

    friend std::ostream & operator<<(std::ostream &, const Vector3 &);

    /** glTranslate using this vector */
    void glTranslate() const;
};

const Vector3 nullVector(0,0,0);
