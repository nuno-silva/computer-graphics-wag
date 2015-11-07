#include "CandleLight.hpp"

CandleLight::CandleLight(Vector3 pos, Vector3 dir, Vector4 amb, Vector4 diffuse, Vector4 specular, GLdouble cut_off, GLdouble exponent, GLdouble number) :
    CandleLight(pos, dir, number) {
    setAmbient(amb);
    setDiffuse(diffuse);
    setSpecular(specular);
    setCutoff(cut_off);
    setExponent(exponent);
}

void CandleLight::draw()
{
    glPushMatrix();

    glColor3f(0.0f, 0.0f, 1.0f);
    
    glTranslatef(_position[0] , _position[1], _position[2] + 0.5f * 0.01f);
    glScalef(0.01f, 0.01f, 0.01f);
    glutSolidCube(CUBE_SIZE);

    glPopMatrix();
}

CandleLight::CandleLight(Vector3 pos, Vector3 dir, GLdouble number) : LightSource(number) {
    setPosition(pos);
}