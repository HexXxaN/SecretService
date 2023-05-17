#pragma once
#include "Agent.h"


class Enemy : public Agent
{
public:
	Enemy(Point p_originPoint, Point p_destinationPoint);
	~Enemy();
	void move();
	void set_player_pos(Point p_playerPos);
	bool detect_player(Point p_playerPos);

private:
	void move_to_point(Point p_point, bool &p_prevPoint, bool &p_nextPoint);

private:
	const short int m_detectionRadius = 200;
	Point m_originPoint;
	Point m_destinationPoint;
	Point m_lastPoint;
	static Point m_playerPos;
	bool m_originPointReached = true;
	bool m_destinationPointReached = false;
};