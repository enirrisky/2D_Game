#include "velocity.h"
#include <cmath>
#include <cassert>

Velocity::Velocity()
{
	setDx(0);
	setDy(0);
}

Velocity::Velocity(int dx, int dy)
{
	setDx(dx);
	setDy(dy);
}


Velocity::~Velocity()
{

}

void Velocity::dampen(float stickyness)
{
	assert(stickyness <= 1.00);
	assert(stickyness >= 0);
	float dx = getDx();
	float dy = getDy();
	
	float dxa = abs(dx);
	float dya = abs(dy);

	dxa = dxa - (dxa * stickyness);
	dya = dya - (dya * stickyness);

	if (dx < 0)
		dxa = dxa * -1;
	if (dy < 0)
		dya = dya * -1;

	setDx(dxa);
	setDy(dya);
}

Velocity operator * (Velocity v, float f)
{
	float dx = v.getDx();
	float dy = v.getDy();
	dx *= f;
	dy *= f;
	v.setDx(dx);
	v.setDy(dy);
	return v;
}

Velocity operator - (Velocity v, Velocity vn)
{
	float dx = v.getDx();
	float dy = v.getDy();
	dx -= v.getDx();
	dy -= v.getDy();
	v.setDx(dx);
	v.setDy(dy);
	return v;
}
