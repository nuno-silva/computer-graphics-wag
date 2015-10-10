#pragma once

#include "StaticObject.hpp"

class Cheerio : public StaticObject
{
public:
	Cheerio( GLdouble innerRadius,  GLdouble outerRadius );
	Cheerio( GLdouble innerRadius,  GLdouble outerRadius,
                    GLdouble x, GLdouble y, GLdouble z );
    virtual void draw();
	virtual void setWireframeState() override;
	void (_STDCALL*drawTorus) (GLdouble, GLdouble, GLint, GLint);
private:
    GLdouble _innerRadius;
    GLdouble _outerRadius;
};
