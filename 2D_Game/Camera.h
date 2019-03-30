#pragma once
#include "MovingObject.h"

class Camera
{
public:
	Camera();
	Camera(MovingObject * follow);
	~Camera();

	void setFollow(MovingObject * f) { follow = f; };
	MovingObject * getFollow() { return follow; }

	void capture();

private:
	MovingObject * follow;
};

