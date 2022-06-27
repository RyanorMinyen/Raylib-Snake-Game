#pragma once


class Location {
public:

	void Add(const Location& delta_loc);
	bool operator==(const Location& r_loc) const;
	int x;
	int y;

};