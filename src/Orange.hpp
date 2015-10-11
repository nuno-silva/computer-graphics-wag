#pragma once

#include "global.hpp"
#include "Obstacle.hpp"


namespace OrangeColors {
    static constexpr GLfloat skin[3]  = { 1.0f, 0.627451f, 0.0f }; // Orange
}

class Orange : public Obstacle {
private:
    GLdouble _radius;
public:
    Orange(GLdouble radius);
    Orange(GLdouble radius, GLdouble x, GLdouble y, GLdouble z);
    virtual void draw();
    void (_STDCALL* drawSphere)(GLdouble, GLint, GLint);
    virtual void setWireframeState() override;

};
