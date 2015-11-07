#pragma once
#include "global.hpp"
#include "LightSource.hpp"

class CandleLight : public LightSource {

    /*
        Note: it makes a lot more sense to use the Builder pattern here,
        but time is limited.
    */
public:
    CandleLight(Vector3 pos, Vector3 dir, Vector4 amb, Vector4 diffuse, Vector4 specular, GLdouble cut_off, GLdouble exponent, GLdouble number);
    virtual void draw() override;

protected:
    CandleLight(Vector3 pos, Vector3 dir, GLdouble number);

private:
    const GLfloat CUBE_SIZE = 1.0f;
};