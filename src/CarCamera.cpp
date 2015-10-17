#include "global.hpp"
#include "CarCamera.hpp"
#include "Vector3.hpp"

#include <iostream>

Vector3 v1(0,0,1);

CarCamera::CarCamera(Car & car) : _car(&car),
                                  PerspectiveCamera(v1, nullVector,
                                                    45, 2, 0.1, 5)
{
    update();
}


void CarCamera::update() {
    setPosition(_car->getPosition());
    setCenter(_car->getOrientation());
}
