#include "Level.h"
#include "Point.h"
#include "uiDraw.h"



Level::Level() 
{
	// set points to assumed viewport size
	int width = 800;
	int height = 400;
	Point tl(0 - width / 2, 0 + height / 2);
	Point br(0 + width / 2, 0 - height / 2);
	setTopLeft(tl);
	setBottomRight(br);
}

Level::Level(Point tl, Point br) 
{
	setTopLeft(tl);
	setBottomRight(br);
};



Level::~Level()
{
}

void Level::draw() 
{
	float width = bottomRight.getX() - topLeft.getX();
	float height = topLeft.getY() - bottomRight.getY();
	float tileWidth = width / 5;
	float tileHeight = height / 3;

	// get center of first tile
	float centerX = topLeft.getX() + (tileWidth / 2);
	float centerY = topLeft.getY() - (tileHeight / 2);
	Point center(centerX, centerY);

	for (int row = 0; row < 3; row++) {
		center.setX(centerX);
		for (int col = 0; col < 5; col++) {
			drawRect(center, tileWidth, tileHeight, 0);
			center.setX(center.getX() + tileWidth);
		}
		center.setY(center.getY() - tileHeight);
	}
}
