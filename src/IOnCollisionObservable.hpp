#pragma once
#include "IOnCollisionObserver.hpp"

class IOnCollisionObservable {
    virtual void registerOnStopCollisonObserver(IOnCollisionObserver& obj) = 0;
    virtual void registerOnResetCollisonObserver(IOnCollisionObserver &obj) = 0;
};