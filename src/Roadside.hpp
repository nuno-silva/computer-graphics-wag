#pragma once

#include "GameObjectCollection.hpp"

#define PI 3.14159265

class Roadside : public GameObjectCollection
{
public:
    Roadside( GLdouble size );
    virtual ~Roadside();
    virtual void draw();
    /*
    virtual void setDrawAsWireframe(bool val) override {
        std::cout << "HELLO!" << std::endl;
        GameObjectCollection::setDrawAsWireframe(val);
    }
    */
        
private:
    GLdouble _size;
};
