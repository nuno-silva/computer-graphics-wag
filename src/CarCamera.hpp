#pragma once

#include "Car.hpp"
#include "PerspectiveCamera.hpp"

class CarCamera : public PerspectiveCamera
{
    std::shared_ptr<Car> _car;
public:
    CarCamera(Car & car);
    virtual void update();
};
