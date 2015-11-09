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
    CandleLight _light;

public:
    Candle(Vector3 pos, GLenum lightNum);
    Candle(GLdouble x, GLdouble y, GLdouble z, GLenum lightNum);
    Candle(Vector3 pos, GLdouble rad, GLenum lightNum);
    Candle(GLdouble x, GLdouble z, GLdouble y, GLdouble rad, GLenum lightNum);
    virtual void draw() override;

};
