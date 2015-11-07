#pragma once
#include "global.hpp"
#include "Vector4.hpp"
#include "Vector3.hpp"

class LightSource {
private:
    GLfloat _ambient[4] = { 0.0f, 0.0f, 0.0f, 0.0f, };
    GLfloat _diffuse[4] = { 0.0f, 0.0f, 0.0f, 0.0f, };
    GLfloat _specular[4] = { 0.0f, 0.0f, 0.0f, 0.0f, };
    GLfloat _position[4] = { 0.0f, 0.0f, 0.0f, 0.0f, };
    GLfloat _direction[4] = { 0.0f, 0.0f, 0.0f, 0.0f, };
    GLfloat _cut_off  = 0.0f;
    GLfloat _exponent = 0.0f;
    GLenum _lightNumber;
    GLboolean _state;

public:
    /** @param lightNumber of the light source, using GL_LIGHT_i constants.
     */
    LightSource(GLenum lightNumber);
    ~LightSource();
    GLboolean getState() const;
    void setState(GLboolean state);
    GLenum getNum() const;
    void setPosition(const Vector3& pos);
    void setDirection(const Vector3& dir);
    void setCutoff(GLfloat cut_off);
    void setExponent(GLfloat exp);
    void setAmbient(const Vector4& amb);
    void setDiffuse(const Vector4& diff);
    void setSpecular(const Vector4& spec);
    virtual void draw();
};
