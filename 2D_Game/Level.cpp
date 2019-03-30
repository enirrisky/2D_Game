#include "Level.h"
#include "Point.h"
#include "uiDraw.h"
#include <cmath>



Level::Level() 
{
	// set points to assumed viewport size
	int width = 1000;
	int height = 400;
	Point tl(0 - width / 2, 0 + height / 2);
	Point br(0 + width / 2, 0 - height / 2); // br.y should be -400 so ball doesn't stop drop before or after floor

	setTopLeft(tl);
	setBottomRight(br);
}

Level::Level(Point tl, Point br) 
{

	// just set the width of the map to the viewport
	//setTopLeft(tl);
	//setBottomRight(br);

	// or derive the level width from viewport
	float width = abs(tl.getX() - br.getX());
	float height = abs(tl.getY() - br.getY());

	width *= 2;
	height *= 2;

	Point tl2(0 - width / 2, 0 + height / 2);
	Point br2(0 + width / 2, 0 - height / 2);
	setTopLeft(tl2);
	setBottomRight(br2);
};



Level::~Level()
{
}

void Level::draw() 
{
	const int numCols = 11;
	const int numRows = 7;
	float width = bottomRight.getX() - topLeft.getX();
	float height = topLeft.getY() - bottomRight.getY();
	float tileWidth = width / numCols;
	float tileHeight = height / numRows;

	// get center of first tile
	float centerX = topLeft.getX() + (tileWidth / 2);
	float centerY = topLeft.getY() - (tileHeight / 2);
	Point center(centerX, centerY);

	for (int row = 0; row < numRows; row++) {
		center.setX(centerX);
		for (int col = 0; col < numCols; col++) {
			drawRect(center, tileWidth, tileHeight, 0);
			center.setX(center.getX() + tileWidth);
		}
		center.setY(center.getY() - tileHeight);
	}
}
