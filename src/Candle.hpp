#pragma once
#include "StaticObject.hpp"
#include "Vector3.hpp"
#include "CandleLight.hpp"

namespace CanldeColors {
    static constexpr GLfloat skin[3] = { 1.0f, 1.0f, 0.2f }; // yellow
}

class Candle : public StaticObject {
protected:
    GLdouble _radius;

public:
    Candle(Vector3 pos);
    Candle(GLdouble x, GLdouble y, GLdouble z);
    Candle(Vector3 pos, GLdouble rad);
    Candle(GLdouble x, GLdouble z, GLdouble y, GLdouble rad);
    virtual void draw() override;
    GLdouble getHeight();
};
