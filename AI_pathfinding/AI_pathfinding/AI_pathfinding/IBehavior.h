#pragma once
#include "Agent.h"
class Agent;
class IBehavior
{
public:
	virtual void update(Agent* Agent, float deltaTime) = 0;
};

