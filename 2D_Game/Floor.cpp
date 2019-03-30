#include "Floor.h"



Floor::Floor()
{

}

Floor::Floor(std::vector<Line> floor)
{
	for (int i = 0; i < floor.size(); i++)
		floorline.push_back(floor[i]);
}


Floor::~Floor()
{
}
