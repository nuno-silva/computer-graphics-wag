#include "CandleLight.hpp"

CandleLight::CandleLight(Vector3 pos, Vector3 dir, Vector4 amb, Vector4 diffuse, Vector4 specular, GLdouble cut_off, GLdouble exponent, GLdouble number) :
    CandleLight(pos, dir, number) {
    setAmbient(amb);
    setDiffuse(diffuse);
    setSpecular(specular);
    setCutoff(cut_off);
    setExponent(exponent);

    // HARDCODED TEMP
    _position_hom[0] = pos.getX();
    _position_hom[1] = pos.getY();
    _position_hom[2] = pos.getZ();
    _position_hom[3] = 1;

    // HARDCODED TEMP
    _direction_hom[0] = dir.getX();
    _direction_hom[1] = dir.getY();
    _direction_hom[2] = dir.getZ();
    _direction_hom[3] = 1;

    glLightfv(GL_LIGHT0, GL_AMBIENT, (GLfloat*)_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, _position_hom);
}

void CandleLight::draw()
{
    glPushMatrix();
    LightSource::draw(); // translate to correct position

    glColor3f(1.0f, 0.0f, 0.0f);
    
    glScalef(0.03f, 0.03f, 0.03f);
    glutSolidCube(CUBE_SIZE);

    glPopMatrix();
}

CandleLight::CandleLight(Vector3 pos, Vector3 dir, GLdouble number) : LightSource(number) {
    setPosition(pos);
}