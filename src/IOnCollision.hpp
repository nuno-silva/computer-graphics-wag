#pragma once
#include "GameObject.hpp"

class IOnCollision {
    public:
        virtual void onStopCollision(GameObject &otherObj) = 0; // stop the car
        virtual void onResetCollision(GameObject &otherObj) = 0; // reset car's position
};