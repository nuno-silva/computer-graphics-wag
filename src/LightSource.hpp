#pragma once
#include "global.hpp"
#include "Vector4.hpp"
#include "Vector3.hpp"

class LightSource {
protected:
    GLdouble _ambient[4];
    GLdouble _diffuse[4];
    GLdouble _specular[4];
    GLdouble _cut_off;
    GLdouble _exponent;
    GLenum _num;
    GLboolean _state;
    Vector3 _direction;
    Vector3 _position;

public:
    LightSource(GLdouble number);
    ~LightSource();
    GLboolean getState() const;
    void setState(GLboolean state);
    GLenum getNum() const;
    void setPosition(const Vector3& pos);
    void setDirection(const Vector3& dir);
    void setCutoff(GLdouble cut_off);
    void setExponent(GLdouble exp);
    void setAmbient(const Vector4& amb);
    void setDiffuse(const Vector4& diff);
    void setSpecular(const Vector4& spec);
    virtual void draw();
};