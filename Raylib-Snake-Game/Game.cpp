#include "Game.h"
#include <assert.h>

Game::Game(int width, int height, std::string title):
	brd(),
	snek({10,10})
{
	assert(!GetWindowHandle()); // check if the window is opened
	InitWindow(width, height, title.c_str());
	
}

Game::~Game() noexcept
{
	assert(GetWindowHandle()); // check if the window is closed
	CloseWindow();
}

bool Game::GameShouldClose() const
{
	return WindowShouldClose();
}

void Game::Tick()
{
	BeginDrawing();
	Update();
	Draw();
	EndDrawing();
}

void Game::Update()
{

	if (IsKeyPressed(KEY_RIGHT)) {
		delta_loc = { 1,0 };
	}
	else if (IsKeyPressed(KEY_LEFT)) {
		delta_loc = { -1,0 };
	}
	else if (IsKeyPressed(KEY_UP)) {
		delta_loc = { 0,-1 };
	}
	else if (IsKeyPressed(KEY_DOWN)) {
		delta_loc = { 0,1 };
	}

	if (IsKeyPressed(KEY_Z)) {
		snek.Grow();
	}

	snek.MoveBy(delta_loc);
}

void Game::Draw()
{
	ClearBackground(RAYWHITE);
	// brd.DrawCell({ 20,20 }, BLUE);
	brd.DrawFrame();
	snek.Draw(brd);
	
}
