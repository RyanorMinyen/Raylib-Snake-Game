#pragma once

#include "raylib.h"
#include <string>
#include "Board.h"
#include "Snake.h"



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
};
