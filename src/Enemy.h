#pragma once
#include "MovableCircularObject.h"


class Enemy : public MovableCircularObject
{
public:
	void move();
	bool detect_player(Point p_playerPos);

private:
	const short int m_DetectionRadius = 200;
	Point m_originPoint;
	Point m_destinationPoint;
	Point m_lastPoint;
	static Point m_playerPos;
	bool m_originPointReached = true;
	bool m_destinationPointReached = false;
};