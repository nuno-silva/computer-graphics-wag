#pragma once
#include "global.hpp"
#include "LightSource.hpp"

class CandleLight : public LightSource {

public:
    CandleLight(Vector3 pos, GLenum lightNum);
    virtual void draw() override;

};
