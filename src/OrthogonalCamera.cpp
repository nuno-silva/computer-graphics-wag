#include "OrthogonalCamera.hpp"

OrthogonalCamera::OrthogonalCamera( GLdouble left, GLdouble right,
                                    GLdouble bottom, GLdouble top,
                                    GLdouble near, GLdouble far ) :
                                    Camera( near, far )
{
    _left = left;
    _right = right;
    _bottom = bottom;
    _top = top;
}

OrthogonalCamera::~OrthogonalCamera() {

}

void OrthogonalCamera::update() {
    Camera::update();
    // TODO
}

void OrthogonalCamera::computeProjectionMatrix() {
    Camera::computeProjectionMatrix();

    glOrtho( _left, _right, _bottom, _top,
             Camera::_near, Camera::_far );
}

void OrthogonalCamera::computeVisualizationMatrix() {
    Camera::computeVisualizationMatrix();

    Vector3 at, center, up;
    at = getAt();
    center = getCenter();
    up = getUp();

    gluLookAt( at.getX(), at.getY(), at.getZ(),
                center.getX(), center.getY(), center.getZ(),
                up.getX(), up.getY(), up.getZ() );
}
