#pragma once

#include "global.hpp"

#include "Entity.hpp"
#include "Vector3.hpp"

class Camera : public Entity {
    Vector3 _up, _center, _at;
protected:
    GLdouble _near;
    GLdouble _far;
    GLsizei _width;
    GLsizei _height;
public:
    Camera( GLdouble near, GLdouble far );
    virtual ~Camera();
    void update();
    void reshape( GLsizei w, GLsizei h );
    virtual void computeProjectionMatrix();
    virtual void computeVisualizationMatrix();
    const Vector3& getUp();
    const Vector3& getCenter();
};
