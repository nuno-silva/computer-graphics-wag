#include "Vector3.hpp"

Vector3::Vector3()
{
}

Vector3::Vector3(GLdouble x, GLdouble y, GLdouble z)
{
	_x = x;
	_y = y;
	_z = z;
}

Vector3::~Vector3()
{
}

GLdouble Vector3::getX() const
{
	return _x;
}

GLdouble Vector3::getY() const
{
	return _y;
}

GLdouble Vector3::getZ() const
{
	return _z;
}

void Vector3::set(GLdouble x, GLdouble y, GLdouble z)
{
	_x = x;
	_y = y;
	_z = z;
}

Vector3 Vector3::operator=(const Vector3 & vec)
{
	_x = vec.getX();
	_y = vec.getY();
	_z = vec.getZ();
	return *this;
}

Vector3 Vector3::operator*(GLdouble num)
{
	return Vector3(this->getX() * num, this->getY() * num, this->getZ() * num);
}

Vector3 Vector3::operator+(const Vector3& vec)
{
	return Vector3(this->getX() + vec.getX(), this->getY() + vec.getY(), this->getZ() + vec.getZ());
}

Vector3 Vector3::operator-(const Vector3& vec)
{
	return Vector3(this->getX() - vec.getX(), this->getY() - vec.getY(), this->getZ() - vec.getZ());
}

void Vector3::glTranslate()
{
	glTranslatef( _x, _y, _z );
}
