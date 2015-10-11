#pragma once

#include "DynamicObject.hpp"
#include "global.hpp"
#include "Wheel.hpp"

#define NUM_WHEELS 4
class Car : public DynamicObject {
    GLdouble _scale = 1.0f;
public:
    // Car wheels radii
    // FIXME: Why do the wheels look so big?
    const GLdouble _wheel_inner_radius = _scale * cm(0.25);
    const GLdouble _wheel_outer_radius = 2      * _wheel_inner_radius;

    // Car elements dimensions
    const GLdouble _bottom_height      = 2      * _wheel_outer_radius;
    const GLdouble _bottom_length      = 5.25   * _bottom_height;
    const GLdouble _bottom_width       = 2      * _bottom_height;

    const GLdouble _top_height         = 0.75   * _bottom_height;
    const GLdouble _top_length         = 3      * _bottom_height;
    const GLdouble _top_width          = 2      * _top_height;

    Car( GLdouble scale, GLdouble x, GLdouble y, GLdouble z );
    Car( GLdouble scale );

    GLdouble getScale() const;

    virtual void draw() override;

    void (_STDCALL*drawCube) (GLdouble size);

    virtual void setWireframeState() override;
    virtual void update(GLdouble a) override;
    virtual void setDrawAsWireframe(bool value) override;
    virtual void drawWheels(GLdouble inner, GLdouble outer, GLdouble scal);

private:
    Wheel wheels[NUM_WHEELS] = { Wheel(), Wheel(), Wheel(), Wheel() };
};
