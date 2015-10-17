#pragma once

#include "global.hpp"

#include "Camera.hpp"

class OrthogonalCamera : public Camera {
    GLdouble _left;
    GLdouble _right;
    GLdouble _bottom;
    GLdouble _top;
public:
    OrthogonalCamera( GLdouble left, GLdouble right, GLdouble bottom,
                      GLdouble top, GLdouble near, GLdouble far );
    virtual void update();
    virtual void computeProjectionMatrix();
    virtual void computeVisualizationMatrix();
};
