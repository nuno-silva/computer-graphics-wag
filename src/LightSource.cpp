#include "LightSource.hpp"

LightSource::LightSource(GLdouble number)
{
    _num = number;
}

GLboolean LightSource::getState() const
{
    return _state;
}

void LightSource::setState(GLboolean state)
{
    _state = state;
}

GLenum LightSource::getNum() const
{
    return _num;
}

void LightSource::setPosition(const Vector3 & pos)
{
    _position = pos;
}

void LightSource::setDirection(const Vector3 & dir)
{
    _direction = dir;
}

void LightSource::setCutoff(GLdouble cut_off)
{
    _cut_off = cut_off;
}

void LightSource::setExponent(GLdouble exp)
{
    _exponent = exp;
}

void LightSource::setAmbient(const Vector4 & amb)
{
    _ambient[0] = amb.getX();
    _ambient[1] = amb.getY();
    _ambient[2] = amb.getZ();
    _ambient[3] = amb.getT();
}

void LightSource::setDiffuse(const Vector4 & diff)
{
    _diffuse[0] = diff.getX();
    _diffuse[1] = diff.getY();
    _diffuse[2] = diff.getZ();
    _diffuse[3] = diff.getT();
}

void LightSource::setSpecular(const Vector4 & spec)
{
    _specular[0] = spec.getX();
    _specular[1] = spec.getY();
    _specular[2] = spec.getZ();
    _specular[3] = spec.getT();
}
