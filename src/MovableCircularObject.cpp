#pragma once
#include "MovableCircularObject.h"
#include "Macros.h"

void MovableCircularObject::move() {
	
	if (m_moveLeft)
		m_dotCenter.x -= m_vel;
	if (m_moveRight)
		m_dotCenter.x += m_vel;

	// Adjust the entity position near left and right edge of the map
	if (m_dotCenter.x < m_radius)
		m_dotCenter.x = m_radius;
	if (m_dotCenter.x > LEVEL_WIDTH * 64 - m_radius)
		m_dotCenter.x = LEVEL_WIDTH * 64 - m_radius;

	if (m_moveUp)
		m_dotCenter.y -= m_vel;
	if (m_moveDown)
		m_dotCenter.y += m_vel;

	// Adjust the entity position near top and bottom edge of the map
	if (m_dotCenter.y < m_radius)
		m_dotCenter.y = m_radius;
	if (m_dotCenter.y > LEVEL_HEIGHT * 64 - m_radius)
		m_dotCenter.y = LEVEL_HEIGHT * 64 - m_radius;

}