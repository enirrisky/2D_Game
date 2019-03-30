#pragma once

#include <iostream>
#include "Velocity.h"

class Point
{
public:
	Point()           : x(0.0), y(0.0) {}
	Point(bool check) : x(0.0), y(0.0) {}
	Point(float x, float y);
	~Point();

	// getters
	float getX()       const { return x; }
	float getY()       const { return y; }

	// setters
	void setX(float x);
	void setY(float y);
	void addX(float dx) { setX(getX() + dx); }
	void addY(float dy) { setY(getY() + dy); }

	/*******************************************
	* POINT add to
	*       adds a velocity to the pointer
	******************************************/
	inline friend Point & operator + (Point & lhs, Velocity & rhs)
	{
		lhs.x += rhs.getDx();
		lhs.y += rhs.getDy();
		return lhs;
	}



private:
	float x;
	float y;
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Point & pt);
std::istream & operator >> (std::istream & in, Point & pt);
Point operator + (Point p, Point pt);
Point operator - (Point p, Point pt);
Point operator * (Point p, float f);

