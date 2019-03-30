#pragma once
#include "Point.h"

class Level
{
public:
	Level();
	Level(Point tl, Point br);
	~Level();

	void draw();
	Point getTopLeft()             { return topLeft;     };
	Point getBottomRight()         { return bottomRight; };
	void  setTopLeft(Point tl)     { topLeft = tl;       };
	void  setBottomRight(Point br) { bottomRight = br;   };

private:
	Point topLeft;
	Point bottomRight;
};

