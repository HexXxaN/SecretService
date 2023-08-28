#pragma once
#include "Agent.h"


class Agent_B : public Agent
{
public:
	Agent_B() {}
	~Agent_B() {}

	void handle_special_ability() override;
};