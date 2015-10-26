#include "Cheerio.hpp"

Cheerio::Cheerio( GLdouble innerRadius,  GLdouble outerRadius,
                    GLdouble x, GLdouble y, GLdouble z ) :
                    _innerRadius(innerRadius), _outerRadius(outerRadius)
{
    setPosition( x, y, z );

#if defined DEBUG
    _axis_size = ( outerRadius + innerRadius ) * 1.5f;
#endif

    _boundingSphere._radius = outerRadius + innerRadius;
    _boundingSphere._center = getPosition();
}


void Cheerio::draw()
{
    glPushMatrix();
    GameObject::draw();

    glColor3f( components3(CheerioColors::cheerio) );
    drawTorus( _innerRadius, _outerRadius, 10, 10 );

    glPopMatrix();
}


void Cheerio::processCollision(Car &go) {
    //TODO
}
