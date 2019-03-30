#pragma once
#include "Point.h"
#include "Player.h"
#include "uiInteract.h"
#include "Level.h"
#include "Camera.h"
#include <time.h> 

class Game
{
public:
	/*********************************************
	 * Constructor
	 * Initializes the game
	 *********************************************/
	Game(Point tl, Point br);
	~Game();

	float getDelta(); 

	/*********************************************
	 * Function: advance
	 * Description: Move everything forward one
	 *  step in time.
	 *********************************************/
	void advance();
	void advancePlayer();

	/*********************************************
	 * Function: handleInput
	 * Description: Takes actions according to whatever
	 *  keys the user has pressed.
	 *********************************************/
	void handleInput(const Interface & ui);

	/*********************************************
	 * Function: draw
	 * Description: draws everything for the game.
	 *********************************************/
	void draw(const Interface & ui);

	/*********************************************
	 * Function: applyGravity
	 * Description: applies gravity to the player
	 *********************************************/
	void applyGravity(MovingObject &o);

	/*********************************************
	 * Function: onGround
	 * Description: makes sure gravity doesn't pull
	 * Objects through the floor
	 *********************************************/
	bool onGround(MovingObject &o);

	/*********************************************
	 * Function: onGround
	 * Description: makes sure gravity doesn't pull
	 * Objects through the floor
	 *********************************************/
	void keepObjectInLevel(MovingObject &o);


	/*********************************************
	* Function: getFloorHeight
	* Description: get floor height at given x
	*********************************************/
	float getFloorHeight(float x);

private: 
	// The coordinates of the viewport
	Point topLeft;
	Point bottomRight;

	// Game related
	Velocity normalGravity;
	float curTime;

	// Objects in the game
	Player player;
	Level level;
	Camera camera;
};

