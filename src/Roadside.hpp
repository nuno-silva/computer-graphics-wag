#pragma once

#include "GameObjectCollection.hpp"

class Roadside : public GameObjectCollection
{
public:
    Roadside( GLdouble size );
    virtual void draw() override;

private:
    GLdouble _size;
};
