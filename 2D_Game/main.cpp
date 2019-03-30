/*****************************************************
 * Description: This file contains the main function
 *  that starts a game and the callback function
 *  that specifies what methods of the game class are
 *  called each time through the game loop.
 ******************************************************/
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include <iostream>
#include "uiInteract.h"
#include "Game.h"
using namespace std;

/*******************************************************************
 * All the interesting work happens here.
 * OpenGL calls this to draw a frame.
 * When it's finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen
 * -to see more look at the run method of the uiInteract class
 *******************************************************************/
void callBack(const Interface *pUI, void *p)
{
	Game *pGame = (Game *)p;

	pGame->advance();
	pGame->handleInput(*pUI);
	pGame->draw(*pUI);
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * the game and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char **argv)
{
	// Point with x y coordinates that set the size of the window
	int width = 800;
	int height = 400;
	Point topLeft(0 - width / 2, 0 + height / 2);
	Point bottomRight(0 + width / 2, 0 - height / 2);

	// Our interface object gets initialized
	Interface ui(
		argc, argv,     // command line parameters are passed 
		"Game",         // name for the window
		topLeft,        // top left point of the window
		bottomRight     // bottom right point of the window
	);

	// Our game class gets initialized with the same points as the window
	Game game(topLeft, bottomRight);

	// We run the 'run' method of our Interface obj with a callback and our game
	ui.run(callBack, &game);

	return 0;
}