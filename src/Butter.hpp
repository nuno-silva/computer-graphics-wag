#pragma once

#include "Obstacle.hpp"

class Butter : public Obstacle
{
public:
	Butter( GLdouble x, GLdouble y, GLdouble z );
    virtual ~Butter();
    virtual void draw();

    /* color definitions */
    static constexpr GLfloat wallColor[3]   = { 0.941f, 0.902f, 0.549f }; // Khaki
    static constexpr GLfloat lidColor[3]  = { 0.980f, 0.980f, 0.824f }; // LightGoldenrodYellow

private:
};


