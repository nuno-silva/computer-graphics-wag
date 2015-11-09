#include "CandleLight.hpp"

CandleLight::CandleLight( Vector3 pos, GLenum lightNum) : LightSource(lightNum)
{
    setPosition( pos );
    setDirection( Vector3( 0.0f, 0.0f, -1.0f ) );
    setAmbient( Vector4( 0.2f, 0.2f, 0.2f, 1.0f ) );
    setDiffuse( Vector4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    setSpecular(Vector4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    setCutoff( 90.0f );
    setExponent( 2.0f );
    setState( true );
}

void CandleLight::draw()
{
    glPushMatrix();


    glColor3f(1.0f, 1.0f, 0.9f);


    glPushMatrix();
    glTranslatef( 0.0f , 0.0f, cm(1)); // LightSource is at the top of the CandleLight
    LightSource::draw(); // LightSource already translates itself to position
    glPopMatrix();

    glTranslatef(_position[0] , _position[1], _position[2] + 0.5 * cm(1));

    glScalef(cm(0.25), cm(0.25), cm(1.5));
    glutSolidCube(1.0f);

    glPopMatrix();
}

