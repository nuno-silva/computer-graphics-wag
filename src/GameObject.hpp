#pragma once

#include "global.hpp"

#include "Entity.hpp"

class GameObject : Entity {

public:
    virtual ~GameObject();
    virtual void draw();
    void update( GLdouble delta_t );
};

