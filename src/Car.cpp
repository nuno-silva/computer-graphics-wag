#include "global.hpp"
#include "Car.hpp"
#include "DynamicObject.hpp"

#include <iostream>

Car::Car(GLdouble scale, GLdouble x, GLdouble y, GLdouble z) :
    DynamicObject::DynamicObject(x, y, z), _scale(scale)
{
    setWheelsState(_wheel_inner_radius, _wheel_outer_radius, _scale);

    _boundingSphere._radius = _bottom_length / 2.0f;
    _boundingSphere._center = getPosition() + getOrientation() * cm(1.625);
}

Car::Car(GLdouble scale) : Car::Car(scale, 0, 0, 0) {}

GLdouble Car::getScale() const {
    return _scale;
}

void Car::drawWheels() {
    for (int i = 0; i < NUM_WHEELS; i++) {
        wheels[i].draw();
    }

}

void Car::setWheelsState(GLdouble inner, GLdouble outer, GLdouble scale)
{
    wheels[0].setState(inner, outer, scale * cm(2.75), scale * cm(-1), inner + outer);
    wheels[1].setState(inner, outer, scale * cm(2.75), scale * cm(1), inner + outer);
    wheels[2].setState(inner, outer, scale * cm(0), scale * cm(-1), inner + outer);
    wheels[3].setState(inner, outer, scale * cm(0), scale * cm(1), inner + outer);
}

void Car::onStopCollision(const GameObject & otherObj)
{
    setSpeed(0.0f);
}

void Car::onResetCollision(const GameObject & otherObj)
{
    setSpeed(0.0f);
    resetInitPosition();
    resetInitOrientation();
}

void Car::draw() {
    glPushMatrix();
    {
        GameObject::draw(); // move car to its position


        //std::cout << "Angle:: " << angle << std::endl;

        //glTranslatef(getPosition().getX(), getPosition().getY(), getPosition().getZ());
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        //glTranslatef(getPosition().getX() * (-1), getPosition().getY() * (-1), getPosition().getZ() * (-1));

        // Car bottom
        glPushMatrix();
        {
            glColor3f( components3(CarColors::bottom) );
            glTranslated(_scale * cm(1.625), 0, _wheel_inner_radius + _scale * cm(1));
            glScaled(_bottom_length, _bottom_width, _bottom_height);
            drawCube(1);
        }
        glPopMatrix();

        // Car top
        glPushMatrix();
        {
            glColor3f( components3(CarColors::top) );
            glTranslated(_scale * cm(2.25), 0, _wheel_inner_radius + _scale * cm(1.875));
            glScaled(_top_length, _top_width, _top_height);
            drawCube(1);
        }
        glPopMatrix();

        glColor3f( components3(CarColors::wheels) );
        drawWheels();
    }
    glPopMatrix();
}

void Car::update(GLdouble delta_t) {
    DynamicObject::update( delta_t );

    for (int i = 0; i < NUM_WHEELS; i++) {
        wheels[i].update( delta_t );
        if (_wired) {
            wheels[i].setWired();
        } else {
            wheels[i].setSolid();
        }
    }
}

void Car::processCollision(GameObject &go) {

}
