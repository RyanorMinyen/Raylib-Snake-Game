#pragma once

#include "Location.h"
#include "raylib.h"



class Board {
public:
	Board();
	void Drawcell(const Location& loc, Color c);
	int getWidth() const;
	int getHeight() const;
	bool isInsideBoard(const Location& loc);
	void DrawFrame();

private:
	static constexpr int dimension = 20;
	static constexpr int width = 35;
	static constexpr int height = 25;
	static constexpr int boarder_padding = 50; // make the grid in the center of the screen
	static constexpr int cell_padding = 1;
	static constexpr int frame_thickness = 5;


	
};