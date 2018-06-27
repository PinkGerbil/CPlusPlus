#include "SeekBehaviour.h"

SeekBehaviour::SeekBehaviour()
{
	m_target = nullptr;
}

SeekBehaviour::SeekBehaviour(Agent* target)
{
	m_target = target; 
}

void SeekBehaviour::update(Agent* agent, float deltaTime)
{
	Vector2 desiredVel = m_target->position - agent->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector2 force = desiredVel - agent->velocity; 
	agent->AddForce(force);
}

SeekBehaviour::~SeekBehaviour()
{
	delete m_target;
}