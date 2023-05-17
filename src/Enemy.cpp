#pragma once
#include "Enemy.h"

//initializing static Point m_playerPos
Point Enemy::m_playerPos;

Enemy::Enemy(Point p_originPoint, Point p_destinationPoint) {
	m_originPoint = p_originPoint;
	m_destinationPoint = p_destinationPoint;

	m_dst.x = p_originPoint.x;
	m_dst.y = p_originPoint.y;
	m_lastPoint = { p_originPoint.x, p_originPoint.y };

	//if the player position is set to negative numbers, the player position is unknown to the enemies
	m_playerPos = { -1, -1 };
}

Enemy::~Enemy() {
}

void Enemy::move() {
	if (m_originPointReached)
		move_to_point(m_destinationPoint, m_originPointReached, m_destinationPointReached);
	if (m_destinationPointReached)
		move_to_point(m_originPoint, m_destinationPointReached, m_originPointReached);
}

bool Enemy::detect_player(Point p_playerPos) {
	int deltaX = m_dotCenter.x - p_playerPos.x;
	int deltaY = m_dotCenter.y - p_playerPos.y;
	
	//From the pythagorean theorem
	if (deltaX * deltaX + deltaY * deltaY < m_detectionRadius * m_detectionRadius) {
		m_playerPos = p_playerPos;
		std::cout << "Player detected!\n";
		return true;
	}
	else
		return false;
}

void Enemy::move_to_point(Point p_point, bool &p_prevPoint, bool &p_nextPoint) {
	if (m_dst.x > p_point.x) {
		m_dst.x -= m_agent_vel;
		if (m_dst.x < p_point.x)
			m_dst.x = p_point.x;
	}
	if (m_dst.x < p_point.x) {
		m_dst.x += m_agent_vel;
		if (m_dst.x > p_point.x)
			m_dst.x = p_point.x;
	}
	if (m_dst.y > p_point.y) {
		m_dst.y -= m_agent_vel;
		if (m_dst.y < p_point.y)
			m_dst.y = p_point.y;
	}
	if (m_dst.y < p_point.y) {
		m_dst.y += m_agent_vel;
		if (m_dst.y > p_point.y)
			m_dst.y = p_point.y;
	}

	if (m_dst.x == p_point.x && m_dst.y == p_point.y) {
		p_prevPoint = false;
		p_nextPoint = true;
	}

	m_dotCenter.x = m_dst.x + (0.5 + m_Diameter / 2) + 1;
	m_dotCenter.y = m_dst.y + (0.5 + m_Diameter / 2) + 1;
}
