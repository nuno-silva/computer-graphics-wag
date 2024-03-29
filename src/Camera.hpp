#pragma once

#include "global.hpp"

#include "Entity.hpp"
#include "Vector3.hpp"


class Camera : public Entity {
private:
    Vector3 _up, _center;
protected:
    GLdouble _near,  _far;
    GLsizei  _width, _height;
    virtual void computeProjectionMatrix();
    virtual void computeVisualizationMatrix();
public:
    Camera( GLdouble near, GLdouble far );
    Camera(const Vector3 &at, GLdouble near, GLdouble far );
    Camera(const Vector3 &up, const Vector3 &center, GLdouble near, GLdouble far);
    Camera(const Vector3 &at, const Vector3 &up, const Vector3 &center, GLdouble near, GLdouble far);


    virtual void update();
    virtual void reshape( GLsizei width, GLsizei height );

    const Vector3& getUp()     const;
    const Vector3& getCenter() const;

    void setCenter(const Vector3 &center);
};
