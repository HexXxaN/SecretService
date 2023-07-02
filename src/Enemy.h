#pragma once
#include <random>
#include "MovableCircularObject.h"


class Enemy : public MovableCircularObject
{
public:
	Enemy(unsigned short int p_x, unsigned short int p_y);

	unsigned short int get_movementTime() { return m_movementTime; }

	bool detect_player(Point p_playerPos);
	void generate_movementTime();
	void move();

private:
	void generate_movement_direction();

private:
	const short int m_DetectionRadius = 200;
	unsigned short int m_movementTime = 0;
	static Point m_playerPos;
};