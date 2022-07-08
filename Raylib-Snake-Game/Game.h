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


	// 1 Second = 1000 Milliseconds
	// target60FPS = 16.67 milliseconds per frame
	float snekMovePeriod = 0.35f; // start off 0.3 second = 300 Milliseconds per move, 18 frames per move
	static constexpr float snekMovePeriodMin = 0.07f; //0.07 seconds = 70 Milliseconds per move
	static constexpr float snekSpeedUpFactor = 0.9f;
	static constexpr int nPoison = 240;
	static constexpr int nFood = 8;
	static constexpr float snekMovePeriodSpeedUp = 0.15f;
	float snekMoveCounter = 0.0f;
	const int obstacleSpawnPeiord = 3; // spawn one every 3 goals
	int goalCounter = 0;
	int lives = 3;

};
