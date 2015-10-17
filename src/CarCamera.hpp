#pragma once

#include "Car.hpp"
#include "PerspectiveCamera.hpp"

class CarCamera : public PerspectiveCamera
{
    Car * _car;
public:
    CarCamera(Car & car);
    virtual void update();
};
