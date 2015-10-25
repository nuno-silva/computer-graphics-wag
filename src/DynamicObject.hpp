#pragma once

#include "GameObject.hpp"
#include "Vector3.hpp"

class DynamicObject : public GameObject {
private:
    GLdouble _accel;
    GLdouble _speed;
    Vector3  _orientation;
    Vector3 _initPosition;
    Vector3 _initOrientation;

protected:
    bool _turnRight;
    bool _turnLeft;
    GLdouble _angleZ = 0;

public:
    DynamicObject();
    DynamicObject(Vector3 orientation);
    DynamicObject(Vector3 orientation, GLdouble x, GLdouble y, GLdouble z);
    DynamicObject(Vector3 orientation, Vector3 position);
    DynamicObject(GLdouble x, GLdouble y, GLdouble z);
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

    virtual void resetInitPosition();
    virtual void resetInitOrientation();
    virtual void resetColSphereInitPosition();
};
