#pragma once

#include "global.hpp"

#include "Entity.hpp"
#include "Vector3.hpp"


class Camera : public Entity {
    Vector3 _up, _center;
protected:
    GLdouble _near,  _far;
    GLsizei  _width, _height;
public:
    Camera( GLdouble near, GLdouble far );
    Camera(Vector3 up, Vector3 center, GLdouble near, GLdouble far);

    void update();
    void reshape( GLsizei width, GLsizei height );

    virtual void computeProjectionMatrix();
    virtual void computeVisualizationMatrix();

    const Vector3& getUp()     const;
    const Vector3& getCenter() const;
};
