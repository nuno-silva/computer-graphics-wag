#pragma once

#include "Obstacle.hpp"
#include "Car.hpp"
#include <vector>

namespace ButterColors {
    static constexpr GLfloat lid[3] = { 1.000f, 0.843f, 0.000f }; // Gold
    static constexpr GLfloat box[3]  = { 1.0f, 1.0f, 0.787f }; // LightYellow
}

class Butter : public Obstacle
{
public:
    Butter( GLdouble x, GLdouble y, GLdouble z );
    virtual void draw() override;
    static constexpr GLfloat butter_scale = 0.5f;
    static constexpr GLfloat box_width  = cm(4) * butter_scale;
    static constexpr GLfloat box_length = cm(6) * butter_scale;
    static constexpr GLfloat box_height = cm(4) * butter_scale;

    static constexpr GLfloat lid_width  = cm(5) * butter_scale;
    static constexpr GLfloat lid_length = cm(7) * butter_scale;
    static constexpr GLfloat lid_height = cm(1) * butter_scale;

    virtual void update(GLdouble delta_t) override;
    virtual void processCollision(Car &car) override;
};
