#pragma once

#include "global.hpp"
#include "Obstacle.hpp"

#define STALK_ROTATION  40 // in degrees

// rotate orange so the stalk is not completely on top
#define ORANGE_ROTATION 40 // in degrees

namespace OrangeColors {
    static constexpr GLfloat skin[3]  = { 1.0f, 0.627451f, 0.0f }; // Orange
    static constexpr GLfloat stalk[3] = { 0.000f, 0.392f, 0.000f }; // DarkGreen
}

class Orange : public Obstacle {
private:
    GLdouble _radius, _stalk_width, _stalk_height;
    GLdouble _stalk_x, _stalk_y, _stalk_z;
    GLdouble _isActive = false;
public:
    Orange(GLdouble radius);
    Orange(GLdouble radius, GLdouble x, GLdouble y, GLdouble z);
    virtual void setPosition(const Vector3& p) override;
    virtual void draw() override;
    void setActive( bool value );
    bool isActive( );
    virtual void processCollision(GameObject &go) override;
};
