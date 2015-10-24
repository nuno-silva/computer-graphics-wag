#pragma once

#include "DynamicObject.hpp"
#include "global.hpp"
#include "Wheel.hpp"
#include "IOnCollisionObserver.hpp"

#define NUM_WHEELS 4

namespace CarColors {
    static constexpr GLfloat wheels[3] = { 0.1f, 0.1f, 0.1f }; // grey-black-ish
    static constexpr GLfloat top[3]    = { 0.118f, 0.565f, 1.000f }; // DodgerBlue
    static constexpr GLfloat bottom[3] = { 0.255f, 0.412f, 0.882f }; // RoyalBlue
}

class Car : public DynamicObject, IOnCollision {
private:
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
    virtual void update(GLdouble delta_t) override;

    virtual void processCollision(GameObject &go) override;

    virtual void drawWheels();
    virtual void setWheelsState(GLdouble inner, GLdouble outer, GLdouble scale);

private:
    Wheel wheels[NUM_WHEELS] = { Wheel(), Wheel(), Wheel(), Wheel() };

    // Inherited via IOnCollision
    virtual void onStopCollision(GameObject & otherObj) override;
    virtual void onResetCollision(GameObject & otherObj) override;
};
