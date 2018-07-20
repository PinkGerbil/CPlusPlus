#pragma once
#include "Behavior.h"

class WanderState : public Behavior
{
public:
	WanderState();
	WanderState(float wanderDistance, float wanderRadius, float jitterAmount, Agent* target, int tag);
	virtual void update(Agent* agent, BehaviorChange* bc, float deltaTime);
	virtual void init(Agent* agent) {}
	virtual void exit(Agent* agent) {}
	~WanderState();
	float m_wanDistance;
	float m_wanRadius;
	float m_jitterAmount;

	Vector2 randomVec;
protected:
	Agent * m_target; 
	float timerWan;
	int Tag; 
};