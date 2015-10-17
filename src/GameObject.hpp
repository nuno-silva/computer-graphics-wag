#pragma once

#include <functional>

#include "global.hpp"

#include "Entity.hpp"

class GameObject : public Entity {
public:
    virtual void draw() = 0;
    virtual void update(GLdouble delta_t );

    void toggleWiredSolid();
    void setWired();
    void setSolid();

protected:
    bool _wired = false;

    std::function<void(GLdouble)>                         drawCube   = glutSolidCube;
    std::function<void(GLdouble, GLint, GLint)>           drawSphere = glutSolidSphere;
    std::function<void(GLdouble, GLdouble, GLint, GLint)> drawTorus  = glutSolidTorus;
};

