#pragma once

#include "GameObjectCollection.hpp"

#define PI 3.14159265

class Roadside : public GameObjectCollection
{
public:
    Roadside( GLdouble size );
    virtual ~Roadside();
    virtual void draw();
        
private:
    GLdouble _size;
};
