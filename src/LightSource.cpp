#include "LightSource.hpp"

LightSource::LightSource(GLenum number)
{
    _lightNumber = number;
    setState( true );
}

LightSource::~LightSource()
{
}

GLboolean LightSource::getState() const
{
    return _state;
}

void LightSource::setState(GLboolean state)
{
    _state = state;

    if( _state ) {
        glEnable( _lightNumber );
    } else {
        glDisable( _lightNumber );
    }
}

GLenum LightSource::getNum() const
{
    return _lightNumber;
}

void LightSource::setPosition(const Vector3 & pos)
{
    _position[0] = pos.getX();
    _position[1] = pos.getY();
    _position[2] = pos.getZ();
    _position[3] = 1.0f;
}

void LightSource::setDirection(const Vector3 & dir)
{
    _direction[0] = dir.getX();
    _direction[1] = dir.getY();
    _direction[2] = dir.getZ();
    _direction[3] = 0.0f;
}

void LightSource::setCutoff(GLfloat cut_off)
{
    _cut_off = cut_off;
}

void LightSource::setExponent(GLfloat exp)
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

void print4(GLfloat v[4]) {
    std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << std::endl;
}

void LightSource::draw() {
    glPushMatrix();
    //std::cout << "pos: "; print4(_position);
    glLightfv( _lightNumber, GL_AMBIENT,  _ambient);
    //std::cout << "amb: "; print4(_ambient);
    glLightfv( _lightNumber, GL_DIFFUSE,  _diffuse);
    //std::cout << "dif: "; print4(_diffuse);
    glLightfv( _lightNumber, GL_SPECULAR, _specular);
    //std::cout << "spe: "; print4(_specular);
    //std::cout << "num: " << _lightNumber << std::endl;
    glLightfv( _lightNumber, GL_POSITION,  _position);

    glLightf( _lightNumber, GL_SPOT_CUTOFF,     _cut_off);
    //std::cout << "cut: " << _cut_off << std::endl;
    glLightfv( _lightNumber,GL_SPOT_DIRECTION,  _direction);
    //std::cout << "dir: "; print4(_direction);
    glLightf( _lightNumber, GL_SPOT_EXPONENT,   _exponent);
    //std::cout << "exp: " << _exponent << std::endl;

    glPopMatrix();
}
