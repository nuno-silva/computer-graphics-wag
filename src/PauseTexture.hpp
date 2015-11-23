#pragma once
#include "Texture.hpp"
#include "LibpngHelper.hpp"
#include <iostream>

#define QUAD_SIDE 0.25f
#define Z_DIST 0.3f

class PauseTexture final : public Texture {

private:
    GLfloat _ar; // aspect ratio for QUAD size calculations

public:
    PauseTexture(char* fileName, int w, int h);

    void draw() override;

};
