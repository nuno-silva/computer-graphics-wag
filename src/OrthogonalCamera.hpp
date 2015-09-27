#pragma once

#include "global.hpp"

#include "Camera.hpp"

class OrthogonalCamera : Camera {
protected:
	GLdouble _left;
	GLdouble _right;
	GLdouble _bottom;
	GLdouble _top;
public:
	OrthogonalCamera( GLdouble left, GLdouble right, GLdouble bottom,
					  GLdouble top, GLdouble near, GLdouble far );
	~OrthogonalCamera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};
