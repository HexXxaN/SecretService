#pragma once
#include <iostream>
#include <random>
#include "Enemy.h"


//initializing static Point m_playerPos
bool Enemy::m_wasPlayerSpotted = false;
Point Enemy::m_playerPos = { -1, -1 };

Enemy::Enemy(Point p_origin) {
	m_dotCenter = p_origin;
	m_originPoint = p_origin;
}

bool Enemy::detect_player(Point p_playerPos) {
	int deltaX = m_dotCenter.x - p_playerPos.x;
	int deltaY = m_dotCenter.y - p_playerPos.y;
	
	//From the pythagorean theorem
	if (deltaX * deltaX + deltaY * deltaY < m_DetectionRadius * m_DetectionRadius)
		return true;
	else
		return false;
}

void Enemy::generate_movementTime() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(100, 500);

	m_movementTime = dist(gen);

	m_Timer.set_to_current_time();
}

void Enemy::move(Point p_point) {

	if (p_point.x - m_dotCenter.x > (int)m_vel) {
		m_moveLeft = false;
		m_moveRight = true;
	}
	else if (p_point.x - m_dotCenter.x <= (int)m_vel && p_point.x - m_dotCenter.x >= (int)-m_vel) {
		m_moveLeft = false;
		m_moveRight = false;
		m_dotCenter.x = p_point.x;
	}
	else if (p_point.x - m_dotCenter.x < (int)-m_vel) {
		m_moveLeft = true;
		m_moveRight = false;
	}

	if (p_point.y - m_dotCenter.y > (int)m_vel) {
		m_moveUp = false;
		m_moveDown = true;
	}
	else if (p_point.y - m_dotCenter.y <= (int)m_vel && p_point.y - m_dotCenter.y >= (int)-m_vel) {
		m_moveUp = false;
		m_moveDown = false;
		m_dotCenter.y = p_point.y;
	}
	else if (p_point.y - m_dotCenter.y < (int)-m_vel) {
		m_moveUp = true;
		m_moveDown = false;
	}

	MovableCircularObject::move();
}

void Enemy::generate_movement_direction() {
	m_moveUp = false;
	m_moveDown = false;
	m_moveLeft = false;
	m_moveRight = false;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 4);

	short int direction = dist(gen);
	
	switch (direction) {
	case 1:
		m_moveUp = true;
		break;
	case 2:
		m_moveDown = true;
		break;
	case 3:
		m_moveLeft = true;
		break;
	case 4:
		m_moveRight = true;
		break;
	}
}