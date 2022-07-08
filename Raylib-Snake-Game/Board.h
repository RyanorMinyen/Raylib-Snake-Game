#pragma once

#include "Location.h"
#include "raylib.h"
#include <random>


class Board {

public:
	Board() = default;
	int GetGridHeight() const;
	int GetGridWidth() const;
	void DrawCell(const Location& loc, Color c) const;
	bool IsInsideBoard(const Location& loc) const;
	void DrawFrame();
	void DrawGrid();
	// forward declaration
	void SpawnContents(std::mt19937& rng, const class Snake& snek, int content);
	void SpawnFood(std::mt19937 rng, const class Snake& snek);
	int GetContents(const Location& loc) const;
	void ConsumeContents(const Location& loc);
	void DrawCells(); // for the poison

private:

	static constexpr int width = 35;
	static constexpr int height = 25;
	static constexpr int dimension = 20;
	static constexpr int boarder_padding = 50;
	static constexpr int frame_thickness = 5;
	static constexpr int cell_padding = 1;
	static constexpr Color obstacleColor = Color{26,77,46,255};
	static constexpr Color foodColor = Color{ 136, 121, 176,255 };
	static constexpr Color poisonColor = Color{ 26,77,46,100 };

	// 0:empty 1:obstacles 2:food 3:poison-speedup
	int contents[width * height] = { 0 };

};