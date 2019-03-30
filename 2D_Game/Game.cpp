#include "Game.h"
#include <time.h>



/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game::Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
{
	normalGravity = Velocity(0, -5);
	curTime = clock();
	
	//level = Level(topLeft, bottomRight);  // sets level to viewport size
	level = Level();

	// Camera needs to know the viewport info and level info
	camera = Camera(
		&player,                    // object to follow
		topLeft,                    // viewport top left
		bottomRight,                // viewport bottom right
		level.getTopLeft(),         // level top left
		level.getBottomRight()      // level bottom right
	);

}


/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game::~Game()
{

}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game::advance()
{
	advancePlayer();
}

void Game::advancePlayer()
{
	if (player.isAlive())
	{
		player.advance();
		applyGravity(player);
	}
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game::handleInput(const Interface & ui)
{
	if (ui.isLeft())
	{
		player.moveLeft();
		keepObjectInLevel(player);
	}

	if (ui.isRight())
	{
		player.moveRight();
		keepObjectInLevel(player);
	}

	if (ui.isUp() && onGround(player))
	{
		player.jump();
	}

	if (ui.isDown())
	{
		player.setCrouched(true);
	}
	else 
	{
		player.setCrouched(false);
	}

	// Check for "Spacebar
	if (ui.isSpace())
	{
	}

	//check for function One Key
	if (ui.isFunctionOne())
	{

	}
}

/*********************************************
 * Function: keepObjectInLevel
 * Description: makes sure the object doesn't
 * leave the level
 *********************************************/
void Game::keepObjectInLevel(MovingObject &o)
{
	Point oPos = o.getPoint();
	float x = oPos.getX();
	float y = oPos.getY();
	
	// check right side
	float rightSide = level.getBottomRight().getX();
	if (x > rightSide - o.getRadius() - 2)
		x = rightSide - o.getRadius() - 2;

	// check left side
	float leftSide = level.getTopLeft().getX();
	if (x < leftSide + o.getRadius() + 2)
		x = leftSide + o.getRadius() + 2;

	Point p(x, y);
	o.setPoint(p);
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game::draw(const Interface & ui)
{
	camera.capture();
	level.draw();
	if (player.isAlive())
	{
		player.draw();
	}
}

/*********************************************
 * Function: applyGravity
 * Description: applies gravity to the player
 *********************************************/
void Game::applyGravity(MovingObject &o)
{
	Point p = o.getPoint();
	float dt = getDelta();
	Velocity v = o.getVelocity();

	Velocity nv = v * dt;
	p = p + nv;

	float px = p.getX();
	v = v + normalGravity * dt;

	o.setPoint(p);
	if (onGround(o))
	{
		float x = o.getPoint().getX();
		float fh = getFloorHeight(x);
		Point p(x, fh + o.getRadius() + 2);
		o.setPoint(p);
		v = v * -1;
		v.dampen(1.0);
	}
	o.setVelocity(v);
}

/*********************************************
* Function: onGround
* Description: returns true if object is 
* already on ground
*********************************************/
bool Game::onGround(MovingObject &o)
{
	float y = o.getPoint().getY();
	float fh = getFloorHeight(o.getPoint().getX()) + o.getRadius() + 2;
	return y <= fh;
}

/*********************************************
* Function: getFloorHeight
* Description: get floor height at given x
*********************************************/
float Game::getFloorHeight(float x)
{
	// simple floor height for now
	return bottomRight.getY();
}

float Game::getDelta(){ 
	float prevTime = curTime;
	curTime = clock();
	float dt = curTime - prevTime;
	if (dt > 0.15)
		dt = 0.15;
	return dt; 
};