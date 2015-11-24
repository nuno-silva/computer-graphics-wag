#pragma once
#include "Texture.hpp"
#include "LibpngHelper.hpp"
#include <iostream>

#define Z_DIST 0.3f

class QuadTexture final : public Texture {

private:
    GLfloat _ar; // aspect ratio for QUAD size calculations
    GLfloat _radius;
public:
    QuadTexture(char* fileName, int w, int h, GLfloat quad_radius);

    void draw() override;

};
