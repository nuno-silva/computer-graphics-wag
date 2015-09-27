#pragma once

#include "Vector3.hpp"
#include "global.hpp"

class Entity {
public:
	Entity();
	~Entity();
	Vector3* getPosition();
	Vector3* setPosition(GLdouble n, GLdouble y, GLdouble z);
	Vector3* setPosition(const Vector3& p);

};
