#include "global.hpp"

#include "Car.hpp"
#include "Wheel.hpp"

Car::Car(GLdouble accel, GLdouble scale, GLdouble x, GLdouble y, GLdouble z) :
    _acceleration(accel), _scale(scale)
{
    setPosition(x, y, z);
}

Car::Car(GLdouble accel, GLdouble scale) : Car::Car(accel, scale, 0, 0, 0) {
    setWireframeState();
}

Car::Car(GLdouble accel) : Car::Car(accel, 1.0f) {}

GLdouble Car::getScale() const {
    return _scale;
}

static void drawWheels(GLdouble inner, GLdouble outer, GLdouble scale) {
    Wheel back_left  (inner, outer, scale * cm(2.75), scale * cm(-1), inner + outer);
    Wheel back_right (inner, outer, scale * cm(2.75), scale * cm( 1), inner + outer);
    Wheel front_left (inner, outer, scale * cm(0),    scale * cm(-1), inner + outer);
    Wheel front_right(inner, outer, scale * cm(0),    scale * cm( 1), inner + outer);

    back_left.draw();
    back_right.draw();
    front_left.draw();
    front_right.draw();
}

void Car::draw() {
    glPushMatrix();
    {
        // FIXME: Why is this here?
        GameObject::draw();

        // Car bottom
        glPushMatrix();
        {
            glColor3f(1, 0, 0);
            glTranslated(_scale * cm(1.625), 0, _wheel_inner_radius + _scale * cm(1));
            glScaled(_bottom_length, _bottom_width, _bottom_height);
            drawCube(1);
        }
        glPopMatrix();

        // Car top
        glPushMatrix();
        {
            glColor3f(1, 1, 0);
            glTranslated(_scale * cm(2.25), 0, _wheel_inner_radius + _scale * cm(1.875));
            glScaled(_top_length, _top_width, _top_height);
            drawCube(1);
        }
        glPopMatrix();

        drawWheels(_wheel_inner_radius, _wheel_outer_radius, _scale);
    }
    glPopMatrix();
}

void Car::setWireframeState() {
    if (drawAsWireframe) {
        drawCube = glutWireCube;
    }
    else {
        drawCube = glutSolidCube;
    }
}

void Car::update(GLdouble a) {
    setWireframeState();
}
