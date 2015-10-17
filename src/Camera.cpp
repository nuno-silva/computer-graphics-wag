#include "Camera.hpp"


Camera::Camera( GLdouble near, GLdouble far ) : Entity(),
    _up(0.0f, 1.0f, 1.0f), _center(0.0f, 0.0f, 0.0f), _near(near), _far(far) {}

Camera::Camera(Vector3 up, Vector3 center, GLdouble near, GLdouble far)
    : Entity(), _up(up), _center(center), _near(near), _far(far) {}

void Camera::update() {
    // TODO
}

void Camera::reshape( GLsizei w, GLsizei h ) {
    _width  = w;
    _height = h;
}

void Camera::computeProjectionMatrix() {
    DBG_PRINT("computeProjectionMatrix()\n");
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
}

void Camera::computeVisualizationMatrix() {
    DBG_PRINT("computeVisualizationMatrix()\n");
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

const Vector3& Camera::getUp()     const { return _up;     }
const Vector3& Camera::getCenter() const { return _center; }

