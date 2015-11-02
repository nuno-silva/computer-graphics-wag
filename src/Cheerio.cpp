#include "Cheerio.hpp"
#include <cmath>

Cheerio::Cheerio( GLdouble innerRadius,  GLdouble outerRadius,
                    GLdouble x, GLdouble y, GLdouble z ) :
                    _innerRadius(innerRadius), _outerRadius(outerRadius)
{
    setPosition( x, y, z );

#if defined DEBUG
    _axis_size = ( outerRadius + innerRadius ) * 1.5f;
#endif

    _boundingSphere._radius = outerRadius + innerRadius;
    _boundingSphere._initCenter = _boundingSphere._center = getPosition();
}


void Cheerio::draw()
{
    if( !_isActive ) {
        return; // ignore inactive Cheerio
    }

    glPushMatrix();
    GameObject::draw();

    glColor3f( components3(CheerioColors::cheerio) );
    drawTorus( _innerRadius, _outerRadius, 10, 10 );

    glPopMatrix();
}

void Cheerio::update(GLdouble delta_t) {
    DynamicObject::update(delta_t);
    if (getSpeed() < 0.0f) {
        stop();
    }

    const auto x = getPosition().getX();
    const auto y = getPosition().getY();

    if ( x < -1.0f || x > 1.0f || y < -1.0f || y > 1.0f) {
        setActive(false);
    }
}

void Cheerio::processCollision(Car &car) {
    GLdouble speed = car.getSpeed() * 1.1f;
    const auto reverse = (speed / fabs(speed) < 0);

    if( fabs(speed) > cm(2) ) {
        Vector3 orientation = car.getOrientation();

        if (reverse) {
            setOrientation( orientation * -1 );
            setSpeed( speed * -1 );
        } else {
            setOrientation( orientation );
            setSpeed( speed );
        }

        setAccel( cm(-40) );
        car.stop();
    }
}

void Cheerio::setActive( bool value ) {
    DBG_PRINTF( "%p -> setActive( %s )\n", (void*)this, value ? "true":"false" );
    _isActive = value;
}

bool Cheerio::isActive( ) {
    return _isActive;
}
