#pragma once

#include <functional>

#include "global.hpp"

#include "Entity.hpp"
#include "Vector3.hpp"

class Car;

struct BoundingSphere {
    BoundingSphere(GLdouble r, const Vector3 & c) : _radius(r), _center(c) {}
    BoundingSphere() : BoundingSphere(0, zeroVector) {}

    GLdouble _radius;
    Vector3  _center;
    Vector3  _initCenter;
};

class GameObject : public Entity {
    bool _alive     = true;
    int _collisions = 0;

protected:
    BoundingSphere _boundingSphere;
    bool _wired = false;

    std::function<void(GLdouble)>                         drawCube   = glutSolidCube;
    std::function<void(GLdouble, GLint, GLint)>           drawSphere = glutSolidSphere;
    std::function<void(GLdouble, GLdouble, GLint, GLint)> drawTorus  = glutSolidTorus;
public:
    GameObject();
    virtual void draw() = 0;
    virtual void update(GLdouble delta_t ) = 0;

    GLdouble getBoundingSphereRadius();
    Vector3 getBoundingSphereCenter();

    virtual bool checkCollision(GameObject &go);
    virtual void processCollision(Car &car);

    virtual void toggleWiredSolid();
    virtual void setWired();
    virtual void setSolid();

    inline void alive(bool a) { _alive = a; }
    inline bool alive() { return _alive; }
    inline int  collisions() { return _collisions; }
    inline void incCollisions() { _collisions++; }

#if defined DEBUG
    GLdouble _axis_size;
    void Axis3d_draw( GLdouble size );
    void drawBoundingSphere( );
#endif
};

