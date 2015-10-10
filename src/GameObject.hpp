#pragma once

#include "global.hpp"

#include "Entity.hpp"

class GameObject : public Entity {

public:
    virtual ~GameObject();
    virtual void draw() = 0;
    virtual void update( GLdouble delta_t );
	virtual void setDrawAsWireframe(bool value);
	virtual bool getDrawAsWireframe();
	virtual void setWireframeState();

protected:
	bool drawAsWireframe = false;
};

