#pragma once
#include "Point.h"
#include "uiDraw.h"
class Line
{
public:
	Line();
	Line(Point start, Point end) : start(start), end(end) {};
	~Line();

	inline void draw() {
		drawLine(start, end, 0.5, 0.4, 0.2);
	}

private:
	Point start;
	Point end;
};

