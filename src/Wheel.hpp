#pragma once

#include "DynamicObject.hpp"
class Wheel : public DynamicObject {
    GLdouble _inner_radius;
    GLdouble _outer_radius;
public:
    Wheel(GLdouble inner_radius, GLdouble outer_radius,
          GLdouble x, GLdouble y, GLdouble z);
    Wheel();
    
    void (_STDCALL*drawTorus) (GLdouble, GLdouble, GLint, GLint);
    virtual void setWireframeState() override;
    virtual void setState(GLdouble inner_radius, GLdouble outer_radius,
        GLdouble x, GLdouble y, GLdouble z);

    virtual void draw();
};
