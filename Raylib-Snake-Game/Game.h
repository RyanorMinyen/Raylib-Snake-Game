#pragma once

#include "raylib.h"
#include <string>
#include "Board.h"
#include "Snake.h"
#include "Goal.h"



class Game {

public:
	Game(int width, int height, std::string title);
	~Game() noexcept; // destructor
	Game(const Game& other) = delete; // copy constructor
	Game& operator=(const Game& other) = delete; //copy assignment
	
	// since we deleted copy constructor and copy assignment
	// move semantics would not be declared by the compiler
	// so we don't need to explicitly delete them
	// -------Game(const Game&& other) = delete; // move constructor
	// -------Game& operator=(const Game&& other) = delete; // move assignment
	
	bool GameShouldClose() const;
	void Tick(); // equivalent to Game::Go();

private:
	void Update();
	void Draw();

private:

	Board brd;
	Snake snek;
	Location delta_loc = { 1,0 };
	bool GameOver = false;
	bool isStarted = false;
	std::mt19937 rng;
	Goal goal;
	float snekMovePeriod = 0.4f;
	static constexpr float snekMovePeriodMin = 0.06f;
	static constexpr float snekSpeedUpFactor = 0.05f;
	float snekMoveCounter = 0.0f;
	const int obstacleSpawnPeiord = 3; // spawn one every 3 goals
	int goalCounter = 0;

};
