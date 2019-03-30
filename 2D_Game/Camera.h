#pragma once
#include "MovingObject.h"

class Camera
{
public:
	Camera();
	Camera(MovingObject * follow, Point viewportTL, Point viewportBR, Point levelTL, Point levelBR);
	~Camera();

	// getters and setters
	void setFollow(MovingObject * f) { follow = f; };
	MovingObject * getFollow() { return follow; }
	
	// getters and setters for level and viewport points
	Point getViewportTL() { return this->viewportTL; }
	Point getViewportBR() { return this->viewportBR; }
	Point getLevelTL() { return this->levelTL; }
	Point getLevelBR() { return this->levelBR; }
	void  setViewportTL(Point tl) { this->viewportTL = tl; }
	void  setViewportBR(Point br) { this->viewportBR = br; }
	void  setLevelTL(Point tl) { this->levelTL = tl; }
	void  setLevelBR(Point br) { this->levelBR = br; }

	void capture();

private:
	Point followsLastPos;
	Point viewportTL;
	Point viewportBR;
	Point levelTL;
	Point levelBR;
	Velocity movement;
	MovingObject * follow;

	bool shouldFollowX();
	bool shouldFollowY();
};

