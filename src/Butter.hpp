#pragma once

#include "Obstacle.hpp"

class Butter : public Obstacle
{
public:
	Butter( GLdouble x, GLdouble y, GLdouble z );
    virtual ~Butter();
    virtual void draw();

    /* color definitions */
    static constexpr GLfloat wallColor[3]   = { 1.000f, 0.843f, 0.000f }; // Gold
    static constexpr GLfloat lidColor[3]  = { 1.0f, 0.627451f, 0.0f }; // Orange

    static constexpr GLfloat box_height = cm(8);
    static constexpr GLfloat lid_height = cm(1);
private:
};


