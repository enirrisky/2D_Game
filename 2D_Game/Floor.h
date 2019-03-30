#pragma once
#include "Point.h"
#include "Line.h"
#include <vector>
class Floor
{
public:
	Floor();
	Floor(std::vector<Line> floor);
	~Floor();

private: 
	std::vector<Line> floorline;
};

