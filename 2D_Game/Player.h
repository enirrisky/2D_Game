#pragma once
#include "MovingObject.h"
#include "uiDraw.h"

class Player : public MovingObject
{
public:
	Player();
	Player(Point p);
	~Player();

private:
	float speed;
	bool crouched;

public:

	//getters & setters
	int  getSpeed()                 { return speed;              }
	void setSpeed(int speed)        { this->speed = speed;       }
	bool isCrouched()               { return crouched;           }
	void setCrouched(bool crouched) { this->crouched = crouched; }

	void moveLeft();
	void moveRight();
	void jump();
	void advance();
		
	virtual void draw()
	{
		drawCircle(getPoint(), 25); // from uiDraw
	}
};

