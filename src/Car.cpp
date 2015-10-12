#include "global.hpp"
#include "Car.hpp"
#include "DynamicObject.hpp"

Car::Car(GLdouble scale, GLdouble x, GLdouble y, GLdouble z) :
    DynamicObject::DynamicObject(), _scale(scale)
{
    setPosition(x, y, z);
}

Car::Car(GLdouble scale) : Car::Car(scale, 0, 0, 0) {
    setWireframeState();
}

GLdouble Car::getScale() const {
    return _scale;
}

void Car::drawWheels(GLdouble inner, GLdouble outer, GLdouble scale) {

    // TODO: REFRACTOR THIS, I AM SORRY, BUT WE ARE IN A HURRY!
    wheels[0].setState(inner, outer, scale * cm(2.75), scale * cm(-1), inner + outer);
    wheels[1].setState(inner, outer, scale * cm(2.75), scale * cm(1), inner + outer);
    wheels[2].setState(inner, outer, scale * cm(0), scale * cm(-1), inner + outer);
    wheels[3].setState(inner, outer, scale * cm(0), scale * cm(1), inner + outer);

    for (int i = 0; i < NUM_WHEELS; i++) {
        wheels[i].draw();
    }

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
    DynamicObject::update(a);

    setWireframeState();

    for (int i = 0; i < NUM_WHEELS; i++) {
        wheels[i].update(a);
    }
}

void Car::setDrawAsWireframe(bool value)
{
    drawAsWireframe = value;

    for (int i = 0; i < NUM_WHEELS; i++) {
        wheels[i].setDrawAsWireframe(value);
    }
}
