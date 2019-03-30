#include "Camera.h"
#include <windows.h>
#include <GL\freeglut.h>    // freeglut library

Camera::Camera()
{
	followsLastPos = Point(0, 0);
	movement = Velocity(0, 0);
}

Camera::Camera(MovingObject * follow, Point viewportTL, Point viewportBR, Point levelTL, Point levelBR)
{
	setFollow(follow);
	setViewportTL(viewportTL);
	setViewportBR(viewportBR);
	setLevelTL(levelTL);
	setLevelBR(levelBR);
};


Camera::~Camera()
{

}

bool Camera::shouldFollowX()
{
	float x = follow->getPoint().getX();
	float r = follow->getRadius();
	float viewportRadius = abs(viewportTL.getX() - viewportBR.getX()) / 2;

	// check right side
	float rightSide = levelBR.getX();
	if (x > rightSide - viewportRadius)
		return false;

	// check left side
	float leftSide = levelTL.getX();
	if (x < leftSide + viewportRadius)
		return false;

	return true;
}

bool Camera::shouldFollowY()
{
	float y = follow->getPoint().getY();
	return false;
}

void Camera::capture()
{
	

	// hacky way to do this that we are going to run with
	float followX = follow->getPoint().getX();
	float followY = follow->getPoint().getY();
	float shiftX = 0;
	float shiftY = 0;

	//std::cout << "shouldFollowX: " << this->shouldFollowX() << std::endl;
	//std::cout << "shouldFollowY: " << this->shouldFollowY() << std::endl;

	if (shouldFollowX())
	{
		shiftX = followsLastPos.getX() - followX;
		followsLastPos.setX(followX);
	}
	if (shouldFollowY())
	{
		shiftY = followsLastPos.getY() - followY;
		followsLastPos.setY(followY);
	}

	glTranslatef(shiftX, shiftY, 0.0);
}


