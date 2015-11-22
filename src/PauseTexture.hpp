#pragma once
#include "Texture.hpp"
#include "LibpngHelper.hpp"
#include <iostream>

#define QUAD_SIDE 0.25f

class PauseTexture final : public Texture {
protected:
    void loadTexture() override;

public:
    void draw() override;
    void setEnabled(bool value) override;
    bool getEnabled() const override;
    bool loadImage() override;
    void toggleEnabled() override;

    PauseTexture(char* fileName, int w, int h);
    ~PauseTexture();
};
