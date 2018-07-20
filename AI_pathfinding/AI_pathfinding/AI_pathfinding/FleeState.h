#pragma once
#include "Behavior.h"
class FleeState : public Behavior
{
public:
	FleeState();
	FleeState(Agent* target);
	virtual void update(Agent* agent, BehaviorChange* bc, float deltaTime);
	virtual void init(Agent* agent) {}
	virtual void exit(Agent* agent) {}
	~FleeState();

private:
	Agent * m_target;
};