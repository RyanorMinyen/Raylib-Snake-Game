#include "Game.h"
#include <assert.h>

Game::Game(int width, int height, std::string title):
	brd(),
	snek({10,10}),
	rng(std::random_device()()),
	goal(rng, brd, snek)
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
	const float dt = GetFrameTime();

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

		snekMoveCounter += dt;
		
		if (snekMoveCounter >= snekMovePeriod) {
			snekMoveCounter -= snekMovePeriod;
			
			Location next = snek.GetNextHeadLocation(delta_loc);
			if (!brd.IsInsideBoard(next) || snek.IsInTileExceptEnd(next) ||
				brd.CheckForObstacles(next)) {
				GameOver = true;
			}
			else {
				bool isEating = next == goal.GetLocation();
				if (isEating) {
					snek.Grow();
					//prg.UpdateProgress();
				}
				snek.MoveBy(delta_loc);

				if (isEating) { // respawn after we grow, since we need to check the snek segments
								// goal respawn
					goal.Respawn(rng, brd, snek);
					goalCounter++;
					if (goalCounter >= 3) {
						goalCounter = 0;
						brd.SpawnObstacle(rng, snek, goal);
					}
					
				}
			}
		}
		snekMovePeriod = std::max(snekMovePeriod - dt * snekSpeedUpFactor, snekMovePeriodMin);
	}
}

void Game::Draw()
{

	ClearBackground({242,242,242,255}); //F2F2F2
	

	// brd.DrawCell({ 20,20 }, BLUE);

	if (!isStarted) {
		DrawText("Press enter to start your game!", 230, 300, 20, { 136, 121, 176,255 });
	}
	else {
		brd.DrawFrame();
		brd.DrawGrid();
		goal.Draw(brd);
		snek.Draw(brd);
		brd.DrawObstacle();

		if (GameOver) {
			DrawText("You loser", 350, 300, 20, { 136, 121, 176,255 });
		}
	}

	
}
