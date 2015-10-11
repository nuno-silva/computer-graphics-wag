#include "Entity.hpp"

Entity::Entity() : _position(0.0f, 0.0f, 0.0f) { }

Entity::~Entity() { }

Vector3 Entity::getPosition() const {
    return _position;
}

void Entity::setPosition(GLdouble x, GLdouble y, GLdouble z) {
    _position.set( x, y, z );
}

void Entity::setPosition(const Vector3 & p) {
    _position = p;
}
