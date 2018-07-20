#include "FleeState.h"
#include "BehaviorChange.h"
#include "WanderState.h"


FleeState::FleeState()
{
	m_target = nullptr;
}

FleeState::FleeState(Agent * target)
{
	m_target = target; 
}

void FleeState::update(Agent * agent, BehaviorChange * bc, float deltaTime)
{
	Vector2 desiredVel = agent->position - m_target->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector2 force = desiredVel - agent->velocity;
	agent->AddForce(force);

	Vector2 distance = m_target->getPosition() - agent->getPosition();
	float length = distance.magnitude();
	if (length > 600.0f) {
		bc->ChangeState(agent, new WanderState(25.0f, 500.0f, 5.0f, m_target, 1));
	}
}

FleeState::~FleeState()
{
	delete m_target; 
}
