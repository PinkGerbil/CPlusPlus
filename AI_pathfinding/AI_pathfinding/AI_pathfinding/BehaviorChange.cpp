#include "BehaviorChange.h"



BehaviorChange::BehaviorChange()
{
	currentState = nullptr;
	prevState = nullptr;
}

BehaviorChange::BehaviorChange(Behavior * newBehavior)
{
	currentState = newBehavior;
	prevState = nullptr;
}

void BehaviorChange::update(Agent * agent, float deltaTime)
{
	currentState->update(agent, this, deltaTime);
}

void BehaviorChange::ChangeState(Agent * agent, Behavior * state)
{
	prevState = currentState;
	currentState = state;
}

Behavior * BehaviorChange::GetCurrentState()
{
	return nullptr;
}

Behavior * BehaviorChange::GetPrevState()
{
	return nullptr;
}


BehaviorChange::~BehaviorChange()
{
}
