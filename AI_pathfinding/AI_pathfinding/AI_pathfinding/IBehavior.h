#pragma once
#include "Agent.h"
class IBehavior
{
public:
	virtual void update(Agent* Agent, float deltaTime) = 0;
};

