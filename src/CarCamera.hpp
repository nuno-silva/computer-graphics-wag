#pragma once

#include "Car.hpp"
#include "PerspectiveCamera.hpp"

#include <memory>

class CarCamera : public PerspectiveCamera
{
    std::shared_ptr<Car> _car;
public:
    CarCamera( std::shared_ptr<Car> car );
    virtual void update() override;
};
