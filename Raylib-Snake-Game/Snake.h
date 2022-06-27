#pragma once
#include "Board.h"

class snake {
public:

	snake(const Location& loc);
	void Moveby(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd) const;
	Location GetNextHeadLocation(const Location& delta_loc) const;
	bool IsInTileExceptEnd(const Location& target) const;
	bool IsInTile(const Location& target) const;


private: // for nested class
	class Segment {

	public:
		void InitHead(const Location& in_loc);
		void InitBody(Color in_c);
		void Follow(const Segment& next);
		void Draw(Board& brd) const;
		void Moveby(const Location& delta_loc);
		const Location& getLocation() const;


	private:
		Location loc;
		Color c;
	};

private: // for member variables

	static constexpr Color headColor = RED;
	static constexpr Color bodyColor = DARKGREEN;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1; // at the start of the game

};