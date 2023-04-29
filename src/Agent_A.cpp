#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Agent_A.h"

Agent_A::Agent_A() {
	//Player has higher speed than the enemies
	m_agent_vel = 10;
}

Agent_A::~Agent_A() {

}
