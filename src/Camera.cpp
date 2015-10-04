#include "Camera.hpp"


Camera::Camera( GLdouble near, GLdouble far ) : Entity(),
    // FIXME: should this be fixed?
    _up( (GLdouble) 0.0f, (GLdouble) 1.0f, (GLdouble) 0.0f ),
    _center( (GLdouble) 0.0f, (GLdouble) 0.0f, (GLdouble) 0.0f )
{
    _near = near;
    _far = far;
}

Camera::~Camera() {

}

void Camera::update() {
    // TODO
}

void Camera::reshape( GLsizei w, GLsizei h ) {
    _width = w;
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


const Vector3& Camera::getUp()
{
    return _up;
}

const Vector3& Camera::getCenter()
{
    return _center;
}

