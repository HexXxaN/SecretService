#pragma once
#include <vector>
#include "MovableCircularObject.h"


class Agent : public MovableCircularObject
{
public:
	Agent() { m_vel = 6; }
	~Agent() {}

	inline void set_moveUp(bool p_val) { m_moveUp = p_val; }
	inline void set_moveDown(bool p_val) { m_moveDown = p_val; }
	inline void set_moveLeft(bool p_val) { m_moveLeft = p_val; }
	inline void set_moveRight(bool p_val) { m_moveRight = p_val; }
	inline void set_Timer_to_curr_time() { m_Timer.set_to_current_time(); }

	bool can_be_detected() { return m_canBeDetected; }
	virtual void handle_special_ability() = 0;

protected:
	bool m_canBeDetected = true;
};