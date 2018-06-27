#include "FleeState.h"



FleeState::FleeState()
{
	m_target = nullptr;
}

FleeState::FleeState(Agent * target)
{
	m_target = target; 
}


void FleeState::update(Agent * agent, float deltaTime)
{
	Vector2 desiredVel = agent->position - m_target->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector2 force = desiredVel - agent->velocity;
	agent->AddForce(force);
}

FleeState::~FleeState()
{
	delete m_target; 
}
