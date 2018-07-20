#pragma once
#include "IBehavior.h"
#include "Behavior.h"

class BehaviorChange : public IBehavior
{
public:
	BehaviorChange();
	BehaviorChange(Behavior* newBehavior);
	virtual void update(Agent* agent, float deltaTime);
	void ChangeState(Agent* agent, Behavior* state);
	Behavior* GetCurrentState();
	Behavior* GetPrevState();
	~BehaviorChange();
private:
	Behavior * currentState;
	Behavior * prevState;
};