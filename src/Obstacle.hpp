#pragma once

#include "DynamicObject.hpp"
#include "Vector3.hpp"

//TODO: is this class really needed?

class Obstacle : public DynamicObject {
public:
    Obstacle();
    Obstacle(Vector3 orientation);
    virtual void draw() = 0;
};
