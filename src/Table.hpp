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
};
