#include "Board.h"
#include <assert.h>
#include "Snake.h"
#include "Goal.h"

int Board::GetGridHeight() const
{
	return height;
}

int Board::GetGridWidth() const
{
	return width;
}

void Board::DrawCell(const Location& loc, Color c) const
{
	assert(loc.x >= 0);
	assert(loc.y >= 0);
	assert(loc.x < width);
	assert(loc.y < height);

	int gap = cell_padding * 2;
	DrawRectangle((loc.x * dimension) + boarder_padding + cell_padding, (loc.y * dimension) + boarder_padding + cell_padding, dimension - gap, dimension - gap, c);
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width&&
		loc.y >= 0 && loc.y < height;
}

void Board::DrawFrame()
{
	int box_rightend = width * dimension + boarder_padding;
	int box_bottomend = height * dimension + boarder_padding;

	int box_leftstart = boarder_padding - frame_thickness;
	int box_topstart = boarder_padding - frame_thickness;


	for (int i = box_rightend; i < box_rightend + frame_thickness; i++) {
		for (int j = box_topstart; j < box_bottomend + 5; j++)
			DrawPixel(i, j, BLUE);
	}

	for (int i = box_leftstart; i < boarder_padding; i++) {
		for (int j = box_topstart; j < box_bottomend + 5; j++)
			DrawPixel(i, j, BLUE);
	}

	for (int i = boarder_padding; i < box_rightend; i++) {
		for (int j = box_topstart; j < boarder_padding; j++) {
			DrawPixel(i, j, BLUE);
		}
	}


	for (int i = boarder_padding; i < box_rightend; i++) {
		for (int j = box_bottomend; j < box_bottomend + frame_thickness; j++) {
			DrawPixel(i, j, BLUE);
		}
	}
}

void Board::DrawGrid()
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			DrawCell({ x,y }, RAYWHITE);
		}
	}
}

bool Board::CheckForObstacles(const Location& loc) const
{
	return hasObstacles[loc.y * width + loc.x];
}

void Board::SpawnObstacle(std::mt19937& rng, const Snake& snek, const Goal& goal)
{
	std::uniform_int_distribution<int> xDist(0, GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, GetGridHeight() - 1);


	Location newloc;
	do {

		newloc.x = xDist(rng);
		newloc.y = yDist(rng);

	} while (snek.IsInTile(newloc) || newloc == goal.GetLocation() || CheckForObstacles(newloc));

	hasObstacles[newloc.y * width + newloc.x] = true;
}

void Board::DrawObstacle()
{
	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {

			if (CheckForObstacles({ x, y })) {
				DrawCell({ x,y }, obstacleColor);
			}
		}
	}





}