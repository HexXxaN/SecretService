#pragma once
#include <iostream>
#include <random>
#include "Enemy.h"

//initializing static Point m_playerPos
Point Enemy::m_playerPos = { -1, -1 };
Timer Enemy::m_detectionTimer;


Enemy::Enemy(unsigned short int p_x, unsigned short int p_y) {
	m_dotCenter.x = p_x;
	m_dotCenter.y = p_y;
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
	generate_movement_direction();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(100, 500);

	m_movementTime = dist(gen);

	this->m_Timer.set_to_current_time();
}

void Enemy::move() {
	if (m_moveUp)
		m_dotCenter.y += m_vel;
	if (m_moveDown)
		m_dotCenter.y -= m_vel;
	if (m_moveLeft)
		m_dotCenter.x -= m_vel;
	if (m_moveRight)
		m_dotCenter.x += m_vel;
}

void Enemy::move(Point m_point) {

	if (m_point.x - m_dotCenter.x > (int)m_vel) {
		m_moveLeft = false;
		m_moveRight = true;
	}
	else if (m_point.x - m_dotCenter.x <= (int)m_vel && m_point.x - m_dotCenter.x >= (int)-m_vel) {
		m_moveLeft = false;
		m_moveRight = false;
		m_dotCenter.x = m_point.x;
	}
	else if (m_point.x - m_dotCenter.x < (int)-m_vel) {
		m_moveLeft = true;
		m_moveRight = false;
	}

	if (m_point.y - m_dotCenter.y > (int)m_vel) {
		m_moveUp = true;
		m_moveDown = false;
	}
	else if (m_point.y - m_dotCenter.y <= (int)m_vel && m_point.y - m_dotCenter.y >= (int)-m_vel) {
		m_moveUp = false;
		m_moveDown = false;
		m_dotCenter.y = m_point.y;
	}
	else if (m_point.y - m_dotCenter.y < (int)-m_vel) {
		m_moveUp = false;
		m_moveDown = true;
	}

	this->move();
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
