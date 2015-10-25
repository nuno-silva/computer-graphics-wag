#pragma once

#include <functional>

#include "global.hpp"

#include "Entity.hpp"
#include "Vector3.hpp"

struct BoundingSphere {
    BoundingSphere(GLdouble r, const Vector3 & c) : _radius(r), _center(c) {}
    BoundingSphere() : BoundingSphere(0, zeroVector) {}

    GLdouble _radius;
    Vector3  _center;
};

class GameObject : public Entity {

protected:
    BoundingSphere _boundingSphere;
    Vector3 _boundingSpehereInitPosition;
    bool _wired = false;

    std::function<void(GLdouble)>                         drawCube   = glutSolidCube;
    std::function<void(GLdouble, GLint, GLint)>           drawSphere = glutSolidSphere;
    std::function<void(GLdouble, GLdouble, GLint, GLint)> drawTorus  = glutSolidTorus;
public:
    GameObject();
    virtual void draw() = 0;
    virtual void update(GLdouble delta_t ) = 0;

    virtual bool checkCollision(GameObject &go);
    virtual void processCollision(GameObject &go) = 0;

    virtual void toggleWiredSolid();
    virtual void setWired();
    virtual void setSolid();

#if defined DEBUG
    GLdouble _axis_size;
    void Axis3d_draw( GLdouble size );
#endif
};

