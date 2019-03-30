#include "Game.h"
#include <time.h>



/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game::Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
{
	normalGravity = Velocity(0, -5);
	curTime = clock();
	level = Level(topLeft, bottomRight);
	camera = Camera(&player);

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
	}

	if (ui.isRight())
	{
		player.moveRight();
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
		Point p(x, fh);
		o.setPoint(p);
		v = v * -1;
		v.dampen(1.0);
	}
	o.setVelocity(v);
}

/*********************************************
* Function: canDrop
* Description: returns true if object is 
* already on ground
*********************************************/
bool Game::onGround(MovingObject o)
{
	float y = o.getPoint().getY();
	float fh = getFloorHeight(o.getPoint().getX());
	return y <= fh;
}

/*********************************************
* Function: getFloorHeight
* Description: get floor height at given x
*********************************************/
float Game::getFloorHeight(float x)
{
	// simple floor height for now
	return bottomRight.getY() + 27;
}

float Game::getDelta(){ 
	float prevTime = curTime;
	curTime = clock();
	float dt = curTime - prevTime;
	if (dt > 0.15)
		dt = 0.15;
	return dt; 
};