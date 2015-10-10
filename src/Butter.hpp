#pragma once

#include "Obstacle.hpp"

namespace ButterColors {
    static constexpr GLfloat box[3] = { 1.000f, 0.843f, 0.000f }; // Gold
    static constexpr GLfloat lid[3]  = { 1.0f, 0.627451f, 0.0f }; // Orange
}

class Butter : public Obstacle
{
public:
	Butter( GLdouble x, GLdouble y, GLdouble z );
    virtual ~Butter();
    virtual void draw();

    static constexpr GLfloat box_height = cm(8);
    static constexpr GLfloat lid_height = cm(1);
};


