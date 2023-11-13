#pragma once
#include "Agent.h"

/// A class for one of two playable agents.
/// 
///


class Agent_A : public Agent
{
public:
	Agent_A() {}
	~Agent_A() {}

	/// The special ability of Agent_A.
	/// 
	/// This method can be called only once. The agent moves faster for 2 seconds.
	void handle_special_ability() override;
};