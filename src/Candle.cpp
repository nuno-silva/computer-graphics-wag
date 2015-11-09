#include "Candle.hpp"

Candle::Candle(Vector3 pos, GLenum lightNum) : Candle(pos, cm(2), lightNum) { }

Candle::Candle(GLdouble x, GLdouble y, GLdouble z, GLenum lightNum) : Candle(Vector3(x,y,z), lightNum) { }

Candle::Candle(Vector3 pos, GLdouble rad, GLenum lightNum) :
               _radius(rad), _light(Vector3(0, 0, 0), lightNum)
{
    setPosition(pos);
}

Candle::Candle(GLdouble x, GLdouble z, GLdouble y, GLdouble rad, GLenum lightNum) : Candle(Vector3(x,y,z), rad, lightNum) { }

void Candle::draw() 
{
    const GLint num_slices = 15;
    const GLint num_slacks = 15;

    glPushMatrix();
    StaticObject::draw(); // translate to position
    glTranslatef(0.0f, 0.0f, _radius); // Candle center is at its bottom

    glColor3f(components3(CanldeColors::skin));
    drawSphere(_radius, num_slices, num_slacks);
   
    
    glTranslatef(0.0f, 0.0f, _radius);
    // we're now at the top of the sphere
    {
        // draw candle's light
        // NOTE: candle's light does matrixPush/matrixPop
        _light.draw();
    }

    glPopMatrix();
}
