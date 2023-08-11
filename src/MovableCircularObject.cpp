#pragma once
#include "MovableCircularObject.h"

void MovableCircularObject::move() {
	if (m_moveUp)
		m_dotCenter.y -= m_vel;
	if (m_moveDown)
		m_dotCenter.y += m_vel;
	if (m_moveLeft)
		m_dotCenter.x -= m_vel;
	if (m_moveRight)
		m_dotCenter.x += m_vel;
}