#pragma once

#include "DynamicObject.hpp"

class Wheel : public DynamicObject {
public:
    static constexpr GLdouble WHEEL_OUTER_RADIUS = 0.005f;
    static constexpr GLdouble WHEEL_INNER_RADIUS = 0.003f;

    Wheel(GLdouble x, GLdouble y, GLdouble z);
    virtual void draw();
	void (_STDCALL*drawTorus) (GLdouble, GLdouble, GLint, GLint);
	virtual void setWireframeState() override;
};
