#include "WanderState.h"
#include <glm\ext.hpp>
#include <random>
#include <time.h>
#include "BehaviorChange.h"
#include "SeekBehaviour.h"
#include "FleeState.h"

WanderState::WanderState()
{
}

WanderState::WanderState(float wanderDistance, float wanderRadius, float jitterAmount, Agent* target, int tag)
{
	m_target = target; 
	Tag = tag; 
	m_wanDistance = wanderDistance;
	m_wanRadius = wanderRadius;
	m_jitterAmount = jitterAmount;
	srand(time(nullptr));
	randomVec = Vector2(rand() % (int)m_jitterAmount, rand() % (int)m_jitterAmount);

}

void WanderState::update(Agent * agent, BehaviorChange * bc, float deltaTime)
{
	glm::vec2 circle = glm::circularRand(m_wanRadius);

	Vector2 newTarget = Vector2(randomVec.m_x + circle.x, randomVec.m_y + circle.y);
	newTarget.normalise();
	Vector2 targetOnSphere = newTarget * m_wanRadius;

	targetOnSphere.normalise();
	Vector2 force = targetOnSphere;

	force = force * 80.0f;
	agent->AddForce(force);

	Vector2 distance = m_target->getPosition() - agent->getPosition();
	float length = distance.magnitude();
	if (length < 200.0f) {
		if (Tag == 0) {
			bc->ChangeState(agent, new SeekBehaviour(m_target));
		}
		else {
			bc->ChangeState(agent, new FleeState(m_target));
		}
	}
}

WanderState::~WanderState()
{
}