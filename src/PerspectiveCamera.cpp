#include "PerspectiveCamera.hpp"


PerspectiveCamera::PerspectiveCamera(GLdouble fovy,  GLdouble aspect,
                                     GLdouble zNear, GLdouble zFar)
    : _fovy(fovy), _aspect(aspect), _zNear(zNear), _zFar(zFar),
      Camera(zNear, zFar) {}

PerspectiveCamera::PerspectiveCamera() : Camera(1, 2) {
    // Empty.
}

void PerspectiveCamera::update() {
    Camera::update();
    // TODO
}

void PerspectiveCamera::computeProjectionMatrix() {
    Camera::computeProjectionMatrix();
    DBG_PRINT("computeProjectionMatrix()\n");

    gluPerspective(_fovy, _aspect, _zNear, _zFar);
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

