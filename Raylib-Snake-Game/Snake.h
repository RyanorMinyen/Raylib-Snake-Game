#pragma once
#include "Location.h"
#include "Board.h"

class Snake {
private:
	class Segment {

	public:
		void InitHead(const Location& loc_in);
		void InitBody(Color c_in);
		void Follow(const Segment& next);
		void Draw(Board& brd) const;
		void MoveBy(const Location& delta_loc);
		const Location& GetLocation() const;

	private:
		Location loc;
		Color c;
	};

public:
	Snake(const Location& loc_in);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd) const;
	Location GetNextHeadLocation(const Location& delta_loc) const;
	bool IsInTileExceptEnd(const Location& target) const;
	bool IsInTile(const Location& target) const;


private:
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;

	static constexpr Color headColor = { 136, 121, 176,255 };



};