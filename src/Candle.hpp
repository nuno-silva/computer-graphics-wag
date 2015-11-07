#pragma once
#include "StaticObject.hpp"
#include "Vector3.hpp"

namespace CanldeColors {
    static constexpr GLfloat skin[3] = { 1.0f, 0.0f, 0.0f }; // Red
}

class Candle : public StaticObject {
protected:
    GLdouble _radius;

public:
    Candle(Vector3 pos);
    Candle(GLdouble x, GLdouble z, GLdouble y);
    Candle(Vector3 pos, GLdouble rad);
    Candle(GLdouble x, GLdouble z, GLdouble y, GLdouble rad);
    virtual void draw() override;

};