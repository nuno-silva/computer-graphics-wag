#include "Cheerio.hpp"

Cheerio::Cheerio( GLdouble innerRadius,  GLdouble outerRadius ) :
                    _innerRadius(innerRadius), _outerRadius(outerRadius)
{
	setWireframeState();
}

Cheerio::Cheerio( GLdouble innerRadius,  GLdouble outerRadius,
                    GLdouble x, GLdouble y, GLdouble z ) :
                    _innerRadius(innerRadius), _outerRadius(outerRadius)
{
    setPosition( x, y, z );
	setWireframeState();
}


void Cheerio::draw()
{
	glPushMatrix();
	GameObject::draw();

    glColor3f( 1.0f, 0.33f, 0.0f );
    drawTorus( _innerRadius, _outerRadius, 10, 10 );

    glPopMatrix();
}

void Cheerio::setWireframeState()
{
    // NOTE: duplicate code, consider deriving Cheerio and Wheel from
	// same base class.
	if (drawAsWireframe) {
		drawTorus = glutWireTorus;
	}
	else {
		drawTorus = glutSolidTorus;
	}   
}
