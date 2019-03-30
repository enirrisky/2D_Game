#include "Camera.h"
#include <windows.h>
#include <GL\freeglut.h>    // freeglut library

Camera::Camera()
{
}

Camera::Camera(MovingObject * follow)
{
	setFollow(follow);
};


Camera::~Camera()
{

}

void Camera::capture()
{
	//glLoadIdentity();
	//glTranslatef(follow->getPoint().getX(), follow->getPoint().getY(), 0.0);
	//glTranslatef(20.00, 20.00, 0.0);
}
