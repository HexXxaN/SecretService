#pragma once
#include "Agent.h"


class Agent_A : public Agent
{
public:
	Agent_A() {}
	~Agent_A() {}

	void handle_special_ability() override;
};