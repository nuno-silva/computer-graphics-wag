#include "global.hpp"

#include "Car.hpp"
#include "Wheel.hpp"

#define SCALE 30

// Car wheels radii
// FIXME: Why do the wheels look so big?
constexpr GLdouble inner         = SCALE * cm(0.25);
constexpr GLdouble outer         = SCALE * cm(0.5);

// Car elements dimensions
constexpr GLdouble bottom_length = SCALE * cm(5.25);
constexpr GLdouble bottom_width  = SCALE * cm(2);
constexpr GLdouble bottom_height = SCALE * cm(1);

constexpr GLdouble top_length    = SCALE * cm(3);
constexpr GLdouble top_width     = SCALE * cm(1.5);
constexpr GLdouble top_height    = SCALE * cm(0.75);



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
    Wheel back_left  (inner, outer, SCALE * cm(2.75), SCALE * cm(-1), outer);
    Wheel back_right (inner, outer, SCALE * cm(2.75), SCALE * cm( 1), outer);
    Wheel front_left (inner, outer, cm(0),            SCALE * cm(-1), outer);
    Wheel front_right(inner, outer, cm(0),            SCALE * cm( 1), outer);

    back_left.draw();
    back_right.draw();
    front_left.draw();
    front_right.draw();
}

void Car::draw() {
    glPushMatrix();
    {
        // FIXME: Why is this here?
        // GameObject::draw();

        // Car bottom
        glPushMatrix();
        {
            glColor3f(0, 0, 1);
            glTranslated(SCALE * cm(1.625), 0, SCALE * cm(1));
            glScaled(bottom_length, bottom_width, bottom_height);
            glutSolidCube(1);
        }
        glPopMatrix();

        // Car top
        glPushMatrix();
        {
            glColor3f(0, 1, 0);
            glTranslated(SCALE * cm(2.25), 0, SCALE * cm(1.875));
            glScaled(top_length, top_width, top_height);
            glutSolidCube(1);
        }
        glPopMatrix();

        drawWheels(_width, _length);
    }
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
