#include "Board.h"

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
	DrawRectangle(loc.x, loc.y, dimension, dimension, c);
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width&&
		loc.y >= 0 && loc.y < height;
}
