#pragma once

#include "Vector3.hpp"
#include "global.hpp"


class Entity {
private:
	Vector3 _position;
public:
	Entity();
	~Entity();

	Vector3 getPosition() const;

	virtual void setPosition(GLdouble x, GLdouble y, GLdouble z);
	virtual void setPosition(const Vector3& p);

};
