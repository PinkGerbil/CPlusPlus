#pragma once
#include "IBehavior.h"
#include "State.h"

class StateMachine : public IBehavior
{
public:
	StateMachine();
	virtual void update(Agent* agent, float deltaTime) = 0;
	void ChangeState(Agent* agent, State* state);
	State* GetCurrentState();
	State* GetPrevState();
	~StateMachine();

private:
	State * currentState;
	State * prevState;
};