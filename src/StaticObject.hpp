#pragma once

#include "global.hpp"
#include "GameObject.hpp"

class StaticObject : public GameObject
{
public:
    virtual ~StaticObject();
    virtual void draw();
    void update( GLdouble delta_t );
};
