#include "Location.h"

void Location::Add(const Location& delta_loc)
{
	x += delta_loc.x;
	y += delta_loc.y;
}

bool Location::operator==(const Location& r_loc) const
{
	return x == r_loc.x && y == r_loc.y;
}