#pragma once
#include "StaticObject.hpp"
#include "Vector3.hpp"
#include "CandleLight.hpp"

namespace CanldeColors {
    static constexpr GLfloat skin[3] = { 1.0f, 0.0f, 0.0f }; // Red
}

class Candle : public StaticObject {
protected:
    GLdouble _radius;
    CandleLight _light = CandleLight(Vector3(0, 0, 0), Vector3(0.0f, 0.0f, 0), Vector4(1.0f, 1.0f, 1.0f, 1.0f), Vector4(0, 1.0f, 1.0f, 1.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f), 1.0f, 1.0f, 1);

public:
    Candle(Vector3 pos);
    Candle(GLdouble x, GLdouble z, GLdouble y);
    Candle(Vector3 pos, GLdouble rad);
    Candle(GLdouble x, GLdouble z, GLdouble y, GLdouble rad);
    LightSource* getLightSource();
    virtual void draw() override;

};