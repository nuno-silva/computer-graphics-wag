#pragma once

#include "DynamicObject.hpp"
#include "Car.hpp"

namespace CheerioColors {
    static constexpr GLfloat cheerio[3] = { 1.000f, 0.973f, 0.863f }; // Cornsilk
}

class Cheerio : public DynamicObject
{
public:
    Cheerio( GLdouble innerRadius,  GLdouble outerRadius,
                    GLdouble x, GLdouble y, GLdouble z );
    virtual void draw() override;
    virtual void update(GLdouble delta_t) override;

    virtual void processCollision(Car &car) override;

    void setActive( bool value );
    bool isActive( );

private:
    GLdouble _innerRadius;
    GLdouble _outerRadius;
    GLdouble _isActive = true;
};
