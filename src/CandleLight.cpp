#include "CandleLight.hpp"

CandleLight::CandleLight( Vector3 pos, GLenum lightNum) : LightSource(lightNum)
{
    setPosition( pos );
    setDirection( Vector3( 0.0f, 0.0f, -1.0f ) );
    setAmbient( Vector4( 0.3f, 0.3f, 0.3f, 1.0f ) );
    setDiffuse( Vector4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    setSpecular(Vector4( 1.0f, 1.0f, 1.0f, 1.0f ) );
    setCutoff( 90.0f );
    setExponent( 1.5f );
    setState( true );
}


