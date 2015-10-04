#pragma once

#include "global.hpp"
#include "Obstacle.hpp"

class Orange : public Obstacle {
private:
    GLdouble _radius;
public:
    Orange(GLdouble radius);
    Orange(GLdouble radius, GLdouble x, GLdouble y, GLdouble z);
    virtual void draw();
};
