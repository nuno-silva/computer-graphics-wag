#pragma once

#include "global.hpp"
#include "Obstacle.hpp"

#define STALK_ROTATION 40

namespace OrangeColors {
    static constexpr GLfloat skin[3]  = { 1.0f, 0.627451f, 0.0f }; // Orange
    static constexpr GLfloat stalk[3] = { 0.000f, 0.392f, 0.000f }; // DarkGreen
}

class Orange : public Obstacle {
private:
    GLdouble _radius, _stalk_width, _stalk_height, _stalk_z_offset;

public:
    Orange(GLdouble radius);
    Orange(GLdouble radius, GLdouble x, GLdouble y, GLdouble z);
    virtual void draw() override;
    virtual void processCollision(GameObject &go) override;

};
