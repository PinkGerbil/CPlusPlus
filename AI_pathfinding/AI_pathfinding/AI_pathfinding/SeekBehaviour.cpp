#include "SeekBehaviour.h"
#include "BehaviorChange.h"
#include "WanderState.h"
SeekBehaviour::SeekBehaviour()
{
	m_target = nullptr;
	distanceX = 0.0f; 
	distanceY = 0.0f; 
}

SeekBehaviour::SeekBehaviour(Agent* target)
{
	m_target = target; 
}

void SeekBehaviour::update(Agent * agent, BehaviorChange * bc, float deltaTime)
{
	Vector2 desiredVel = m_target->position - agent->position;
	desiredVel.normalise();
	desiredVel = desiredVel * 100.0f;
	Vector2 force = desiredVel - agent->velocity;
	agent->AddForce(force);
	
	Vector2 distance = m_target->getPosition() - agent->getPosition();
	float length = distance.magnitude();
	if (length > 600.0f) {
		bc->ChangeState(agent, new WanderState(25.0f, 500.0f, 5.0f, m_target, 0));
	}

}


SeekBehaviour::~SeekBehaviour()
{
	delete m_target;
}