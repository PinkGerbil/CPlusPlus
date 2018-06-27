#pragma once
#include "IBehavior.h"
class FleeState : public IBehavior
{
public:
	FleeState();
	FleeState(Agent* target);
	void update(Agent* agent, float deltaTime);
	~FleeState();

private:
	Agent * m_target;
};