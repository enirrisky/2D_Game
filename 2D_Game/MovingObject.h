#pragma once
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class MovingObject
{
public:
	MovingObject() : alive(true) {}
	~MovingObject() {}

private:
	Point p;
	Velocity v;
	bool alive;

public: 
	//getters & setters
	Point    getPoint() { return p; }
	Velocity getVelocity() { return v; }
	void     setPoint(Point p) { this->p = p; }
	void     setVelocity(Velocity v) { this->v = v; }
	bool     isAlive() { return alive; }
	void     kill() { this->alive = false; }
	void     ressurrect() { this->alive = true; }

	//virtual functions
	virtual void advance() {
		Point p = getPoint();
		Velocity v = getVelocity();
		setPoint(p + v);
	}
	virtual void draw() {}
};
