#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Agent_A.h"


void Agent_A::handle_special_ability() {
	if (m_timer && SDL_GetTicks() - m_timer <= 2000)
		m_agent_vel = 10;
	else 
		m_agent_vel = 6;

	if (m_vel_x > 0)
		m_vel_x = m_agent_vel;
	if (m_vel_x < 0)
		m_vel_x = -m_agent_vel;
	if (m_vel_y > 0)
		m_vel_y = m_agent_vel;
	if (m_vel_y < 0)
		m_vel_y = -m_agent_vel;
}
