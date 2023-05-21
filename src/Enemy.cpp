#pragma once
#include "Enemy.h"
#include <iostream>

//initializing static Point m_playerPos
Point Enemy::m_playerPos;

bool Enemy::detect_player(Point p_playerPos) {
	int deltaX = m_dotCenter.x - p_playerPos.x;
	int deltaY = m_dotCenter.y - p_playerPos.y;
	
	//From the pythagorean theorem
	if (deltaX * deltaX + deltaY * deltaY < m_DetectionRadius * m_DetectionRadius) {
		m_playerPos = p_playerPos;
		std::cout << "Player detected!\n";
		return true;
	}
	else
		return false;
}
