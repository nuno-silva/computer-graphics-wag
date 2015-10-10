#pragma once

#include "DynamicObject.hpp"

class Car : public DynamicObject {
    GLdouble _width;
    GLdouble _length;
public:
    Car(GLdouble width, GLdouble length);

    GLdouble getWidth()  const;
    GLdouble getLength() const;

    virtual void draw();
};
