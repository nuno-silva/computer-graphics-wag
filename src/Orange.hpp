#pragma once

#include "global.hpp"
#include "StaticObject.hpp"

class Orange : public StaticObject {
private:
    GLdouble _radius;
public:
    Orange(GLdouble radius);
    Orange(GLdouble radius, GLdouble x, GLdouble y, GLdouble z);
    virtual void draw();
};
