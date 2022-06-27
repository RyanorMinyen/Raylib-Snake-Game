#include "Snake.h"
#include <assert.h>
#include <math.h>

snake::snake(const Location& loc)
{

	for (int i = 0; i < nSegmentsMax; ++i) {
		segments[i].InitBody(bodyColor);
	}
	segments[0].InitHead(loc);
}

void snake::Moveby(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i) {
		segments[i].Follow(segments[i - 1]);
	}

	segments[0].Moveby(delta_loc);
}

void snake::Grow()
{
	if (nSegments < nSegmentsMax) {
		++nSegments;
	}
}

void snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; i++) {
		segments[i].Draw(brd);
	}
}

Location snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l(segments[0].getLocation());
	l.Add(delta_loc);
	return l;
}

bool snake::IsInTileExceptEnd(const Location& target) const
{
	for (int i = 0; i < nSegments - 1; i++) {
		if (segments[i].getLocation() == target) {
			return true;
		}
	}

	return false;
}

bool snake::IsInTile(const Location& target) const
{

	for (int i = 0; i < nSegments; i++) {
		if (segments[i].getLocation() == target) {
			return true;
		}
	}

	return false;
}

void snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = snake::headColor;
}

void snake::Segment::InitBody(Color c_in)
{
	c = c_in;

}

void snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void snake::Segment::Draw(Board& brd) const
{
	brd.Drawcell(loc, c);
}

void snake::Segment::Moveby(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

const Location& snake::Segment::getLocation() const
{
	return loc;
}



