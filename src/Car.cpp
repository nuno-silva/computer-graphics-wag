#include "DynamicObject.hpp"
#include "Car.hpp"

Car::Car()
{
}

Car::~Car()
{
}

void Car::draw()
{
	glPushMatrix();
	GameObject::draw();
	
	glPushMatrix();
		glScalef(1.0f, 2.0f, 1.0f); // scale y *2
		glutSolidCube(0.2); // TODO: change size
	glPopMatrix();


	glPopMatrix();
}
