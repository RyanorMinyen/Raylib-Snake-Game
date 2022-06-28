#include "Board.h"
#include <assert.h>

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
