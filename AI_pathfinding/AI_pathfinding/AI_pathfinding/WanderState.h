#pragma once
#include "IBehavior.h"

class WanderState : public IBehavior
{
public:
	WanderState();
	WanderState(float wanderDistance, float wanderRadius, float jitterAmount);
	void update(Agent * agent, float deltaTime); 
	~WanderState();

	float m_wanDistance;
	float m_wanRadius;
	float m_jitterAmount;

	Vector2 randomVec;
protected:
};