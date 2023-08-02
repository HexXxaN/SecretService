#pragma once

struct Point {
	int x, y;
};

inline bool operator== (const Point& p_point1, const Point& p_point2) {
	return p_point1.x == p_point2.x && p_point1.y == p_point2.y;
}