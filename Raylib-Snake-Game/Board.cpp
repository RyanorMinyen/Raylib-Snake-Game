#include "Board.h"
#include <assert.h>
#include "Snake.h"


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
			DrawPixel(i, j, { 55, 125, 113, 255 }); //#377D71
	}

	for (int i = box_leftstart; i < boarder_padding; i++) {
		for (int j = box_topstart; j < box_bottomend + 5; j++)
			DrawPixel(i, j, { 55, 125, 113, 255 }); //#377D71
	}

	for (int i = boarder_padding; i < box_rightend; i++) {
		for (int j = box_topstart; j < boarder_padding; j++) {
			DrawPixel(i, j, { 55, 125, 113, 255 });//#377D71
		}
	}


	for (int i = boarder_padding; i < box_rightend; i++) {
		for (int j = box_bottomend; j < box_bottomend + frame_thickness; j++) {
			DrawPixel(i, j, { 55, 125, 113, 255 });//#377D71
		}
	}
}

void Board::DrawGrid()
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			DrawCell({ x,y }, { 55, 125, 113, 20 }); //#377D71 with 50 alpha
		}
	}
}

int Board::GetContents(const Location& loc) const
{
	return contents[loc.y * width + loc.x];
}

void Board::ConsumeContents(const Location& loc)
{
	assert(GetContents(loc) == 2 || GetContents(loc) == 3);
	contents[loc.y * width + loc.x] = 0; // cell is empty after eating

}

void Board::SpawnContents(std::mt19937& rng, const Snake& snek, int content)
{
	std::uniform_int_distribution<int> xDist(0, GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, GetGridHeight() - 1);


	Location newloc;
	do {

		newloc.x = xDist(rng);
		newloc.y = yDist(rng);

	} while (snek.IsInTile(newloc) || GetContents(newloc) != 0);

	contents[newloc.y * width + newloc.x] = content;
}



void Board::DrawCells()
{
	for (int y = 0; y < height; y++) {

		for (int x = 0; x < width; x++) {

			const int contents = GetContents({ x,y });
			if (contents == 1) {
				DrawCell({ x,y }, obstacleColor);
			}
			else if (contents == 2) {
				DrawCell({ x,y }, foodColor);
			}
			else if (contents == 3) {
				DrawCell({ x,y }, poisonColor);
			}
		}
	}





}