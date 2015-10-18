#include "Cheerio.hpp"

Cheerio::Cheerio( GLdouble innerRadius,  GLdouble outerRadius ) :
                    _innerRadius(innerRadius), _outerRadius(outerRadius) {}

Cheerio::Cheerio( GLdouble innerRadius,  GLdouble outerRadius,
                    GLdouble x, GLdouble y, GLdouble z ) :
                    _innerRadius(innerRadius), _outerRadius(outerRadius)
{
    setPosition( x, y, z );
}


void Cheerio::draw()
{
    glPushMatrix();
    GameObject::draw();

    glColor3f( components3(CheerioColors::cheerio) );
    drawTorus( _innerRadius, _outerRadius, 10, 10 );

    glPopMatrix();
}
