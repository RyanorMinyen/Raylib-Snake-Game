#include "Snake.h"
#include <assert.h>
#include <cmath>

Snake::Snake(const Location& loc_in)
{
	constexpr int nBodyColors = 4;
	constexpr Color bodyColors[nBodyColors] = {
		{0,10,100,32},
		{0,10,130,48},
		{0,18,160,48},
		{0,10,130,48}
	};

	for (int i = 0; i < nSegmentsMax; i++) {
		segments[i].InitBody(bodyColors[i % nBodyColors]);
	}
	segments[0].InitHead(loc_in);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--) {
		segments[i].Follow(segments[i - 1]);
	}

	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax) {
		nSegments++;
	}
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; i++) {
		segments[i].Draw(brd);
	}
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l = segments[0].GetLocation();

	l.Add(delta_loc);

	return l;
}

void Snake::Segment::InitHead(const Location& loc_in)
{
	loc = loc_in;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(Color c_in)
{
	c = c_in;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);

}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
