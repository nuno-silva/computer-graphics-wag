#include "DynamicObject.hpp"
#include "Car.hpp"

#define Y_SCALE 2.0f

#define CAR_LENGTH 0.04f

void Car::draw()
{
	glPushMatrix();
	GameObject::draw();


  glTranslatef(0.0f, 0.0f, 0.2f);
  glScalef(6.0f, 6.0f, 6.0f);

	glPushMatrix();
		glScalef(1.0f, Y_SCALE, 1.0f); // scale y *2
		glTranslatef(0.0f, 0.0f, 0.005f);
		glutSolidCube(CAR_LENGTH); // TODO: change size
	glPopMatrix();

	glPushMatrix();
  {
      glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
      glTranslatef(0.02f, 0.0f, 0.025 * Y_SCALE);
      glTranslatef(0.0f, -(CAR_LENGTH/2.0f) * Y_SCALE + 0.005f * Y_SCALE, 0.0f);
      glutSolidTorus(0.003f, 0.005f, 10, 10);
  }
	glPopMatrix();

	glPopMatrix();
}
