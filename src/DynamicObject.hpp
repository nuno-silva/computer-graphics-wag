#pragma once

#include "GameObject.hpp"
#include "Vector3.hpp"

class DynamicObject : public GameObject {
private:
    GLdouble _accel;
    GLdouble _speed;
    Vector3  _orientation;

protected:
    bool _turnLeft;
    bool _turnRight;
    GLdouble angle = 0;

public:
    DynamicObject();
    DynamicObject(Vector3 orientation);
    void update(GLdouble delta_t) override;

    void setSpeedUp( bool value );
    void setSlowDown( bool value );
    void setTurnRight( bool value );
    void setTurnLeft( bool value );

    void setAccel(GLdouble accel);

    void setSpeed(GLdouble speed);

    void setOrientation(const Vector3& orientation);
    void setOrientation(GLdouble x, GLdouble y, GLdouble z);
    bool isAccelerating();

    GLdouble getAccel() const;
    GLdouble getSpeed() const;
    Vector3 getOrientation() const;

    virtual void draw() = 0;
};
