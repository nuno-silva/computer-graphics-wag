#pragma once

#include "global.hpp"

#include "Entity.hpp"
#include "Vector3.hpp"

class Camera : public Entity {
    Vector3 _up, _center, _at;
protected:
    GLdouble _near;
    GLdouble _far;
public:
    Camera( GLdouble near, GLdouble far );
    ~Camera();
    void update();
    void computeProjectionMatrix();
    void computeVisualizationMatrix();
    const Vector3& getUp();
    const Vector3& getCenter();
    const Vector3& getAt();
};
