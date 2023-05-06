#pragma once
#include "Enemy.h"


Enemy::Enemy(m_Point p_originPoint, m_Point p_destinationPoint) {
	m_originPoint = p_originPoint;
	m_destinationPoint = p_destinationPoint;

	m_dst.x = p_originPoint.x;
	m_dst.y = p_originPoint.y;
	m_lastPoint = { p_originPoint.x, p_originPoint.y };
}

Enemy::~Enemy() {

}

void Enemy::move() {
	if (m_originPointReached)
		move_to_point(m_destinationPoint, m_originPointReached, m_destinationPointReached);
	if (m_destinationPointReached)
		move_to_point(m_originPoint, m_destinationPointReached, m_originPointReached);
}

void Enemy::move_to_point(m_Point p_point, bool &p_prevPoint, bool &p_nextPoint) {
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

}
