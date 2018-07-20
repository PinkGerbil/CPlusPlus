#pragma once
#include "Agent.h"
class BehaviorChange; 
class Behavior
{
public:
	virtual void update(Agent* agent, BehaviorChange* bc, float deltaTime) = 0;
	virtual void init(Agent* agent) = 0;
	virtual void exit(Agent* agent) = 0;
};