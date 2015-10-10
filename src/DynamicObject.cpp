#include "DynamicObject.hpp"

void DynamicObject::update(GLdouble delta_t) {
    (void) delta_t;
}

void DynamicObject::setSpeed(const Vector3 & speed) {
    (void) speed;
}

void DynamicObject::setSpeed(GLdouble x, GLdouble y, GLdouble z) {
    (void) x;
    (void) y;
    (void) z;
}

Vector3 DynamicObject::getSpeed() const {
    return Vector3();
}
