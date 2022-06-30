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
	bool CheckForObstacles(const Location& loc) const;
	// forward declaration
	void SpawnObstacle(std::mt19937& rng, const class Snake& snek, const class Goal& goal);
	void DrawObstacle();
private:

	static constexpr int width = 35;
	static constexpr int height = 25;
	static constexpr int dimension = 20;
	static constexpr int boarder_padding = 50;
	static constexpr int frame_thickness = 5;
	static constexpr int cell_padding = 1;
	static constexpr Color obstacleColor = Color{26,77,46,255};
	bool hasObstacles[width * height] = { false };

};