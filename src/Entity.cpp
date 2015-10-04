#include "Entity.hpp"

Entity::Entity() : _position(0, 0, 0)
{

}

Entity::~Entity()
{

}

Vector3& Entity::getPosition()
{
    return _position;
}

void Entity::setPosition(GLdouble x, GLdouble y, GLdouble z)
{
    _position.set( x, y, z );
}

void Entity::setPosition(const Vector3 & p)
{
    _position = p;
}
