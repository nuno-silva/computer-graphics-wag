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
		glTranslatef(0.0f, 0.0f, 0.005f);
		glutSolidCube(0.04f); // TODO: change size
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.02f, 0.0f, 0.025);
	glutSolidTorus(0.003f, 0.005f, 10, 10);
	glPopMatrix();

	glPopMatrix();
}
