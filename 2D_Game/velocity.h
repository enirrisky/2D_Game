#pragma once

class Velocity
{
private: 
	float dx;
	float dy;

public:
	Velocity();
	Velocity(int dx, int dy);
	~Velocity();

	float getDx() { return dx; } const
	float getDy() { return dy; } const
	void  setDx(float dx) { this->dx = dx; }
	void  setDy(float dy) { this->dy = dy; }
	void  addDx(float dx) { this->dx += dx; }
	void  addDy(float dy) { this->dy += dy; }
	void  dampen(float stickyness);

	inline friend Velocity operator + (Velocity & lhs, Velocity & rhs)
	{
		Velocity v;
		v.setDx(lhs.getDx() + rhs.getDx());
		v.setDy(lhs.getDy() + rhs.getDy());
		return v;
	}
};

Velocity operator * (Velocity v, float f);
Velocity operator - (Velocity v, Velocity vn);
