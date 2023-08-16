#pragma once
#include "Agent_A.h"


void Agent_A::handle_special_ability() {
	if (m_Timer.get_start() && m_Timer.get_current_time() - m_Timer.get_start() <= 2000)
		m_vel = 10;
	else 
		m_vel = 6;
}
