#pragma once

#include "DynamicObject.hpp"

class Obstacle : public DynamicObject {
    virtual void draw() = 0;
};
