#include "Game.h"
#include <assert.h>


Game::Game(int width, int height, std::string title):
	brd(),
	snek({10,10}),
	rng(std::random_device()())
{

	assert(!GetWindowHandle()); // check if the window is opened
	for (int i = 0; i < nPoison; i++) {
		brd.SpawnContents(rng, snek, 3);
	}
	for (int i = 0; i < nFood; i++) {
		brd.SpawnContents(rng, snek, 2);
	}

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
	const float dt = GetFrameTime(); // Get time in seconds for last frame drawn (delta time)

	if (IsKeyPressed(KEY_ENTER)) {
		isStarted = true;
	}

	if (!GameOver && isStarted) {


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

		float snekModifiedMovePeriod = snekMovePeriod;
		if (IsKeyPressed(KEY_LEFT_CONTROL)) {
			snekModifiedMovePeriod = std::min(snekMovePeriod, snekMovePeriodSpeedUp);
		}
		snekMoveCounter += dt;
		
		if (snekMoveCounter >= snekModifiedMovePeriod) {
			snekMoveCounter -= snekModifiedMovePeriod;
			
			Location next = snek.GetNextHeadLocation(delta_loc);
			const int contents = brd.GetContents(next);
			if (!brd.IsInsideBoard(next) || snek.IsInTileExceptEnd(next) ||
				contents == 1) {
				GameOver = true;
				
				/*if (lives == 0) {
					
				}
				*/
			}
			else if( contents == 2) {
				
				
				snek.Grow();
				snek.MoveBy(delta_loc);
				brd.ConsumeContents(next);
				brd.SpawnContents(rng, snek,2);

				
				goalCounter++;
				if (goalCounter >= 3) {
					goalCounter = 0;
					brd.SpawnContents(rng, snek,1);
				}
					
			}
			else if (contents == 3) {
				snek.MoveBy(delta_loc);
				brd.ConsumeContents(next);
				brd.SpawnContents(rng, snek, 3);
				snekMovePeriod = std::max(snekMovePeriod * snekSpeedUpFactor, snekMovePeriodMin);
			}
			else {
				snek.MoveBy(delta_loc);
			}
		}
		
		snekMovePeriod = std::max(snekMovePeriod - dt * snekSpeedUpFactor, snekMovePeriodMin);
	}
}

void Game::Draw()
{

	ClearBackground({242,242,242,255}); //F2F2F2
	

	if (!isStarted) {
		
		DrawText("Press enter to start your game!", 230,300 , 20,{ 136, 121, 176,255 });
	}
	else {
		brd.DrawFrame();
		brd.DrawGrid();
		snek.Draw(brd);
		brd.DrawCells();

		if (GameOver) {
			DrawText("You loser", 350, 300, 20, { 136, 121, 176,255 });
		}
		// for lives, we need a game pause phase, and reset speed
		// user press enter to enter snek phase again, the obstacle will be destroyed.
		// hit body and wall -> instant death, hit obstacle will cost one life
		// 

	}

	
}
