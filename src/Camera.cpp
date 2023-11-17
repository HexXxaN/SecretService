#pragma once
#include "Camera.h"
#include "Agent.h"


void Camera::handle_camera(Agent* p_player, unsigned int p_levelWidth, unsigned int p_levelHeight) {
	//Focus the camera on the player
	m_camera.x = p_player->get_dotCenter().x - m_camera.w / 2;
	m_camera.y = p_player->get_dotCenter().y - m_camera.h / 2;

	//Adjust the camera near the edges of the level
	if (m_camera.x < 0)
		m_camera.x = 0;
	if (m_camera.x + m_camera.w > p_levelWidth)
		m_camera.x = p_levelWidth - m_camera.w;
	if (m_camera.y < 0)
		m_camera.y = 0;
	if (m_camera.y + m_camera.h > p_levelHeight)
		m_camera.y = p_levelHeight - m_camera.h;
}
