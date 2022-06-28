#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snek)
{
	Respawn(rng, brd, snek);
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake& snek)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 1);


	Location newloc;
	do {

		newloc.x = xDist(rng);
		newloc.y = yDist(rng);

	} while (snek.IsInTile(newloc) || brd.CheckForObstacles(newloc));

	loc = newloc;

}

void Goal::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

const Location& Goal::GetLocation() const
{
	return loc;
}