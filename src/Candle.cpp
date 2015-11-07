#include "Candle.hpp"

Candle::Candle(Vector3 pos) : Candle(pos, 0.0f) { }

Candle::Candle(GLdouble x, GLdouble z, GLdouble y) : Candle(x, y, z, 0.0f) { }

Candle::Candle(Vector3 pos, GLdouble rad) : _radius(rad)
{
    setPosition(pos);
    _light.setPosition(Vector3(pos.getX(), pos.getY(), pos.getZ() + rad));

}

Candle::Candle(GLdouble x, GLdouble z, GLdouble y, GLdouble rad) : _radius(rad)
{
    setPosition(x, y, z);
    _light.setPosition(Vector3(x, y, z + rad));
}

LightSource * Candle::getLightSource()
{
    return &_light;
}

void Candle::draw() 
{
    const GLint num_slices = 20;
    const GLint num_slacks = 20;

    glPushMatrix();
    StaticObject::draw();

    glColor3f(components3(CanldeColors::skin));
    glTranslatef(0.0f, 0.0f, _radius);
    drawSphere(_radius, num_slices, num_slacks);
   
    
    {
        // draw candle's light
        // NOTE: candle's light does matrixPush/matrixPop
        _light.draw();
    }

    glPopMatrix();
}
