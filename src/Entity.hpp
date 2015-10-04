#pragma once

#include "Vector3.hpp"
#include "global.hpp"


class Entity {
	Vector3 _position;
public:
	Entity();
	~Entity();

	Vector3 getPosition() const;

	void setPosition(GLdouble n, GLdouble y, GLdouble z);
	void setPosition(const Vector3& p);

};
