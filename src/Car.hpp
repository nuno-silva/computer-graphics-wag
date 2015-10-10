#pragma once

#include "DynamicObject.hpp"
#include "global.hpp"

class Car : public DynamicObject {
    GLdouble _width;
    GLdouble _length;

public:
    Car(GLdouble width, GLdouble length);
    GLdouble getWidth()  const;
    GLdouble getLength() const;
    virtual void draw();
	void (_STDCALL*drawCube) (GLdouble size);
	virtual void setWireframeState() override;
	virtual void update(GLdouble a);

};
