#include "Game.h"
#include <assert.h>

Game::Game(int width, int height, std::string title)
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
}

void Game::Draw()
{
	ClearBackground(RAYWHITE);
	brd.DrawCell({ 20,20 }, BLUE);
	
}
