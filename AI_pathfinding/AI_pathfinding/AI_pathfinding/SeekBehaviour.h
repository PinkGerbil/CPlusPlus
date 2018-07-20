#pragma once
#include "Behavior.h"

class SeekBehaviour : public Behavior
{
public:
	SeekBehaviour();
	SeekBehaviour(Agent* target);
	virtual void update(Agent* agent, BehaviorChange* bc, float deltaTime);
	virtual void init(Agent* agent) {}
	virtual void exit(Agent* agent) {}
	~SeekBehaviour();

private:
	Agent* m_target; 
	float distanceX;
	float distanceY; 
};

