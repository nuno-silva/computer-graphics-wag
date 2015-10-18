#pragma once

#include "Obstacle.hpp"

namespace ButterColors {
    static constexpr GLfloat lid[3] = { 1.000f, 0.843f, 0.000f }; // Gold
    static constexpr GLfloat box[3]  = { 1.0f, 1.0f, 0.787f }; // LightYellow
}

class Butter : public Obstacle
{
public:
    Butter( GLdouble x, GLdouble y, GLdouble z );
    virtual void draw();

    static constexpr GLfloat box_width  = cm(4);
    static constexpr GLfloat box_length = cm(6);
    static constexpr GLfloat box_height = cm(4);

    static constexpr GLfloat lid_width  = cm(5);
    static constexpr GLfloat lid_length = cm(7);
    static constexpr GLfloat lid_height = cm(1);
};


