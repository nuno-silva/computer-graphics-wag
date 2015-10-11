#pragma once

#include "global.hpp"
#include "StaticObject.hpp"

namespace TableColors {
    static constexpr GLfloat table[3] = { 0.827f, 0.827f, 0.827f }; // LightGrey
}

class Table : public StaticObject {
public:
    Table( GLdouble size );
    Table( GLdouble size, GLdouble x, GLdouble y, GLdouble z );
    virtual void draw();
private:
    GLdouble _size;
};
