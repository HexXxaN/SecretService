#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Agent_A.h"


void Agent_A::handle_special_ability() {
	if (m_timer && SDL_GetTicks() - m_timer <= 2000)
		m_vel = 10;
	else 
		m_vel = 6;
}
