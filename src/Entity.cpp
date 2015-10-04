#include "Entity.hpp"

Entity::Entity() : _position(0.0d, 0.0d, 0.0d) {}

Entity::~Entity() {}

Vector3& Entity::getPosition() const {
    return _position;
}

void Entity::setPosition(GLdouble x, GLdouble y, GLdouble z) {
    _position.set( x, y, z );
}

void Entity::setPosition(const Vector3 & p) {
    _position = p;
}
