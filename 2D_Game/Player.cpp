#include "Player.h"



Player::Player() : speed(4)
{
}

Player::Player(Point p)
{
	Player();
	setPoint(p);
}


Player::~Player()
{
}

void Player::advance()
{
	Velocity v = getVelocity();
	Point p = getPoint();
	setPoint(p + v);
}

void Player::moveLeft()
{
	Velocity v(-(getSpeed()), 0);
	setPoint(getPoint() + v);
}

void Player::moveRight()
{
	Velocity v(getSpeed(), 0);
	setPoint(getPoint() + v);
}

void Player::jump()
{
	Point p = getPoint();
	Velocity v(0, getSpeed() * 2);
	setVelocity(getVelocity() + v);
}


