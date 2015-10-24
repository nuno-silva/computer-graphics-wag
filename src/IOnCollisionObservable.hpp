#pragma once
#include "GameObject.hpp"

class IOnCollisionObservable {
    virtual void registerOnStopCollisonObserver(GameObject &obj) = 0;
    virtual void registerOnResetCollisonObserver(GameObject &obj) = 0;
};