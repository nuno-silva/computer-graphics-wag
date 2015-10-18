#pragma once

#include "global.hpp"
#include "Camera.hpp"

class PerspectiveCamera : public Camera {
    GLdouble _fovy   = 90;
    GLdouble _aspect = 1;
    GLdouble _zNear  = 1;
    GLdouble _zFar   = 1;
public:
    PerspectiveCamera(const Vector3 &at, const Vector3 &up, const Vector3 &center,
                      GLdouble fovy,  GLdouble aspect,
                      GLdouble zNear, GLdouble zFar);
    PerspectiveCamera();

    virtual void update();
    virtual void computeProjectionMatrix();
    virtual void computeVisualizationMatrix();
};
