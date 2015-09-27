#pragma once

#include "global.hpp"

#include "Entity.hpp"

class Camera {
protected:
	GLdouble _near;
	GLdouble _far;
public:
	Camera( GLdouble near, GLdouble far );
	~Camera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};
