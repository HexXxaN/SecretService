#pragma once
#include "Agent_B.h"


void Agent_B::handle_special_ability() {
	if (m_Timer.get_start() && m_Timer.get_current_time() - m_Timer.get_start() <= 2000)
		m_canBeDetected = false;
	else
		m_canBeDetected = true;
}