#pragma once

#include "global.hpp"
#include "StaticObject.hpp"


class Table : public StaticObject {
public:
    Table( GLdouble size );
    Table( GLdouble size, GLdouble x, GLdouble y, GLdouble z );
    virtual void draw();
private:
    GLdouble _size;

    static constexpr GLfloat TABLE_COLOR[3]   = { 0.827f, 0.827f, 0.827f }; // LightGrey
};
