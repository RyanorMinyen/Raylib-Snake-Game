#pragma once

#include "Location.h"
#include "raylib.h"

class Board {

public:
	Board() = default;
	int GetGridHeight() const;
	int GetGridWidth() const;
	void DrawCell(const Location& loc, Color c) const;
	bool IsInsideBoard(const Location& loc) const;
private:

	static constexpr int width = 35;
	static constexpr int height = 25;
	static constexpr int dimension = 20;

};