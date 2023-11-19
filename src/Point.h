#pragma once


/// A struct responsible for storing 2 dimentional coordinates.
/// 
///

struct Point {
	int x, y;
};

/// This operator checks if coordinates of both points are the same.
/// 
///
/// <param name="p_point1"> The first Point. </param>
/// <param name="p_point2"> The second Point. </param>
/// <returns> True when the points have the same coordinates and false when they do not. </returns>
inline bool operator==(const Point& p_point1, const Point& p_point2) {
	return p_point1.x == p_point2.x && p_point1.y == p_point2.y;
}