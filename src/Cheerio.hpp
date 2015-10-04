#pragma once

#include "StaticObject.hpp"

class Cheerio : public StaticObject
{
public:
	Cheerio( GLdouble innerRadius,  GLdouble outerRadius );
	Cheerio( GLdouble innerRadius,  GLdouble outerRadius,
                    GLdouble x, GLdouble y, GLdouble z );
    virtual ~Cheerio();
    virtual void draw();

private:
    GLdouble _innerRadius;
    GLdouble _outerRadius;
};
