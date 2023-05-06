#pragma once
#include "Agent.h"


class Enemy : public Agent
{
private:
	struct m_Point {
		short int x, y;
	};

public:
	Enemy(m_Point p_originPoint, m_Point p_destinationPoint);
	~Enemy();
	void move();

private:
	void move_to_point(m_Point p_point, bool &p_prevPoint, bool &p_nextPoint);

private:
	m_Point m_originPoint;
	m_Point m_destinationPoint;
	m_Point m_lastPoint;
	static m_Point m_playerPos;
	bool m_originPointReached = true;
	bool m_destinationPointReached = false;
};