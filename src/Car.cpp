#include "Car.hpp"
#include "Wheel.hpp"

#define Y_SCALE 2.0f



Car::Car(GLdouble width, GLdouble length) : _width(width), _length(length) { 
	setWireframeState();
}

GLdouble Car::getWidth() const {
    return _width;
}

GLdouble Car::getLength() const {
    return _length;
}

void drawWheels(GLdouble car_width, GLdouble car_length) {
    const GLdouble outer = Wheel::WHEEL_OUTER_RADIUS;
    const GLdouble inner = Wheel::WHEEL_INNER_RADIUS;

    Wheel back_left(  (outer - inner) / 2, (car_length / 2 - outer) * Y_SCALE, outer);
    Wheel back_right((-outer + inner) / 2, (car_length / 2 - outer) * Y_SCALE, outer);

    Wheel front_left(  (outer - inner) / 2, -(car_length / 2 - outer) * Y_SCALE, outer);
    Wheel front_right((-outer + inner) / 2, -(car_length / 2 - outer) * Y_SCALE, outer);

    back_left.draw();
    back_right.draw();
    front_left.draw();
    front_right.draw();
}

void Car::draw() {
    glPushMatrix();

    GameObject::draw();

    glTranslatef(0.0f, 0.0f, 0.2f);
    glScalef(6.0f, 6.0f, 6.0f);

    glPushMatrix();

    glScalef(1.0f, Y_SCALE, 1.0f);
    glTranslatef(0.0f, 0.0f, -Wheel::WHEEL_OUTER_RADIUS);
    drawCube(_length);

    glPopMatrix();

    drawWheels(_width, _length);

    glPopMatrix();
}

// @Override
void Car::setWireframeState() {
	if (drawAsWireframe) {

		drawCube = glutWireCube;
	}
	else {
		drawCube = glutSolidCube;
	}
}

void Car::update(GLdouble a)
{
	setWireframeState();
}
