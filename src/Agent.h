#pragma once
#include <vector>
#include "MovableCircularObject.h"

///	A basic class for Agent_A and agent_B classes.
/// 
/// This is a virtual class that allows polymorphism for Agent_A and Agent_B classes.


class Agent : public MovableCircularObject
{
public:
	Agent() { m_vel = 6; }
	virtual ~Agent() {}

	inline void set_moveUp(bool p_val) { m_moveUp = p_val; }
	inline void set_moveDown(bool p_val) { m_moveDown = p_val; }
	inline void set_moveLeft(bool p_val) { m_moveLeft = p_val; }
	inline void set_moveRight(bool p_val) { m_moveRight = p_val; }
	inline void set_Timer_to_curr_time() { m_Timer.set_to_current_time(); }

	/// A method that checks if the agent can be detected or not.
	/// 
	/// <returns> This method always returns true for Agent_A, and for Agent_B returns true if the special ability is not activated and false when it is. </returns>
	virtual bool can_be_detected() { return true; }

	/// A virtual method that's responsible for handling Agent_A and Agent_B's special abilities. 
	/// 
	/// For Agent_A it increases the speed for 2 seconds, and for Agent_B makes it undetectable for enemies for 2 seconds.
	virtual void handle_special_ability() = 0;
};