#include "PerspectiveCamera.hpp"
#include "Vector3.hpp"

PerspectiveCamera::PerspectiveCamera(const Vector3 &at, const Vector3 &up, const Vector3 &center,
                                     GLdouble fovy,
                                     GLdouble zNear,    GLdouble zFar)
    : Camera(at, up, center, zNear, zFar),
    _fovy(fovy), _zNear(zNear), _zFar(zFar) { }



void PerspectiveCamera::computeProjectionMatrix() {
    Camera::computeProjectionMatrix();
    DBG_PRINT("computeProjectionMatrix()\n");

    GLfloat ratio = (GLfloat) Camera::_width / (GLfloat) Camera::_height;
    gluPerspective(_fovy, ratio, _zNear, _zFar);
}


void PerspectiveCamera::computeVisualizationMatrix() {
    Camera::computeVisualizationMatrix();
    DBG_PRINT("computeVisualizationMatrix()\n");

    Vector3 at, center, up;

    at     = getPosition();
    center = getCenter();
    up     = getUp();

    gluLookAt( at.getX(),     at.getY(),     at.getZ(),
               center.getX(), center.getY(), center.getZ(),
               up.getX(),     up.getY(),     up.getZ() );
}
