#include "Camera.hpp"


Camera::Camera( GLdouble near, GLdouble far ) : Entity(),
    // FIXME: should this be fixed?
    _up( (GLdouble) 0.0f, (GLdouble) 1.0f, (GLdouble) 0.0f ),
    _center( (GLdouble) 0.0f, (GLdouble) 0.0f, (GLdouble) 0.0f ),
    _at( (GLdouble) 0.0f, (GLdouble) 0.0f, (GLdouble) -1.9f )
{
    _near = near;
    _far = far;
}

Camera::~Camera() {

}

void Camera::update() {
    // TODO
}

void Camera::computeProjectionMatrix() {
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
}

void Camera::computeVisualizationMatrix() {
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

const Vector3& Camera::getAt()
{
    return _at;
}

