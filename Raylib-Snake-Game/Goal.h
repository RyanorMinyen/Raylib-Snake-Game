#pragma once
#include "Snake.h"
#include <random>

class Goal {

public:

	Goal(std::mt19937& rng, const Board& brd, const Snake& snek);
	void Respawn(std::mt19937& rng, const Board& brd, const Snake& snek);
	void Draw(Board& brd);
	const Location& GetLocation() const;
	// void UpdateColor();

private:

	Location loc;
	Color c = { 136, 121, 176,255 };
	//bool colorIncreasing = true;

};