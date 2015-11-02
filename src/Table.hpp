#pragma once

#include "global.hpp"
#include "StaticObject.hpp"

namespace TableColors {
    //static constexpr GLfloat table[3] = { 0.000f, 0.392f, 0.000f }; // DarkGreen
    static constexpr GLfloat table[3] = { 0.545f, 0.000, 0.000f }; // DarkRed
}

class Table : public StaticObject {
public:
    Table( GLdouble size );
    Table( GLdouble size, GLdouble x, GLdouble y, GLdouble z );
    virtual void draw() override;

    virtual bool checkCollision(GameObject &go);
    virtual void processCollision(Car &car);
private:
    GLdouble _size;
};
