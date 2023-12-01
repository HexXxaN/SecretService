#pragma once
#include "Camera.h"
#include "Agent.h"


void Camera::handle_camera(Agent* p_player, unsigned int p_levelWidth, unsigned int p_levelHeight) {
	//Focus the camera on the player
	m_cameraRect.x = p_player->get_dotCenter().x - m_cameraRect.w / 2;
	m_cameraRect.y = p_player->get_dotCenter().y - m_cameraRect.h / 2;

	//Adjust the camera near the edges of the level
	if (m_cameraRect.x < 0)
		m_cameraRect.x = 0;
	if (m_cameraRect.x + m_cameraRect.w > p_levelWidth)
		m_cameraRect.x = p_levelWidth - m_cameraRect.w;
	if (m_cameraRect.y < 0)
		m_cameraRect.y = 0;
	if (m_cameraRect.y + m_cameraRect.h > p_levelHeight)
		m_cameraRect.y = p_levelHeight - m_cameraRect.h;
}
