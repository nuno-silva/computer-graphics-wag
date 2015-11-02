#include "OrthogonalCamera.hpp"

OrthogonalCamera::OrthogonalCamera( GLdouble left, GLdouble right,
                                    GLdouble bottom, GLdouble top,
                                    GLdouble near, GLdouble far )
    : Camera( Vector3(0, 0, 1), near, far ), _left(left), _right(right),
      _bottom(bottom), _top(top) {}



void OrthogonalCamera::computeProjectionMatrix() {
    Camera::computeProjectionMatrix();
    //DBG_PRINT("computeProjectionMatrix()\n");

    GLfloat ratio = (GLfloat) Camera::_width / (GLfloat) Camera::_height;

    if( _width > _height ) {
        glOrtho( _left * ratio, _right * ratio, _bottom, _top,
             Camera::_near, Camera::_far );
    } else {
        glOrtho( _left, _right, _bottom / ratio, _top / ratio,
             Camera::_near, Camera::_far );
    }
}

void OrthogonalCamera::computeVisualizationMatrix() {
    Camera::computeVisualizationMatrix();
    //DBG_PRINT("computeVisualizationMatrix()\n");

    Vector3 at, center, up;
    at = getPosition();
    center = getCenter();
    up = getUp();

    /*DBG_PRINTF("gluLookAt( %.3f, %.3f, %.3f,  %.3f, %.3f, %.3f,  %.3f, %.3f, %.3f );\n",
                    at.getX(), at.getY(), at.getZ(),
                    center.getX(), center.getY(), center.getZ(),
                    up.getX(), up.getY(), up.getZ() );
    */
    gluLookAt( at.getX(), at.getY(), at.getZ(),
                center.getX(), center.getY(), center.getZ(),
                up.getX(), up.getY(), up.getZ() );
}
