#include "global.hpp"
#include "CarCamera.hpp"
#include "Vector3.hpp"

#include <iostream>

Vector3 v1(0,0,1);

CarCamera::CarCamera(Car & car) : _car(&car),
                                  PerspectiveCamera(nullVector, v1, nullVector,
                                                    45, 2, 0.1, 5)
{
    update();
}


void CarCamera::update() {
    const auto xy_offset = _car->getOrientation().normalized() * -_car->_bottom_length * 3;
    const auto z_offset  = Vector3(0, 0, (_car->_bottom_height + _car->_top_height) * 2);

    setPosition(_car->getPosition() + xy_offset + z_offset);
    setCenter(_car->getPosition() + _car->getOrientation());
}
