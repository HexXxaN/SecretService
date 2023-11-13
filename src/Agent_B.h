#pragma once
#include "Agent.h"

/// A class for one of two playable agents.
/// 
///


class Agent_B : public Agent
{
public:
	Agent_B() {}
	~Agent_B() {}

	/// The special ability of Agent_B.
	/// 
	/// This method can be called only once. Upon using the agent cannot be detectes for 2 second by the enemies.
	void handle_special_ability() override;

	/// The method that checks if the Agent_B can be detected or not.
	/// 
	///
	/// <returns> True when the special ability is not activated and false when it is. </returns>
	bool can_be_detected() override { return m_canBeDetected; }
	
private:
	bool m_canBeDetected = true;
};