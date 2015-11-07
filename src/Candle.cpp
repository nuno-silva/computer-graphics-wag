#include "Candle.hpp"

Candle::Candle(Vector3 pos) : Candle(pos, 0.0f) { }

Candle::Candle(GLdouble x, GLdouble z, GLdouble y) : Candle(x, y, z, 0.0f) { }

Candle::Candle(Vector3 pos, GLdouble rad) : _radius(rad)
{
    setPosition(pos);
}

Candle::Candle(GLdouble x, GLdouble z, GLdouble y, GLdouble rad) : _radius(rad)
{
    setPosition(x, y, z);
}

void Candle::draw() 
{
    const GLint num_slices = 20;
    const GLint num_slacks = 20;

    glPushMatrix();
    StaticObject::draw();

    glColor3f(components3(CanldeColors::skin));
    drawSphere(_radius, num_slices, num_slacks);
   
    
    {
        // draw candle's light
        // NOTE: candle's light does matrixPush/matrixPop
    }

    glPopMatrix();
}
