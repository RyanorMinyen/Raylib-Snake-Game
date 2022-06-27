
#include "raylib.h"
#include "Board.h"
#include "Snake.h"
//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------


const int screenWidth = 800;
const int screenHeight = 600;

// TODO: Initialize all required variables and load all required data here!

int framesCounter = 0;          // Useful to count frames

Board brd;
snake snek({ 2,2 });
Location delta_loc = { 1,0 };
//--------------------------------------------------------------------------------------
